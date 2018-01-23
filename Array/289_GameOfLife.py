# coding: utf8


"""
    题目链接: https://leetcode.com/problems/game-of-life/description.
    题目描述:

    According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised
    by the British mathematician John Horton Conway in 1970."

    Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its
    eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia
    article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    Write a function to compute the next state (after one update) of the board given its current state.

    Follow up:
    Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some
    cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause
    problems when the active area encroaches the border of the array. How would you address these problems?
    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return

        rows = len(board)
        columns = len(board[0])
        cnt_board = [[0 for _ in range(columns)] for _ in range(rows)]
        neighbors = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
        for i in range(rows):
            for j in range(columns):
                for neighbor in neighbors:
                    dx, dy = i + neighbor[0], j + neighbor[1]
                    if 0 <= dx < rows and 0 <= dy < columns and board[dx][dy] == 1:
                        cnt_board[i][j] += 1
        for i in range(rows):
            for j in range(columns):
                if board[i][j] == 1 and (cnt_board[i][j] < 2 or cnt_board[i][j] > 3):
                    board[i][j] = 0
                elif board[i][j] == 0 and cnt_board[i][j] == 3:
                    board[i][j] = 1
