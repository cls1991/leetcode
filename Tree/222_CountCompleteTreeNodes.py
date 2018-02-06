# coding: utf8


"""
    题目链接: https://leetcode.com/problems/count-complete-tree-nodes/description.
    题目描述:

    Given a complete binary tree, count the number of nodes.

    Definition of a complete binary tree from Wikipedia:
    In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last
    level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        # 满二叉树, 直接返回
        # 不然, leetcode大数据样例通不过测试
        lh = self.left_tree_height(root)
        rh = self.right_tree_height(root)
        if lh == rh:
            return pow(2, lh) - 1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    def left_tree_height(self, root):
        if not root:
            return 0

        return 1 + self.left_tree_height(root.left)

    def right_tree_height(self, root):
        if not root:
            return 0

        return 1 + self.right_tree_height(root.right)
