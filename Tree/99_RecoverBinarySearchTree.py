# coding: utf8


"""
    题目链接: https://leetcode.com/problems/recover-binary-search-tree/description.
    题目描述:

    Two elements of a binary search tree (BST) are swapped by mistake.

    Recover the tree without changing its structure.

    Note:
    A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        # 保存中序序列, 排序, 重新赋值
        # 待改进: 空间复杂度: O(n)
        # ans = []
        # values = []
        # self.recursive_inorder(root, ans, values)
        # values.sort()
        # for i in range(len(ans)):
        #     ans[i].val = values[i]

        self.morris_inorder(root)

    def recursive_inorder(self, root, ans, values):
        if not root:
            return

        self.recursive_inorder(root.left, ans, values)
        ans.append(root)
        values.append(root.val)
        self.recursive_inorder(root.right, ans, values)

    # 改进算法, 线索二叉树
    # 空间复杂度: O(1)
    def morris_inorder(self, root):
        if not root:
            return

        # first, second指针记录出错的两个节点
        # predecessor指针记录中序前驱节点
        # 比较当前节点与中序前驱节点数值
        first = second = predecessor = None
        cur = root
        while cur:
            if not cur.left:
                if predecessor and predecessor.val >= cur.val:
                    if not first:
                        first = predecessor
                    second = cur
                predecessor = cur
                cur = cur.right
            else:
                pre = cur.left
                while pre.right and pre.right != cur:
                    pre = pre.right

                if pre.right == cur:
                    if predecessor.val >= cur.val:
                        if not first:
                            first = predecessor
                        second = cur
                    pre.right = None
                    predecessor = cur
                    cur = cur.right
                else:
                    pre.right = cur
                    cur = cur.left

        if first and second:
            first.val, second.val = second.val, first.val
