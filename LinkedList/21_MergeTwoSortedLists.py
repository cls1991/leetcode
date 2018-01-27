# coding: utf8


"""
    题目链接: https://leetcode.com/problems/merge-two-sorted-lists/description.
    题目描述:

    Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the
    nodes of the first two lists.

    Example:

        Input: 1->2->4, 1->3->4
        Output: 1->1->2->3->4->4

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = cursor = ListNode(0)
        while l1 and l2:
            if l1.val > l2.val:
                cursor.next = l2
                l2 = l2.next
            else:
                cursor.next = l1
                l1 = l1.next
            cursor = cursor.next
        if l1:
            cursor.next = l1
        else:
            cursor.next = l2

        return head.next
