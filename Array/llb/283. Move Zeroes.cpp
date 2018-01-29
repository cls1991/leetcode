/*
问题描述：
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
思路：可以放置一个记录非零的下标值，然后依次判断增长，最后它所在的位置就是非0数字的结尾
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //放置一个非零的指针
        int index = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[index++] = nums[i];
            }
        }
        
        //index所在位置就是所有非0的结尾 
        for (; index<nums.size(); index++){
            nums[index] = 0;
        }
    }
};
