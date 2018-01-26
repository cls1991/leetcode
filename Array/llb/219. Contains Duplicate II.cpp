/*
问题描述：
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
*/

/*
思路：是否包含了重复的数字，并且他们的下标差不大于k
借助map来实现，key存nums的值，value存下标i
*/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> myMap;
        for (int i=0; i<nums.size(); i++) {
            if (myMap.find(nums[i]) != myMap.end() && i-myMap[nums[i]] <= k) {
                return true;
            } else {
                myMap[nums[i]] = i;
            }
        }
        return false;
    }
};
