import gym
import haiku as hk
from jax.experimental.optimizers import adam
import jax
import jax.numpy as jnp

# import torch
# import torch.nn as nn
# import torch.nn.functional as F
# import torch.optim as optim
# from torch.distributions import Categorical

# hparam
learning_rate = 0.0002
gamma = 0.98


class Policy(hk.Module):
    def __init__(self):
        super(Policy, self).__init__()
        self.data = []

        self.net = hk.Sequential(
                [hk.Flatten(),
                 hk.Linear(128), jax.nn.relu,
                 hk.Linear(2), jax.nn.softmax])
        self.optimizer = adam(learning_rate, b1=0.9, b2=0.999, eps=1e-8)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.softmax(self.fc2(x), dim=0)
        return x

    def put_data(self, item):
        self.data.append(item)

    def train_net(self):
        R = 0
        self.optimizer.zero_grad()
        for r, prob in self.data[::-1]:
            R = r + gamma * R
            loss = -torch.log(prob) * R
            loss.backward()
        self.optimizer.step()
        self.data = []


def main():
    env = gym.make('CartPole-v1')
    pi = Policy()
    score = 0.0
    print_interval = 20

    for n_epi in range(10000):
        s = env.reset()
        done = False

        while not done:
            prob = pi(torch.from_numpy(s).float())
            m = Categorical(prob)
            a = m.sample()
            s_prime, r, done, info = env.step(a.item())
            pi.put_data((r, prob[a]))
            s = s_prime
            score += r

        pi.train_net()

        if n_epi % print_interval == 0 and n_epi != 0:
            print("# of episode: {}, avg score: {}".format(n_epi, score/print_interval))
            score = 0.0

    env.close()


if __name__ == "__main__":
    main()
