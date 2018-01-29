/*
问题描述：
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        int count = 1;        //初始化为第一个
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == nums[majorityIndex]) {
                count++;
            }
            else {
                count--;
            }
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }
        
        return nums[majorityIndex];
    }
};
