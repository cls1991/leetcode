# ================================================================================
#  LeetCode - Algorithms - 2. Add Two Numbers
#  https://leetcode.com/problems/add-two-numbers/description/
# 
#  Language: Python3
#  Author: ConradG
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   第一反应竟然是反转后转换成数字进行加法 XD
#   基本的链表操作，不过肯定python小伙伴告知为什么这么慢 T.T
# ================================================================================

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        p = 0
        result = t = ListNode(0)
        while (l1 or l2 or p > 0):
            
            a = l1.val if l1 != None else 0
            b = l2.val if l2 != None else 0
            
            t.next = ListNode((a + b + p) % 10)
            t = t.next

            l1, l2, p = l1.next if l1 else None, l2.next if l2 else None, (a + b + p) // 10

        return result.next

# 1562 / 1562 test cases passed.
# Status: Accepted
# Runtime: 215 ms 
# Your runtime beats 40.06 % of python3 submissions.
