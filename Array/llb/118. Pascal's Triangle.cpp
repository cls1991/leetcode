/*
问题描述：
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/*思路：
每行的两边都是1，中间则有上一行的j和j-1相加而成
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //思路：每行两边的都是1，中间都是上一行的j和j-1之和
        // vector<vector<int>> resultVec(numRows);
        // for (int i=0; i<numRows; i++) {
        //     resultVec[i].resize(i+1);
        //     resultVec[i][0] = 1;
        //     resultVec[i][i] = 1;
        //     for (int j=1; j<i; j++) {
        //         resultVec[i][j] = resultVec[i-1][j-1] + resultVec[i-1][j];
        //     }
        // }
        // return resultVec;
        
        vector<vector<int>> resultVec(numRows);
        for (int i=0; i<numRows; i++) {
            vector<int> tempVec(i+1);
            tempVec[0] = tempVec[i] = 1;            
            for (int j=1; j<i; j++) {
                tempVec[j] = resultVec[i-1][j-1] + resultVec[i-1][j];
            }
            resultVec[i] = tempVec;
        }
        return resultVec;
    }
};

