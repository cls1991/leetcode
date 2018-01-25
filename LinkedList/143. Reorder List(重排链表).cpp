/*
问题描述：
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/


/*
思路：从头结点开始给每个节点后添加最后一位的节点，添加后删除最后一位，一直循环下去
*/

//方法一：以下是自己实现的方法：
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        
        //基本思路：从开头每个节点后添加最后一位的节点，添加后删除最后一位，一直循环下去
        ListNode* pDummy = new ListNode(0);
        pDummy->next = head;
        while(head->next != nullptr && head->next->next != nullptr) {
            ListNode* pPrevLast = FindPervLastNode(head);    //找到最后一个节点前一个节点
            ListNode* pLast = pPrevLast->next;               //记录下最后一个节点
            ListNode* pNext = head->next;                    //记录下当前节点的下个节点
            
            head->next = pLast;                 
            pLast->next = pNext; 
            pPrevLast->next = nullptr;
            head = head->next->next;
        }
        
        head = pDummy->next;    //再将指针复原
    }
    
    //找到最后一个节点的前一个节点
    ListNode* FindPervLastNode(ListNode* node) {
        while(node->next->next != nullptr) {
            node = node->next;
        }
        
        return node;
    }
};




//方法二：九章算法的方法
//方法理解：借助容器来讲链表按顺序拆开，然后再连接
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL)
            return;
        
        vector<ListNode*> nodes;
        ListNode* iter = head;
        while(iter != NULL)
        {
            nodes.push_back(iter);
            iter = iter->next;
        }
        
        int LEN = nodes.size();
        int left = 0;
        int right = LEN -1;
        while(left < right)
        {
            nodes[left]->next = nodes[right];
            nodes[right--]->next = nodes[++left];
        }
        nodes[left]->next = NULL;
    }
};
