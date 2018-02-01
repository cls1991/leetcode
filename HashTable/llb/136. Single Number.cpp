/*
问题描述：
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
思路：要求是在线性时间完成，并且不适用额外的空间
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //思路一：先排序，然后两两比较，不相同则，单独元素就是就是这组的前一个
        // sort(nums.begin(), nums.end());
        // for (int i=0; i<nums.size(); i+=2) {
        //     if (nums[i] != nums[i+1]) {
        //         return nums[i];
        //     }
        // }
        
        
        //思路二：进行异或运算，就把唯一不同的找出来了
        int result = 0;
        for (int i=0; i<nums.size(); i++) {
            result ^= nums[i];
        }
        return result;
    }
};
