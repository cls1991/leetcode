/*
问题描述：
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/


/*
思路：每次移动两个指针，将两数相加，每次创建一个新node，生成一个链表。
注意：计算它的溢出值，得移动到下位相加时也用到。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        int carry = 0;     //记录每位运算值
        while(true) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            
            ptr->val = carry%10;
            carry = carry/10;
            //如果两个链表还有未空的或者还有进位，就继续运算
            if (l1 != nullptr || l2 != nullptr || carry != 0) {
                ptr->next = new ListNode(0);
                ptr = ptr->next;
            }else {
                break;
            }
        }
        
        return head;
    }
    
};
