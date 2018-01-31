# coding: utf8


"""
    题目链接: https://leetcode.com/problems/sum-root-to-leaf-numbers/description.
    题目描述:

    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

    An example is the root-to-leaf path 1->2->3 which represents the number 123.

    Find the total sum of all root-to-leaf numbers.

    For example,

        1
       / \
      2   3
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.

    Return the sum = 12 + 13 = 25.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, 0)

    def dfs(self, root, sub):
        if not root:
            return 0

        sub = 10 * sub + root.val
        if not root.left and not root.right:
            return sub

        return self.dfs(root.left, sub) + self.dfs(root.right, sub)
