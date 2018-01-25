/*
问题描述：
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/


/*
思路：由于是链表逆序相加，何不把两条链表值放入到栈中，然后再相加连接起来。
注意：注意链接过程中需要再把链表翻转过来
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
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int sum = 0;
        ListNode* pHead = new ListNode(0);
        while(!s1.empty() || !s2.empty()) {
            if(!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            
            pHead->val = sum%10;
            //这块处理在两个链表都为结束时是没有意义的，当为最后一个时相加时才有意义，
            //因为是最后一遍循环，下次不能再循环赋值了，即不能在执行pHead->val = sum%10;
            ListNode* pNewNode = new ListNode(sum/10);      
            pNewNode->next = pHead;
            pHead = pNewNode;
            sum = sum/10;
        }
        
        return pHead->val==0 ? pHead->next : pHead;
    }
};
