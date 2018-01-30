# coding: utf8


"""
    题目链接: https://leetcode.com/problems/path-sum-ii/description.
    题目描述:

    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

    For example:
        Given the below binary tree and sum = 22,
                      5
                     / \
                    4   8
                   /   / \
                  11  13  4
                 /  \    / \
                7    2  5   1
        return
        [
           [5,4,11,2],
           [5,8,4,5]
        ]

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root:
            return []

        ans = sub = []
        self.recursive_path_sum(root, sum, sub, ans)

        return ans

    def recursive_path_sum(self, root, sum, sub, ans):
        sub.append(root.val)
        if not root.left and not root.right and sum == root.val:
            ans.append(sub[:])
        if root.left:
            self.recursive_path_sum(root.left, sum - root.val, sub, ans)
        if root.right:
            self.recursive_path_sum(root.right, sum - root.val, sub, ans)
        sub.pop()
