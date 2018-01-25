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
3.知道这次相遇，相遇点即为入环口。
4.解释图链接：http://p16y6inrx.bkt.clouddn.com/Linked%20List%20Cycle%20II.png
  如图假设链表长为L、环长为r, 链表头为h, hd长为a, dc长为x, hc长为s, cd长为y, 第一次相遇点为c, 入环口假设为d.
  假设相遇前fast已经在环内饶了n圈，因为快指针是慢指针走的路程的2倍
  所以：2s = s + nr 导出 s = nr; 又因为a + x = s;
  所以：a + x = nr; 因为 x + y = r;  所以：a = (n-1)r + y;
  所以说，a的长度等于y的长度加上n-1圈的环，所以，此时再将快慢指针从头和初次相遇点开始判断，
  那么无论几圈，那么他们的下次相遇点必然在d，即环的入口处。
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

