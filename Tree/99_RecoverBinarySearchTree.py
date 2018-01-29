# coding: utf8


"""
    题目链接: https://leetcode.com/problems/recover-binary-search-tree/description.
    题目描述:

    Two elements of a binary search tree (BST) are swapped by mistake.

    Recover the tree without changing its structure.

    Note:
    A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        ans = []
        values = []
        self.recursive_inorder(root, ans, values)
        values.sort()
        for i in range(len(ans)):
            ans[i].val = values[i]

    # 保存中序序列, 排序, 重新赋值
    # 待改进: 空间复杂度: O(n)
    def recursive_inorder(self, root, ans, values):
        if not root:
            return

        self.recursive_inorder(root.left, ans, values)
        ans.append(root)
        values.append(root.val)
        self.recursive_inorder(root.right, ans, values)
