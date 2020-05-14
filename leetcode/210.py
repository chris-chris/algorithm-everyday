from collections import defaultdict
class Solution:
  WHITE = 1
  GRAY = 2
  BLACK = 3

  def findOrder(self, numCourses, prerequisites):
    graph = defaultdict(list)
    color = {k:Solution.WHITE for k in range(numCourses)}

    for dest, src in prerequisites:
      graph[src].append(dest)

    is_possible = True
    topological_sorted_order = []

    def dfs(node):
      nonlocal is_possible

      if not is_possible:
        return

      color[node] = Solution.GRAY

      if node in graph:
        for neighbor in graph[node]:
          if color[neighbor] == Solution.WHITE:
            dfs(neighbor)
          elif color[neighbor] == Solution.GRAY:
            is_possible = False

      color[node] = Solution.BLACK
      topological_sorted_order.append(node)

    for node in range(numCourses):
      if color[node] == Solution.WHITE:
        dfs(node)
    return topological_sorted_order[::-1] if is_possible else []
