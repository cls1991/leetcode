/*
问题描述：
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6

*/


/*
思路：
找出度最大的元素的最小的段的长度
step1:求出所有元素的度值
step2:选出最大的度的元素(们)
step3:找出包含这个最大度的元素的所有段，然后取出最短的段
实现思路：
借助map求出每个元素的度值，然后求出最大的度的那几个元素放入到一个容器中。
在数组遍历每个最大度元素，把他们的index值保存进来，那么第一个到最后一个的距离就是能够包含改度元素的最短的段
*/


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //1.先将所有数字出现次数统计到一个map中
        unordered_map<int, int> countMap;
        for(int num : nums) {
            countMap[num]++;
        }
        
        //2.找到最大的度
        int maxDegree = 0;
        for (auto iter=countMap.begin(); iter!=countMap.end(); iter++) {
            if (iter->second > maxDegree) {
                maxDegree = iter->second;
            }
        }
        
        //3.找到度最大的数字们
        vector<int> maxDegreeNumVec;
        for (auto iter=countMap.begin(); iter!=countMap.end(); iter++) {
            if (iter->second == maxDegree) {
                maxDegreeNumVec.push_back(iter->first);
            }
        }
        
        //4.然后找每个最大度数字的最短段的长度
        int minLen = nums.size();
        for (int maxDegreeNum : maxDegreeNumVec) {
            //存放该度数字index的容器
            vector<int> indexVec;     
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] == maxDegreeNum) {
                    indexVec.push_back(i);
                }
            }
            
            //该最大度数字的最短子串长度，就是找该数字的两头index差
            int len = indexVec[indexVec.size()-1] - indexVec[0] + 1;
            if (len < minLen) {
                minLen = len;
            }
        }
        
        return minLen;
    }
};
