# coding: utf8


"""
    题目链接: https://leetcode.com/problems/minimum-depth-of-binary-tree/description.
    题目描述:

    Given a binary tree, find its minimum depth.

    The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # return self.recursive_tree_of_min_depth(root)
        return self.iterative_tree_of_min_depth(root)

    # 递归解法, 基本操作
    def recursive_tree_of_min_depth(self, root):
        if not root:
            return 0
        if not root.left:
            return self.recursive_tree_of_min_depth(root.right) + 1
        if not root.right:
            return self.recursive_tree_of_min_depth(root.left) + 1

        return min(self.recursive_tree_of_min_depth(root.left), self.recursive_tree_of_min_depth(root.right)) + 1

    # 非递归解法
    # 类似于二叉树的层序遍历
    def iterative_tree_of_min_depth(self, root):
        if not root:
            return 0

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
                # 叶子节点
                if not root.left and not root.right:
                    return depth + 1
                if root.left:
                    queue.append(root.left)
                    rear += 1
                if root.right:
                    queue.append(root.right)
                    rear += 1

            depth += 1

        return depth
