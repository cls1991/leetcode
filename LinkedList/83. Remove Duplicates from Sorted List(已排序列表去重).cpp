/*
问题描述：
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/*
思路：由于是已经排序好的了，所以每个节点只需和自己下个元素排序，如果相同则删除，否则继续
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //思路，由于是排序的，所以从头遍历，如果值和下一个相同那么把改node删掉
        if (!head) {
            return nullptr;
        } 
        
        ListNode *pNode = head;
        while(pNode->next != nullptr) {
            if (pNode->val == pNode->next->val) {
                pNode->next = pNode->next->next;
            }else {
                pNode = pNode->next;
            }
        }
        return head;
    }
};
