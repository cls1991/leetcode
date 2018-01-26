# coding: utf8


"""
    题目链接: https://leetcode.com/problems/linked-list-cycle/description.
    题目描述:

    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return False

        pre = head
        ptr = head.next

        while ptr and ptr.next:
            if pre == ptr:
                return True
            pre = pre.next
            ptr = ptr.next.next

        return False
