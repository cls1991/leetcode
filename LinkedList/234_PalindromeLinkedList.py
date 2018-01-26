# coding: utf8


"""
    题目链接: https://leetcode.com/problems/palindrome-linked-list/description.
    题目描述:

    Given a singly linked list, determine if it is a palindrome.

    Follow up:
    Could you do it in O(n) time and O(1) space?

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        return 'val: {0}'.format(self.val)


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # @TODO: 优化: 反转链表后半段(空间复杂度O(n)->O(1))
        if not head or not head.next:
            return True

        copy_head = ListNode(head.val)
        ctr = copy_head
        ptr = head.next
        while ptr:
            ctr.next = ListNode(ptr.val)
            ctr = ctr.next
            ptr = ptr.next

        reversed_head = None
        ptr = copy_head

        while ptr:
            node = ptr.next
            ptr.next = reversed_head
            reversed_head = ptr
            ptr = node

        while head and reversed_head and head.val == reversed_head.val:
            head = head.next
            reversed_head = reversed_head.next

        return not head
