/*
问题描述：
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 1:
Input: [1,3,5,6], 0
Output: 0

*/


/*
思路：
由于数组是有序的，所以找到某个元素之大于等于它时，那么它的前一个位置就是它
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        if (target > nums[length-1]) {
            return length;
        }
        
        int insertIndex = 0;
        for (int i=0; i<nums.size(); i++) {
            if (target <= nums[i]) {
                if (i == 0) {
                    break;
                } else if (target > nums[i-1]) {
                    insertIndex = i;
                    break;
                }
            }
        }
        
        return insertIndex;
    }
};
