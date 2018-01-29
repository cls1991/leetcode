# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-level-order-traversal/description.
    题目描述:

    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by
    level).

    For example:
        Given binary tree [3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        return its level order traversal as:
        [
          [3],
          [9,20],
          [15,7]
        ]

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        queue = []
        ans = []
        # 非递归解法
        # 模拟队列, 辅助变量: 记录队列头尾节点
        front = 0
        rear = 1
        queue.append(root)

        while front < rear:
            # 记录上一层节点数
            last = rear
            level = []
            while front < last:
                root = queue[front]
                level.append(root.val)
                front += 1
                # 左右子树入队
                if root.left:
                    queue.append(root.left)
                    rear += 1
                if root.right:
                    queue.append(root.right)
                    rear += 1

            ans.append(level)

        return ans
