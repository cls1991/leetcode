/*
问题描述：
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

/*先把数字交换到该在的位置，然后数字不符合的再帅选出来，下标+1就是缺失的*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vec;
        
        //把他们交换到该交换的位置
        // for (int i=0; i<nums.size(); i++) {
        //     if (nums[i] != nums[nums[i]-1]) {
        //         swap(nums[i], nums[nums[i]-1]);
        //         i--;
        //     }
        // }
        
        int i=0;
        while(i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
            else {
                i++;
            }
        }
        
        //再比较每个位置的zhi
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) {
                vec.push_back(i+1);
            }
        }
        
        return vec;
    }
};
