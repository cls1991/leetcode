# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-paths/description.
    题目描述:

    Given a binary tree, return all root-to-leaf paths.

    For example, given the following binary tree:

           1
         /   \
        2     3
         \
          5
        All root-to-leaf paths are:

        ["1->2->5", "1->3"]
    Credits:
    Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []

        ans = []
        self.recursive_tree_path(root, '', ans)

        return ans

    def recursive_tree_path(self, root, path, ans):
        if not root.left and not root.right:
            ans.append(path + root.val)
        if root.left:
            self.recursive_tree_path(root.left, path + str(root.val) + '->', ans)
        if root.right:
            self.recursive_tree_path(root.right, path + str(root.val) + '->', ans)
