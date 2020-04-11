import tensorflow as tf
import numpy as np
import gym
import collections
import copy

model = tf.keras.Sequential([
    tf.keras.layers.Input((4,)),
    tf.keras.layers.Dense(32, activation='relu'),
    tf.keras.layers.Dense(2, activation='softmax')])
model.build()
optimizer = tf.keras.optimizers.Adam(learning_rate=0.01)
compute_loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True)

Transition = collections.namedtuple("Transition", ["step", "state", "action", "reward", "next_state", "done"])

env = gym.make('CartPole-v0')
episodes = 20000
discount_factor = 0.8

for i_episode in range(episodes):
    s = env.reset()
    episode = []
    total_reward = 0
    step = 0
    done = False
    while not done:
        s = tf.reshape(s, (1,4))
        logits = model(s)
        a_dist = logits.numpy()
        a = np.random.choice(np.arange(len(a_dist[0])), p=a_dist[0])
        n_s, r, done, _ = env.step(a)
        step += 1
        state = tf.squeeze(s)
        episode.append(Transition( step=step,
                                   state=state, action=a, reward=r, next_state=n_s, done=done))
        s = copy.deepcopy(n_s)
        total_reward += r
    if i_episode % 100 == 0:
        print(f"episode: {i_episode} reward: {total_reward}")

    for t, transition in enumerate(episode):
        total_return = sum(discount_factor**i * t.reward for i, t in enumerate(episode[t:]))
        with tf.GradientTape() as tape:
            state = tf.reshape(transition.state, (1,4))
            logits = model(state, training=True)
            loss = compute_loss(transition.action, logits, sample_weight=tf.stop_gradient(total_return))
        grads = tape.gradient(loss, model.trainable_variables)
        optimizer.apply_gradients(zip(grads, model.trainable_variables))