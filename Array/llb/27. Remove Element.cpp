/*
问题描述：
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
*/


/*
思路：和问题26和相似，这个是去掉某个值的元素，然后计算长度。
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int len = 0;
        for(int i=0; i< nums.size(); i++) {
            if (nums[i] != val) {
                nums[len] = nums[i];
                len++;
            }
        }
        
        return len;
    }
};
