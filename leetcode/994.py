from queue import Queue
class Solution:
  def bfs(self, grid, i, j, minute):
    dirs = [(1,0), (-1,0), (0,1), (0,-1)]
    q = Queue()
    q.put((i,j,minute))
    while not q.empty():
      y, x, m = q.get()
      self.visited[y][x] = m
      for dy, dx in dirs:
        y2 = y + dy
        x2 = x + dx
        if y2 < 0 or y2 >= self.rows:
          continue
        if x2 < 0 or x2 >= self.cols:
          continue
        if m+1 >= self.visited[y2][x2]:
          continue
        if grid[y2][x2] != 1:
          continue
        q.put((y2,x2,m+1))

  def orangesRotting(self, grid: List[List[int]]) -> int:
    self.rows = len(grid)
    self.cols = 0
    if self.rows > 0:
      self.cols = len(grid[0])
    self.visited = [[float('inf') for _ in range(self.cols)] for _ in range(self.rows)]
    for i in range(self.rows):
      for j in range(self.cols):
        if grid[i][j] == 2:
          self.bfs(grid, i, j, 0)

    min_minute = 0
    for i in range(self.rows):
      for j in range(self.cols):
        if grid[i][j] == 1 and self.visited[i][j] == float('inf'):
          return -1
        elif grid[i][j] == 1 and self.visited[i][j] != float('inf'):
          min_minute = max(min_minute, self.visited[i][j])
        print(str(self.visited[i][j]) + " ", end="")
      print()
    return min_minute

