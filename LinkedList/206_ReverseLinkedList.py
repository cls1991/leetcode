# coding: utf8


"""
    题目链接: https://leetcode.com/problems/reverse-linked-list/description.
    题目描述:

    Reverse a singly linked list.

    click to show more hints.

    Hint:
    A linked list can be reversed either iteratively or recursively. Could you implement both?

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseList_v1(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cursor = None
        while head:
            node = head.next
            head.next = cursor
            cursor = head
            head = node

        return cursor

    def reverseList_v2(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        if not head.next:
            return head

        node = self.reverseList_v2(head.next)
        head.next.next = head
        head.next = None

        return node
