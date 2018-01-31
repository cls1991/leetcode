# coding: utf8


"""
    题目链接: https://leetcode.com/problems/surrounded-regions/description.
    题目描述:

    Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

    A region is captured by flipping all 'O's into 'X's in that surrounded region.

    For example,
        X X X X
        X O O X
        X X O X
        X O X X
        After running your function, the board should be:

        X X X X
        X X X X
        X X X X
        X O X X

"""


class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not any(board):
            return

        rows, columns = len(board), len(board[0])
        for i in range(rows):
            for j in range(columns):
                if i == 0 or i == rows - 1 or j == 0 or j == columns - 1 and board[i][j] == 'O':
                    self.dfs(board, rows, columns, i, j)

        for i in range(rows):
            for j in range(columns):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '$':
                    board[i][j] = 'O'

    def dfs(self, board, rows, columns, i, j):
        if i < 0 or i >= rows or j < 0 or j >= columns or board[i][j] != 'O':
            return

        board[i][j] = '$'
        self.dfs(board, rows, columns, i - 1, j)
        self.dfs(board, rows, columns, i, j + 1)
        self.dfs(board, rows, columns, i + 1, j)
        self.dfs(board, rows, columns, i, j - 1)
