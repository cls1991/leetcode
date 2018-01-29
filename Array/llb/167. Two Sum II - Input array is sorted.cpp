/*
问题描述：
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
思路：由于是排序数组，所以可以从两边开始标记，知道产生结果
注意：最后的index是第n个元素而非下标
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //思路：由于是排序数组，所以从左右两边，用两个标记一次向中间聚头，直到产生结果
        int l=0, r = numbers.size()-1;
        while(l < r) {
            if (numbers[l] + numbers[r] > target) {
                r--;
            }
            else if (numbers[l] + numbers[r] < target) {
                l++;
            }
            else {
                vector<int> resultVec;
                resultVec.push_back(++l);
                resultVec.push_back(++r);
                return resultVec;
            }
        }
        
        return vector<int>(0);
    }
};
