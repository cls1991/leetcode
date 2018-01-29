# coding: utf8


"""
    题目链接: https://leetcode.com/problems/validate-binary-search-tree/description.
    题目描述:

    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    Example 1:
        2
       / \
      1   3
    Binary tree [2,1,3], return true.
    Example 2:
        1
       / \
      2   3
    Binary tree [1,2,3], return false.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # return self.conquer_binary_search_tree(root, float('-inf'), float('inf'))

        ans = []
        self.traverse_binary_search_tree(root, ans)
        for i in range(1, len(ans)):
            if ans[i] <= ans[i - 1]:
                return False

        return True

    # 分治法
    # 递归比较, 左右子树与当前节点数值
    def conquer_binary_search_tree(self, root, min_value, max_value):
        if not root:
            return True
        if root.val >= max_value or root.val <= min_value:
            return False

        return self.conquer_binary_search_tree(root.left, min_value, root.val) and self.conquer_binary_search_tree(
            root.right, root.val, max_value)

    # 中序遍历
    # 特性: 生成序列有序
    def traverse_binary_search_tree(self, root, ans):
        if not root:
            return

        self.traverse_binary_search_tree(root.left, ans)
        ans.append(root.val)
        self.traverse_binary_search_tree(root.right, ans)
