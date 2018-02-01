/*
问题描述：
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        //基本思路：逐个遍历找寻是否有相同的
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
        */
        
        
        //思路二：先排序，然后对比每个元素和它的下个元素
        if (nums.size() == 0) {
            return false;
        }
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
        
    }
};
