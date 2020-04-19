## template
from collections import defaultdict

n = int(input())
s = ""
sums = 0
dup = defaultdict(int)
cnt = {}

def division(x):
  global s, n, sums, cnt, dup
  # print("division", x)
  if sums >= n:
    if sums == n and len(s) >= 2 and str(cnt) not in dup.keys():
      print(s)
      dup[str(cnt)] = 1
    return
  for i in reversed(range(1, x+1)):
    sums += i
    # print("reversed", s, i, sums)
    if str(i) not in cnt:
      cnt[str(i)] = 0

    if s != "":
      s += "+"
      s += str(i)
      cnt[str(i)] += 1
      division(x-1)
      cnt[str(i)] -= 1
      s = s[:-2]
    else:
      s += str(i)
      cnt[str(i)] += 1
      division(x-1)
      cnt[str(i)] -= 1
      s = s[:-1]
    sums -= i

division(n)
print(len(dup.keys()))
