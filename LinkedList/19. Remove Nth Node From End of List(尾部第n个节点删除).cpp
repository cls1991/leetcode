/*
问题描述：
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/


/*
思路：先找到总长，再减去n，那个位置就是要删除的节点的前一个节点
注意：细节，删除第一点、n大于链表长度的情况
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *pDummy = new ListNode(0);
        pDummy->next = head;
        ListNode *pIter = head;
        int len = 0;
        while(pIter != nullptr) {
            len++;
            pIter = pIter->next;
        }
        
        //分别进行长度的判断
        if (n > len) {              //n大于长度，没有改点
            return nullptr;    
        } 
        else if (n == len) {        //n等于长度，意思是要删除第一个元素的情况
            pDummy->next = head->next;
            delete head;
            return pDummy->next;
        } 
        else {
            ListNode* pTemp = pDummy->next;
            int index = 0;
            while(pTemp != nullptr && pTemp->next != nullptr) {
                index++;
                //达到要求就删除节点
                if (index + n == len) {
                    pTemp->next = pTemp->next->next;
                    break;
                }
                pTemp = pTemp->next; 
            }
            return pDummy->next;
        }
    }
};
