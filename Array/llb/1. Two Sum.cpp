/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
*/

//思路：求两个数字和的数字index


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> resultVec;
        for(int i=0; i<nums.size(); ++i) {
            int firstNum = nums.at(i);
            for(int j=i+1; j<nums.size(); ++j) {
                int secondNum = nums.at(j);
                if (firstNum + secondNum == target){
                    resultVec.push_back(i);
                    resultVec.push_back(j);
                    return resultVec;
                }
            }
        }
        return resultVec;
    }
};
