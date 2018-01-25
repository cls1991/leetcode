/*
问题描述：
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/*
思路：利用快慢指针的思想，看能否交汇，知道快指针下个点为空(如果有环那么next不会有尾，没环就会有尾)
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            if (fast == slow) {
                return true;
            }
            
            fast = fast->next->next;       //快指针每次走两步
            slow = slow->next;             //慢指针每次走一步
        }
        
        return false;
    }
};
