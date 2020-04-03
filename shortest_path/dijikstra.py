from collections import defaultdict

graph = defaultdict(list)
table = defaultdict(int)
check = defaultdict(bool)

n, m = input().split()
n, m = int(n), int(m)

for i in range(m):
  a, b = input().split()
  a, b = int(a), int(b)
  graph[a].append(b)
  graph[b].append(a)

begin, end = input().split()
begin, end = int(begin), int(end)

for i in range(n):
  table[i] = 999999999
  check[i] = False

table[begin] = 0

# for i = 0 ~ n
for i in range(n):
  minIndex = -1
  minValue = 999999999
  for j in range(n):
    if table[j] <= minValue and not check[j]:
      minValue = table[j]
      minIdex = j

  check[minIdex] = True
  for node in graph[minIdex]:
    if table[node] > table[minIdex] + 1:
      table[node] = table[minIdex] + 1

print(table[end])