## template

# 1232123

# use Backtracking

# 1 - 2 or 3
# doRecursion(x)
# 1. Check -1 step : skip prev [-1] != [0]
# 2. Check -2 -1 step [-3:-1] != [-1:1]
# 3. Check -3 -2 -1 step [-5:-2] != [-2:1]
# n. Check s[-i:] == s[-i*2:-i]


# n = int(input())
# s = ""
# candidates = ["1", "2", "3"]
# solved = False

# def doRecursion(x):
#   global s, solved
#   if solved:
#     return
#   if x>=n:
#     solved = True
#     print(s)
#   else:
#     for c in candidates:
#       s_ = s + c
#       valid = True
#       for i in range(1, int((x+1)/2) + 1):
#         if s_[-2*i:-i] == s_[-i:]:
#           valid = False
#       if valid:
#         s += c
#         doRecursion(x+1)
#         if solved:
#           return
#         s = s[:-1]

# doRecursion(0)
s = ""
nums = ["1", "2", "3"]
n = int(input())
solved = False

def doRecursion(x):
  global s, n, nums, solved
  if solved:
    return
  if x>=n:
    solved = True
    print(s)
    return
  for num in nums:
    ns = s + num
    valid = True
    # 123123213 1,2,3,4
    check_len = int(len(ns)/2)
    for i in range(1, check_len+1):
      # print(ns, ns[-i:], ns[-2*i:-i])
      if ns[-i:] == ns[-2*i:-i]:
        valid = False
    if valid:
      s = ns
      doRecursion(x+1)
      s = s[:-1]

doRecursion(0)