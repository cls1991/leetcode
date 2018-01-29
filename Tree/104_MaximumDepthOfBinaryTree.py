# coding: utf8


"""
    题目链接: https://leetcode.com/problems/maximum-depth-of-binary-tree/description.
    题目描述:

    Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

    For example:
    Given binary tree [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    return its depth = 3.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        # return self.recursive_tree_of_max_depth(root)
        return self.iterative_tree_of_max_depth(root)

    # 递归解法, 基本操作
    def recursive_tree_of_max_depth(self, root):
        if not root:
            return 0

        return max(self.recursive_tree_of_max_depth(root.left), self.recursive_tree_of_max_depth(root.right)) + 1

    # 非递归解法
    # 类似于二叉树的层序遍历
    def iterative_tree_of_max_depth(self, root):
        queue = []
        front = 0
        rear = 1
        depth = 0
        queue.append(root)

        while front < rear:
            last = rear
            while front < last:
                root = queue[front]
                front += 1
                if root.left:
                    queue.append(root.left)
                    rear += 1
                if root.right:
                    queue.append(root.right)
                    rear += 1

            # 整层访问完毕
            depth += 1

        return depth
