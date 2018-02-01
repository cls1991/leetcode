/*
问题描述：
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

class Solution {
public:
    
    /*思考：
        快乐数就是每个数字的各位平方然后继续，把每次计算的结果放入一个容器中，
        每次判断，如果是1，直接返回就是快乐数。
        如果不是1，就判断容器。如果没有则把新数字加入，如果有了，那么之前出现过，之后会陷入循环。
        如果这个重复的数为1，那么直接返回，就是快乐数，如果不是则返回不是快乐数
    */
    
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            int temp = 0;
            while (n) {
                temp += (n%10)*(n%10);      //计算各位的平方，然后相加
                n /= 10;
            }
            n = temp;   //将计算的和赋值给n
            if (s.count(n) > 0)   //陷入重复循环了，判断n是否在set中了
                break;
            else
                s.insert(n);
        }
        
        return n==1;
    }
};
