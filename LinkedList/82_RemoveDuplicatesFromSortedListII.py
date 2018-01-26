# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description.
    题目描述:

    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
    original list.

    For example,
        Given 1->2->3->3->4->4->5, return 1->2->5.
        Given 1->1->1->2->3, return 2->3.

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

        # 新生成一个节点, 保存原链表头部
        fake_head = ListNode(0)
        fake_head.next = head
        first_ptr = fake_head
        # pre指针保存前一个数值首次出现的节点位置
        pre = head
        ptr = head.next

        while ptr:
            if ptr.val != pre.val:
                # 核心: 仅相邻两个节点数值不同, 才说明该节点只出现一次
                if pre.next == ptr:
                    first_ptr.next = pre
                    first_ptr = first_ptr.next
                pre = ptr
            ptr = ptr.next

        # 加入最后一个节点
        first_ptr.next = None if pre.next else pre

        return fake_head.next
