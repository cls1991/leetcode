# coding: utf8


"""
    题目链接: https://leetcode.com/problems/swap-nodes-in-pairs/description.
    题目描述:

    Given a linked list, swap every two adjacent nodes and return its head.

    For example,
        Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be
    changed.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return 'val: {0}'.format(self.val)


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        cursor = head
        pre = ListNode(0)
        head = head.next

        while cursor and cursor.next:
            n = cursor.next
            cursor.next = n.next
            n.next = cursor
            pre.next = n
            pre = cursor
            cursor = cursor.next

        return head
