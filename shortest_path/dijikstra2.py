import collections

n, m = input().split()
n, m = int(n), int(m)

graph = collections.defaultdict(list)
table = [999999999 for _ in range(n)]
check = [False for _ in range(n)]

for _ in range(m):
  s, e = input().split()
  s, e = int(s), int(e)
  graph[s].append(e)
  graph[e].append(s)

start, to = input().split()
start, to = int(start), int(to)

table[start] = 0

for _ in range(n):
  min_index = -1
  min_value = 9999999999
  for i in range(n):
    if min_value > table[i] and not check[i]:
      min_index = i
      min_value = table[i]

  check[min_index] = True

  for target in graph[min_index]:
    if table[target] >= table[min_index] + 1:
      table[target] = table[min_index] + 1

print(f"{table[to]}")

"""
11 14
0 1
0 2
1 2
1 4
1 5
2 3
3 7
4 7
4 9
4 10
5 6
6 8
6 10
7 8
0 10
"""