/*
问题描述：
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

/*
思路：
1.思路一：双重循环，逐个找出是否有相等的元素
2.思路二：先排序，然后对比每个元素和它的下个元素
*/


方法一实现：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};


方法二：
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
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
