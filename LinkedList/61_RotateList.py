# coding: utf8


"""
    题目链接: https://leetcode.com/problems/rotate-list/description.
    题目描述:

    Given a list, rotate the list to the right by k places, where k is non-negative.

    Example:

        Given 1->2->3->4->5->NULL and k = 2,

        return 4->5->1->2->3->NULL.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next or k == 0:
            return head

        def reverse_partial_list(node, start, end):
            """反转指定区间的链表"""
            fake_head = ListNode(0)
            fake_head.next = node
            pre = fake_head
            for _ in range(1, start):
                pre = pre.next

            ptr = pre.next
            ctr = ptr.next

            for _ in range(0, end - start):
                ptr.next = ctr.next
                ctr.next = pre.next
                pre.next = ctr
                ctr = ptr.next

            return fake_head.next

        ll = 0
        p = head
        while p:
            ll += 1
            p = p.next

        k %= ll
        l1 = reverse_partial_list(head, 1, ll)
        l2 = reverse_partial_list(l1, 1, k)
        l3 = reverse_partial_list(l2, k + 1, ll)

        return l3
