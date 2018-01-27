# coding: utf8


"""
    题目链接: https://leetcode.com/problems/intersection-of-two-linked-lists/description.
    题目描述:

    Write a program to find the node at which the intersection of two singly linked lists begins.


    For example, the following two linked lists:

        A:          a1 → a2
                           ↘
                             c1 → c2 → c3
                           ↗
        B:     b1 → b2 → b3
        begin to intersect at node c1.

    Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
    Credits:
    Special thanks to @stellari for adding this problem and creating all test cases.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB:
            return None

        la = lb = 0
        ptr_a = headA
        ptr_b = headB

        while ptr_a:
            la += 1
            ptr_a = ptr_a.next
        while ptr_b:
            lb += 1
            ptr_b = ptr_b.next
        if ptr_a != ptr_b:
            return None

        ptr_a = headA
        ptr_b = headB
        if la > lb:
            while la > lb:
                ptr_a = ptr_a.next
                la -= 1
        else:
            while lb > la:
                ptr_b = ptr_b.next
                lb -= 1

        while ptr_a != ptr_b:
            ptr_a = ptr_a.next
            ptr_b = ptr_b.next

        return ptr_a
