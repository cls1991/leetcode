# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-postorder-traversal/description.
    题目描述:

    Given a binary tree, return the postorder traversal of its nodes' values.

    For example:
        Given binary tree [1,null,2,3],

           1
            \
             2
            /
           3

    return [3,2,1].

    Note: Recursive solution is trivial, could you do it iteratively?

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        self.recursive_postorder(root, ans)
        self.iterative_postorder(root, ans)

        return ans

    # 递归解法, 基本操作
    def recursive_postorder(self, root, ans):
        if not root:
            return

        self.recursive_postorder(root.left, ans)
        self.recursive_postorder(root.right, ans)
        ans.append(root.val)

    # 非递归解法
    # 需要加一个辅助变量, 标志上次访问的节点
    def iterative_postorder(self, root, ans):
        stack = []
        last_visit_node = root
        while root or stack:
            while root:
                stack.append(root)
                root = root.left

            # 该节点的右子树为空或右子树已访问, 出栈
            # 否则, 继续遍历右子树
            root = stack[-1]
            if not root.right or root.right == last_visit_node:
                ans.append(root.val)
                stack.pop()
                last_visit_node = root
                root = None
            else:
                root = root.right
