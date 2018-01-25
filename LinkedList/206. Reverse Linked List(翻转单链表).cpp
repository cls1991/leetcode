/*
问题描述：
Reverse a singly linked list.
*/

/*
思路：定义一个头结点和头结点之前的指针，每步生成一个指针保存下个节点地址，然后翻转指针指向，之后一步步向后移动
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pPrev = nullptr;
        while(head) {
            ListNode* pNode = head->next;
            head->next = pPrev;
            pPrev = head;
            head = pNode;
        }
        
        return pPrev;
    }
};


//拆分出来的代码，步骤细分的
class Solution {
public:
    ListNode * reverse(ListNode * head) {
        // write your code here
        ListNode* pReverseHead = nullptr;         //翻转后的指针头结点
        ListNode* pNode = head;                   //当前结点
        ListNode* pPrev = nullptr;                //前一节点
        while (pNode != nullptr) {
            ListNode* pNext = pNode->next;        //next保存当前结点的下个结点，防止丢失
            if (pNext == nullptr) {
                pReverseHead = pNode;             //如果下个结点直接为nullptr结束了，那么翻转头就是本结点了
            }
            pNode->next = pPrev;                  //将当前结点指向前一个结点，翻转
            //结点向后移动
            pPrev = pNode;
            pNode = pNext;
        }
        
        return pReverseHead;
    }
};
