/*
问题描述：
Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].
*/

/*
思路：
有2n个整数，并且将他们两两分为n个数字对，然后取每对最小的相加，求最大的和
由于为2n个数，所以对数最后肯定为整数，求取每对中最小的，而对的数字选择却由小到大开始选择,所以先排序，选择第奇数个数字相加即可
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0; i<nums.size()-1; i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};

