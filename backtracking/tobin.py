
from collections import defaultdict

n, k = input().split()
n, k = int(n), int(k)

cnt = defaultdict(int)

s = ""
nums = ["1", "0"]

def bin(x):
  global s, n, k
  if x >= n:
    if cnt["1"] == k:
      print(s)
    return
  for num in nums:
    s += num
    cnt[num] += 1
    bin(x+1)
    cnt[num] -= 1
    s = s[:-1]

bin(0)