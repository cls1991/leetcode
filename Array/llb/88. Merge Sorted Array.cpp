/*
问题描述：
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

/*思路：
一：利用栈，然后排序
二：从尾部开始给排序
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*思路一：利用栈*/
        for (int i=0; i<n; i++) {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //利用数组的index
         m--;
         n--;
         int index = m+n+1;       //新的index
         while (m >= 0 || n >= 0) {
            if (m < 0) {
                nums1[index--] = nums2[n--];    //从尾部处理，m没了就直接复制num2中的
            }
            else if (n < 0) {
                nums1[index--] = nums1[m--];
            }
            else {
                if (nums1[m] > nums2[n]) {
                    nums1[index--] = nums1[m--];
                } 
                else {
                    nums1[index--] = nums2[n--];
                }
            }
        }
    }
};
