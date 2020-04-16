from collections import defaultdict

n = int(input())
data = input().split()
for i in range(n):
  data[i] = int(data[i])

def check(size):
  cnt = defaultdict(int)
  dups = set()

  for i in range(size):
    cnt[data[i]] += 1
    if cnt[data[i]] > 1:
      dups.add(data[i])

  if len(dups) == 0:
    return True

  for i in range(size, n):
    cnt[data[i-size]] -= 1
    if data[i-size] in dups and cnt[data[i-size]] <= 1:
      dups.remove(data[i-size])

    cnt[data[i]] += 1
    if cnt[data[i]] > 1:
      dups.add(data[i])

    if len(dups) == 0:
      return True

p = 1
q = n
if check(n):
  print(n)
else:
  # 7 1 4 2 5 3 6
  # p     m     q
  #       p m   q
  #         p m q
  #           pm q - stop
  while p+1 < q:
    mid = int((p+q)/2)
    if check(mid):
      p = mid
    else:
      q = mid
  print(p)