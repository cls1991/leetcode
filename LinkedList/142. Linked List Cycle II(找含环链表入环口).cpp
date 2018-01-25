/*
问题描述：
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
*/

/*
思路：
和找链表是否有环一样，利用快慢指针的思路。
1.利用快慢指针找到第一次相遇点
2.然后将快指针(慢指针)指向链表头，慢指针(快指针)继续指向相遇点。注:这时步数每次均都为1
3.知道这次相遇，相遇点即为入环口。(至于原因解析请看md文件)
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            //先走一次，再判断
            fast = fast->next->next;
            slow = slow->next;
            //走到第一个相遇点，把fast又赋给头，继续每次走一步，直到相遇点
            if (fast == slow) {
                fast = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        
        return nullptr;
    }
};

