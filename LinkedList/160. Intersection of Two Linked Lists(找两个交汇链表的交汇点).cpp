/*
问题描述
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/


/*
思路：
1.因为两个链表最终交汇到一点，所以结尾相同，可能开头长度不同。
2.所以计算两个链表的长度差。
3.然后让长的链表先跑，跑出长度差，然后停下。
4.下来两个链表在统一起点了，再同时跑，两个指针指向相同的点就是交汇点了
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        
        //定义两个迭代器找两个链表的长度
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        
        //找出两个迭代器的长度差
        int lengthA = 1, lengthB = 1;
        while(iterA->next != nullptr) {
            iterA = iterA->next;
            lengthA++;
        }
        
        while(iterB->next != nullptr) {
            iterB = iterB->next;
            lengthB++;
        }
        
        //如果两个链表没有交点
        if (iterA != iterB) {
            return nullptr;
        }
        
        //让长的跑到相同的起点
        if (lengthA > lengthB) {
            for (int i=0; i<lengthA-lengthB; i++) {
                headA = headA->next;
            }
        }
        if (lengthB > lengthA) {
            for (int i=0; i<lengthB-lengthA; i++) {
                headB = headB->next;
            }
        }
        
        //A、B两个链表的交汇点，就是指向的节点地址一样的地方，就是指针相同的地方
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;   //return headB也行
    }
};
