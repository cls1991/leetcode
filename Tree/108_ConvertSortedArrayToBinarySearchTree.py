# coding: utf8


"""
    题目链接: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description.
    题目描述:

    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
    of every node never differ by more than 1.


    Example:

        Given the sorted array: [-10,-3,0,5,9],

        One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

              0
             / \
           -3   9
           /   /
         -10  5

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.construct_binary_search_tree(nums, 0, len(nums) - 1)

    # 二分, 递归建立二叉搜索树
    def construct_binary_search_tree(self, nums, nl, nr):
        if nl > nr:
            return None

        mid = nl + (nr - nl) / 2
        left = self.construct_binary_search_tree(nums, nl, mid - 1)
        right = self.construct_binary_search_tree(nums, mid + 1, nr)
        root = TreeNode(nums[mid])
        root.left, root.right = left, right

        return root
