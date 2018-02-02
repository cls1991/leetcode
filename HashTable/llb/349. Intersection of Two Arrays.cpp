/*
问题描述：
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //思路一：先排序，然后利用两个下标从两个容器开始，比较大小，把小的向后移动。
        //如果相等的话，再比较是结果的容器内是否已经有了该值
        int i=0, j=0;
        vector<int> vec;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] > nums2[j]) {
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                if (vec.empty() || vec.back() != nums1[i]) {
                    vec.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        return vec;
    }
};
