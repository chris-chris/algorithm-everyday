class Solution:
  def getMoneyAmount(self, n: int) -> int:
    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    for l in range(2, n+1):
      start = 1
      while start <= n - l + 1:
        minres = 999999999
        for piv in range(int(start+(l-1)/2), start+l-1):
          res = piv + max(dp[start][piv-1], dp[piv+1][start+l-1])
          minres = min(res, minres)
        dp[start][start+l-1] = minres
        start += 1
    return dp[1][n]
