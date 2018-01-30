/*
问题描述：
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

用队列结构实现栈
*/

/* 
  思路一：
  利用两个队列实现，由于只能用队列的基本操作，而不能用back等，所以应该按照如下思路进行：
  一个队列q1只用来模拟栈顶元素，其他元素则放入到另一个队列q2中。
  1.模拟栈的push操作，先判断q1是否为空，如果为空直接压入q1，如果非空，那么先把q1中的元素放入q2队列中，再将新元素放入队列q1。
  2.pop、或者top操作。先判断q1中是否有元素，如果有直接取出即可，如果没有那么找到q2，通过平移找到q2最后一个元素即可。
  3.empty，就是判断q1、q2是否全部为空。
*/

/*
private:
    queue<int> q1, q2;
    
public:
    // Initialize your data structure here. 
    MyStack() {
        
    }
    
    // Push element x onto stack. 
    void push(int x) {
        q1.push(x);
        if (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    // Removes the element on top of the stack and returns that element. 
    int pop() {
        int topElment = top();
        if (!q1.empty()) {
            q1.pop();
        }
        else {
            q2.pop();
        }
        return topElment;
    }
    
    // Get the top element.
    int top() {
        if (q1.empty()) {
            int lenQ2 = q2.size();
            for (int i=0; i<lenQ2-1; i++) {   //移位操作
                q2.push(q2.front());          
                q2.pop();
            }
            q1.push(q2.front());
            q2.pop();
        }
        return q1.front();
    }
    
    // Returns whether the stack is empty. 
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
*/

/*
  思路二：
  也是利用两个队列，就是每次插入的时候，把元素插入到队列的头部，那么也就形成了类似栈的出入顺序。
  就是每次插入到队列的头部时，需要每次借用另一个队列，现将之前元素全部出队放到temp队列中，等新元素进队之后，再将之前temp中的队列元素入队
*/


private:
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tempQ;
        while(!q.empty()) {               //注意：如果某个队列或者容器循环只涉及入或者出，而非出入均衡，那么就不要使用for循环
            tempQ.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!tempQ.empty()) {
            q.push(tempQ.front());
            tempQ.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int topElment = q.front();
        q.pop();
        return topElment;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

