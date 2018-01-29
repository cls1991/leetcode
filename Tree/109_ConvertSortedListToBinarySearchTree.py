# coding: utf8


"""
    题目链接: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description.
    题目描述:
    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
    of every node never differ by more than 1.


    Example:

    Given the sorted linked list: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

          0
         / \
       -3   9
       /   /
     -10  5

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        return self.construct_binary_search_tree_with_fast_snow_pointers(head, None)

    # 快慢指针, 建立二叉搜索树
    def construct_binary_search_tree_with_fast_snow_pointers(self, head, last):
        if head == last:
            return None

        fast = snow = head
        while fast != last and fast.next != last:
            snow, fast = snow.next, fast.next.next

        left = self.construct_binary_search_tree_with_fast_snow_pointers(head, snow)
        right = self.construct_binary_search_tree_with_fast_snow_pointers(snow.next, last)
        root = TreeNode(snow.val)
        root.left, root.right = left, right

        return root
