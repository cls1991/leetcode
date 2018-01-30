# coding: utf8


"""
    题目链接: https://leetcode.com/problems/binary-tree-preorder-traversal/description.
    题目描述:

    Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
        Given binary tree [1,null,2,3],
           1
            \
             2
            /
           3
        return [1,2,3].

    Note: Recursive solution is trivial, could you do it iteratively?

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        self.recursive_preorder(root, ans)
        self.iterative_preorder(root, ans)
        self.morris_preorder(root, ans)

        return ans

    # 递归解法, 基本操作
    def recursive_preorder(self, root, ans):
        if not root:
            return

        ans.append(root.val)
        self.recursive_preorder(root.left, ans)
        self.recursive_preorder(root.right, ans)

    # 非递归解法, 辅助栈
    # 左子树入栈, 右子树的左子树入栈
    def iterative_preorder(self, root, ans):
        stack = []
        while root or stack:
            while root:
                ans.append(root.val)
                # 保存节点, 为了之后遍历其右子树
                stack.append(root)
                root = root.left
            if stack:
                root = stack.pop()
                root = root.right

    # 非递归解法
    # 不需要辅助栈, 充分利用叶子节点的空闲右指针, 指向当前节点的中序后继节点
    # 空间复杂度: O(1), 时间复杂度: O(n)
    def morris_preorder(self, root, ans):
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
                    pre.right = None
                    cur = cur.right
                else:
                    ans.append(cur.val)
                    pre.right = cur
                    cur = cur.left
