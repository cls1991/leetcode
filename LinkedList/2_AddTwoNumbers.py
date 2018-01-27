# coding: utf8


"""
    题目链接: https://leetcode.com/problems/add-two-numbers/description.
    题目描述:

    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
    order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example

        Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
        Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return '{0}'.format(self.val)


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2

        if not l2:
            return l1

        carry = 0

        head = cursor = None

        while l1 and l2:
            s = l1.val + l2.val + carry
            if s >= 10:
                carry = 1
            else:
                carry = 0
            if not head:
                head = ListNode(s % 10)
                cursor = head
            else:
                cursor.next = ListNode(s % 10)
                cursor = cursor.next
            l1 = l1.next
            l2 = l2.next

        while l1:
            s = l1.val + carry
            if s >= 10:
                carry = 1
            else:
                carry = 0
            cursor.next = ListNode(s % 10)
            cursor = cursor.next
            l1 = l1.next

        while l2:
            s = l2.val + carry
            if s >= 10:
                carry = 1
            else:
                carry = 0
            cursor.next = ListNode(s % 10)
            cursor = cursor.next
            l2 = l2.next

        if carry:
            cursor.next = ListNode(carry)

        return head
