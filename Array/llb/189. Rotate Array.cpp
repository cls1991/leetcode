/*
问题描述：
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

/*
思路：利用数组翻转，先翻转各自段，然后翻转总的就会出现数组滚动
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //思路：利用数组翻转，先各自翻转两段，再翻转总长
        if (nums.size() == 0) {
            return;
        } 
        
        int len = nums.size();
        k = k%len;
        reverse(nums, 0, len-k-1);
        reverse(nums, len-k, len-1);
        reverse(nums, 0, len-1);
    }
    
    void reverse(vector<int>& nums, int begin, int end) {
        while(begin < end) {
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            begin++;
            end--;
        }
    }
};
