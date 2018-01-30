/*
问题描述：
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

利用栈实现队列
*/

/*  思路：
    利用两个栈，每次给栈压入元素时，将新元素放到栈底，那么顺序就和队列类似了.
    利用temp栈，当压入新元素时，先把旧栈元素全部放入到temp栈中，然后，再将新元素压入栈底，之后再将temp中的元素全部重新压入栈中
*/

class MyQueue {

    /*
    思路：
    利用两个栈，每次给栈压入元素时，将新元素放到栈底，那么顺序就和队列类似了.
    利用temp栈，当压入新元素时，先把旧栈元素全部放入到temp栈中，然后，再将新元素压入栈底，之后再将temp中的元素全部重新压入栈中
    */
    
private:
    stack<int> sk;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tempSk;
        while(!sk.empty()) {
            tempSk.push(sk.top());
            sk.pop();
        }
        sk.push(x);
        while(!tempSk.empty()) {
            sk.push(tempSk.top());
            tempSk.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int topElement = sk.top();
        sk.pop();
        return topElement;
    }
    
    /** Get the front element. */
    int peek() {
        return sk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
