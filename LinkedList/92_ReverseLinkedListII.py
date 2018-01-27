# coding: utf8


"""
    题目链接: https://leetcode.com/problems/reverse-linked-list-ii/description.
    题目描述:

    Reverse a linked list from position m to n. Do it in-place and in one-pass.

    For example:
        Given 1->2->3->4->5->NULL, m = 2 and n = 4,

        return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head or not head.next or m == n:
            return head

        fake_head = ListNode(0)
        fake_head.next = head
        pre = fake_head
        for _ in range(1, m):
            pre = pre.next

        ptr = pre.next
        ctr = ptr.next

        for _ in range(0, n - m):
            ptr.next = ctr.next
            ctr.next = pre.next
            pre.next = ctr
            ctr = ptr.next

        return fake_head.next
