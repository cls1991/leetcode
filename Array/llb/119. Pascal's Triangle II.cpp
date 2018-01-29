/*
杨辉三角二：
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex+1);
        vec[0] = 1;       //相当于赋初始值
        for (int i=0; i<=rowIndex; i++) {
            for (int j=i; j>0; j--) {     //vec[0]永远不变
                vec[j] = vec[j] + vec[j-1];
            }
        }
        return vec;
    }
};
