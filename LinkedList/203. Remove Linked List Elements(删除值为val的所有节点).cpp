/*
问题描述：
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

/*思路:
  遍历整个链表，相等的删掉（利用上个节点指针的next指向下个node），不同的继续向下进行
  注意：第一个节点的判断，所以可以加上个节点，next指向头结点来处理
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0);         //作为头结点的上一个节点，为了方便处理头结点
        temp->next = head;
        
        ListNode* pCur = temp;                  //加一个当前指针来操作链表
        while(pCur->next != nullptr) {
            if (pCur->next->val == val) {
                pCur->next = pCur->next->next;
            }else {
                pCur = pCur->next;
            }
        }
        
        return temp->next;
    }
};
