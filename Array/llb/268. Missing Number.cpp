/*
问题描述：
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
思路：
一：先排序，再和下标对比
二：因为0-n的元素一个不少的话，可以利用长度求和，再循环把存在的而数字全部减去，缺少的数字就是剩余的和数
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<=nums.size(); i++)
        // {
        //     if (nums[i] != i) {
        //         return i;
        //     }
        // }
        // return 0;
        
        
        //思路二
        int len = nums.size();
        int sum = len*(len+1)/2;
        for (int num : nums) {
            sum -= num;
        }
        return sum;
    }
};
