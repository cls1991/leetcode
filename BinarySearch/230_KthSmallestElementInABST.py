# coding: utf8


"""
    题目链接: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description.
    题目描述:

    Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

    Note:
    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

    Follow up:
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How
    would you optimize the kthSmallest routine?

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class NewTreeNode(object):
    def __init__(self, x):
        self.val = x
        # 新增字段: 记录当前节点的左右子树节点数
        self.count = 1
        self.left = None
        self.right = None


class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        # return self.binary_search_tree_inorder_recursive_optimization(root)
        # ans = []
        # self.binary_search_tree_inorder_iterative(root, ans)
        # return ans[k - 1]
        # return self.binary_search_tree_inorder_iterative_optimization(root, k)
        # return self.binary_search_tree_conquer(root, k)
        root = self.reconstruct_tree(root)
        return self.binary_search_tree_conquer_optimization(root, k)

    # 返回完整的中序序列, 需要额外数组空间存储
    def binary_search_tree_inorder_iterative(self, root, ans):
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            if stack:
                root = stack.pop()
                ans.append(root.val)
                root = root.right

    # 计数, k时, 直接返回(递归)
    def binary_search_tree_inorder_recursive_optimization(self, root):
        if not root:
            return -1

        val = self.binary_search_tree_inorder_recursive_optimization(root.left)
        if self.k == 0:
            return val
        self.k -= 1
        if self.k == 0:
            return root.val

        return self.binary_search_tree_inorder_recursive_optimization(root.right)

    # 计数, k时, 直接返回(非递归)
    def binary_search_tree_inorder_iterative_optimization(self, root, k):
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            if stack:
                root = stack.pop()
                k -= 1
                if k == 0:
                    return root.val
                root = root.right

        return -1

    # 分治法: 计算左右子树节点数
    def binary_search_tree_conquer(self, root, k):
        if not root:
            return -1

        nodes_num = self.calc_nodes(root.left)
        if k <= nodes_num:
            return self.binary_search_tree_conquer(root.left, k)
        elif k > nodes_num + 1:
            return self.binary_search_tree_conquer(root.right, k - nodes_num - 1)

        return root.val

    def calc_nodes(self, root):
        if not root:
            return 0

        return 1 + self.calc_nodes(root.left) + self.calc_nodes(root.right)

    # Follow up: 频繁修改节点, 频繁查找k小数值
    # 在上述的分治法基础上, 进行优化
    # 每次递归计算节点左右子树的节点数, 会造成不必要的开销
    # 可以考虑, 修改TreeNode, 新增count字段, 记录当前节点的左右子树节点数
    def binary_search_tree_conquer_optimization(self, root, k):
        if not root:
            return -1

        if root.left:
            nodes_num = root.left.count
            if k <= nodes_num:
                return self.binary_search_tree_conquer_optimization(root.left, k)
            elif k > nodes_num + 1:
                return self.binary_search_tree_conquer_optimization(root.right, k - nodes_num - 1)

            return root.val
        else:
            if k == 1:
                return root.val

            return self.binary_search_tree_conquer_optimization(root.right, k - 1)

    def reconstruct_tree(self, root):
        if not root:
            return None

        left = self.reconstruct_tree(root.left)
        right = self.reconstruct_tree(root.right)
        root = NewTreeNode(root.val)
        root.left, root.right = left, right
        if root.left:
            root.count += root.left.count
        if root.right:
            root.count += root.right.count

        return root
