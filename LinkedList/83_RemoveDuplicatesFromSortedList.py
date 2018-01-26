# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description.
    题目描述:

    Given a sorted linked list, delete all duplicates such that each element appear only once.

    For example,
        Given 1->1->2, return 1->2.
        Given 1->1->2->3->3, return 1->2->3.

"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        # 游标指针, 比较下一个节点的值
        # 若相同, 删除; 反之, 移动游标, 指向下一个节点
        ptr = head
        while ptr and ptr.next:
            n = ptr.next
            if ptr.val == n.val:
                ptr.next = n.next
                n.next = None
            else:
                ptr = ptr.next

        return head
