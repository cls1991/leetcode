/*
问题描述：
Given a list, rotate the list to the right by k places, where k is non-negative.

Example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/


/*
思路一：
利用指针找到分割点，然后拆分，再拼接起来
思路二：
利用容器等将node放入再拼接

注意：
注意k远大于链表长度的情况，所以要对他取余
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        
        int len = 1;
        ListNode* ptr = head;
        while(ptr->next) {
            len++;
            ptr = ptr->next;
        }
        
        //把尾节点指向头部
        ptr->next = head;
        int step = len - k%len;       //k可以很大
        //找到分割点的前一个点
        for(int i=0; i<step; i++) {
            ptr = ptr->next;
        }
        
        ListNode* newHead = ptr->next;
        ptr->next = nullptr;
        
        return newHead;
    }
};
