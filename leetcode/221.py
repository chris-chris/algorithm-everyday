class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ylen = len(matrix)
        xlen = 0
        if ylen > 0:
            xlen = len(matrix[0])
        dp = [[0 for i in range(xlen+1)] for j in range(ylen+1)]
        maxsize = 0
        for i in range(1, ylen+1):
            for j in range(1, xlen+1):
                if matrix[i-1][j-1] == '1':
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1
                    maxsize = max(maxsize, dp[i][j])
        return maxsize * maxsize