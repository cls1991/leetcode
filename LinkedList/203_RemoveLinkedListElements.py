# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-linked-list-elements/description.
    题目描述:

    Remove all elements from a linked list of integers that have value val.

    Example
        Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
        Return: 1 --> 2 --> 3 --> 4 --> 5

    Credits:
    Special thanks to @mithmatt for adding this problem and creating all test cases.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        fake_head = ListNode(0)
        fake_head.next = head
        ptr = fake_head

        while ptr and ptr.next:
            n = ptr.next
            if n.val == val:
                ptr.next = n.next
                n.next = None
            else:
                ptr = ptr.next

        return fake_head.next
