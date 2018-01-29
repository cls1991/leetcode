# coding: utf8


"""
    题目链接: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description.
    题目描述:

    Given inorder and postorder traversal of a tree, construct the binary tree.

    Note:
    You may assume that duplicates do not exist in the tree.

    For example, given

    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
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
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not postorder:
            return None

        return self.construct_tree_with_inorder_and_postorder(inorder, postorder, 0, len(inorder) - 1,
                                                              0, len(postorder) - 1)

    def construct_tree_with_inorder_and_postorder(self, inorder, postorder, ib, ie, pb, pe):
        if pb > pe:
            return None

        # 查找该节点在中序序列中的索引
        # 递归构造左右子树
        idx = inorder.index(postorder[pe])
        left = self.construct_tree_with_inorder_and_postorder(inorder, postorder, ib, idx - 1, pb, pb + idx - ib - 1)
        right = self.construct_tree_with_inorder_and_postorder(inorder, postorder, idx + 1, ie, pb + idx - ib, pe - 1)
        root = TreeNode(postorder[pe])
        root.left, root.right = left, right

        return root
