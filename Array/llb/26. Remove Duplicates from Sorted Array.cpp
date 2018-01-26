/*
问题描述：
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

/*
思路：由于是有序的数组，所以只需比较数组元素前后的值，然后用index重新计算非重元素的值
注意：由于不用管超过新数组长度的事，所以只需
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        if (nums.size() == 0) {
            return 0;
        }
        
        int index = 1;
        for(int i=1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[index] = nums[i];
                index++;
            }
        }
        
        return index;
    }
};
