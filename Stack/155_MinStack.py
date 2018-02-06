# coding: utf8


"""
    题目链接: https://leetcode.com/problems/min-stack/description.
    题目描述:

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
    Example:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   --> Returns -3.
    minStack.pop();
    minStack.top();      --> Returns 0.
    minStack.getMin();   --> Returns -2.

"""


class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        # 记录stack当前最小值
        self.min = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self.min or x <= self.min[-1]:
            self.min.append(x)
        self.stack.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if not self.stack:
            return

        if self.stack[-1] == self.min[-1]:
            self.min.pop()
        self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return -1

        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if not self.min:
            return -1

        return self.min[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
