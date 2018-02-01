# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-right-side-view/description.
    题目描述:

    Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
    ordered from top to bottom.

    For example:
        Given the following binary tree,
           1            <---
         /   \
        2     3         <---
         \     \
          5     4       <---
        You should return [1, 3, 4].

    Credits:
    Special thanks to @amrsaqr for adding this problem and creating all test cases.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        ans = []
        self.bfs(root, ans)

        return ans

    def bfs(self, root, ans):
        queue = []
        front = 0
        rear = 1

        queue.append(root)
        while front < rear:
            last = rear
            # 加入每层的最右节点
            ans.append(queue[last - 1].val)
            while front < last:
                root = queue[front]
                front += 1
                if root.left:
                    queue.append(root.left)
                    rear += 1
                if root.right:
                    queue.append(root.right)
                    rear += 1
