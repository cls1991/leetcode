/*
问题描述：
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/*
思路：每步分别移动两个链表，然后判断两个对应值的大小，如果小的，链接到当前指针，并且只移动当前直小的链表，下次在对比，知道有一个链表为空时
注意：当一个链接结束后还要链接上未完的链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if ((l1 == NULL) && (l2 != NULL))
            return l2;
        else if ((l1 != NULL) && (l2 == NULL))
            return l1;
        else if ((l1 == NULL) && (l2 == NULL))
            return NULL;
        
        //***这个方法是没有生成新的node串联，而是生成一个新的指针串联当前l1、l2中的node***
        ListNode* dummy = new ListNode(0);
        ListNode* pTemp = dummy;     //比较后串联生成链表的指针
        while(l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pTemp->next = l1;
                l1 = l1->next;
            } else {
                pTemp->next = l2;
                l2 = l2->next;
            }
            //再把比较temp向后移动
            pTemp = pTemp->next;
        }
        
        //串联起剩余未完的链表
        if (l1 != nullptr) {
            pTemp->next = l1;
        } else {
            pTemp->next = l2;
        }
        
        //返回头结点
        return dummy->next;
    }
};
