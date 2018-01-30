# coding: utf8


"""
    题目链接: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description.
    题目描述:

    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w
    as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

            _______6______
           /              \
        ___2__          ___8__
       /      \        /      \
       0      _4       7       9
             /  \
             3   5
    For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
    since a node can be a descendant of itself according to the LCA definition.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None

        # 公共祖先节点位于左子树中
        if root.val > max(p.val, q.val):
            return self.lowestCommonAncestor(root.left, p, q)
        # 公共祖先节点位于右子树中
        elif root.val < min(p.val, q.val):
            return self.lowestCommonAncestor(root.right, p, q)

        return root
