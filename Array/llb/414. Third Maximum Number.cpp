/*
问题描述：
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/


/*思路：先排序，然后按照从尾部开始倒着寻找第三个，如果最后没有第三个大，那么就返回最大的*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //思路返回第三个大的数
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int temp = nums[len-1];
        int numKind = 1;
        for (int i=len-1; i>=0; i--) {
            if (nums[i] < temp) {
                temp = nums[i];
                numKind++;
                if (numKind == 3) {
                    break;
                }
            }
        }
        
        if (numKind < 3) {
            return nums[len-1];    //小于3时返回最大的
        }
        return temp;
    }
};
