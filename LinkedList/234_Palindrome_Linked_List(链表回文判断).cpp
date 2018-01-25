/*
问题描述：
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?
要求：用O(n)的时间复杂度和O(1)的尽量完成

思路：
1.不考虑空间复杂度为o(1),可以借助指针，一个跑到中间节点后，开始把剩下后半部分放入一个栈中，再比较
2.不用栈的话，考虑用链表翻转，将后半段链表翻转
*/


//思路2的实现
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
    bool isPalindrome(ListNode* head) {
        //1.不考虑空间复杂度为o(1),可以借助指针，一个跑到中间节点后，开始把剩下后半部分放入一个栈中，再比较
        //2.不用栈的话，考虑用链表翻转，将后半段链表翻转
        
        //方法二实现
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        
        ListNode* pMid = findMid(head);
        //由于是中点或者中轴上一个点，所以取mid的next翻转。
        ListNode* pReverseHead = reverse(pMid->next);
        //并且连接起两部分
        pMid->next = pReverseHead;
        //开始判断两个链表
        while(head != nullptr && pReverseHead != nullptr) {
            //如果有一个不同就证明不是了
            if (head->val != pReverseHead->val) {
                return false;
            }
            head = head->next;
            pReverseHead = pReverseHead->next;
        }
        
        return true;
    }
    
    //找中点的思路，从两个指针，快指针和慢指针，快每次移动两位，慢每次移动1次
    //总数为奇数时，mid为中点、总数为偶数时，mid为中轴上一个点
    ListNode* findMid(ListNode* pNode) {
        ListNode* pSlow = pNode;
        ListNode* pFast = pNode->next;
        while(pFast != nullptr && pFast->next != nullptr) {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
        }
        return pSlow;
    }
    
    //链表翻转,当前、下一个、之前，然后当前和下一个移位
    ListNode* reverse(ListNode* pNode) {
        ListNode* pPrev = nullptr;
        while(pNode != nullptr) {
            ListNode* pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pPrev;
    }
};
