# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-inorder-traversal/description.
    题目描述:

    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
        Given binary tree [1,null,2,3],
           1
            \
             2
            /
           3
        return [1,3,2].

    Note: Recursive solution is trivial, could you do it iteratively?

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        # self.recursive_inorder(root, ans)
        # self.iterative_inorder(root, ans)
        self.morris_inorder(root, ans)

        return ans

    # 递归解法, 基本操作
    def recursive_inorder(self, root, ans):
        if not root:
            return

        self.recursive_inorder(root.left, ans)
        ans.append(root.val)
        self.recursive_inorder(root.right, ans)

    # 非递归解法, 与先序类似
    # 辅助栈
    def iterative_inorder(self, root, ans):
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            if stack:
                node = stack.pop()
                ans.append(node.val)
                root = node.right

    # 非递归解法
    # 不需要辅助栈, 充分利用叶子节点的空闲右指针, 指向当前节点的中序后继节点
    # 空间复杂度: O(1), 时间复杂度: O(n)
    def morris_inorder(self, root, ans):
        if not root:
            return

        cur = root
        while cur:
            if not cur.left:
                ans.append(cur.val)
                cur = cur.right
            else:
                pre = cur.left
                while pre.right and pre.right != cur:
                    pre = pre.right

                if pre.right == cur:
                    ans.append(cur.val)
                    pre.right = None
                    cur = cur.right
                else:
                    pre.right = cur
                    cur = cur.left
