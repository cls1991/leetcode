# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-search-tree-iterator/description.
    题目描述:

    Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a
    BST.

    Calling next() will return the next smallest number in the BST.

    Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

"""


# Definition for a  binary tree node
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return True if self.stack else False

    def next(self):
        """
        :rtype: int
        """
        root = self.stack.pop()
        right = root.right
        while right:
            self.stack.append(right)
            right = right.left

        return root.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
