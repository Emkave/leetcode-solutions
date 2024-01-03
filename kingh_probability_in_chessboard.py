'''
https://leetcode.com/problems/knight-probability-in-chessboard/
'''

class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        directions = [(1, 2), (1, -2), (-1, 2), (-1, -2), (2, 1), (2, -1), (-2, 1), (-2, -1)]
        prev_dp = [[0] * n for _ in range(n)]
        curr_dp = [[0] * n for _ in range(n)]
        prev_dp[row][column] = 1
        for moves in range(1, k + 1):
            for i in range(n):
                for j in range(n):
                    curr_dp[i][j] = 0
                    for direction in directions:
                        prev_i, prev_j = i - direction[0], j - direction[1]
                        if 0 <= prev_i < n and 0 <= prev_j < n:
                            curr_dp[i][j] += prev_dp[prev_i][prev_j] / 8
            prev_dp, curr_dp = curr_dp, prev_dp
        total_probability = sum(
            prev_dp[i][j]
            for i in range(n)
            for j in range(n)
        )
        return total_probability