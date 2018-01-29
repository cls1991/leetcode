# coding: utf8


"""
    题目链接: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description.
    题目描述:

    Given preorder and inorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.

    For example, given

    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    Return the following binary tree:

        3
       / \
      9  20
        /  \
       15   7

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder:
            return None

        return self.construct_tree_with_preorder_and_inorder(preorder, inorder, 0, len(preorder) - 1,
                                                             0, len(inorder) - 1)

    def construct_tree_with_preorder_and_inorder(self, preorder, inorder, pb, pe, ib, ie):
        if pb > pe:
            return None

        # 查找该节点在中序序列中的索引
        # 递归构造左右子树
        idx = inorder.index(preorder[pb])
        left = self.construct_tree_with_preorder_and_inorder(preorder, inorder, pb + 1, pb + idx - ib, ib, idx - 1)
        right = self.construct_tree_with_preorder_and_inorder(preorder, inorder, pb + idx - ib + 1, pe, idx + 1, ie)
        root = TreeNode(preorder[pb])
        root.left, root.right = left, right

        return root
