/*
问题描述：
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.

The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.
*/

/*
思路：这是个排球积分的问题
题目意思分析：
    1.数字表示分数；
    2.‘+’表示当前轮次的分数等于上两轮分数之和；
    3.‘D’表示当前轮次的分数等于上轮分数的2倍；
    4.‘C’表示清除上一轮分数。
    
    考虑到意思，可以利用栈的思路，但利用vector来完成
*/

//写法一：

// class Solution {
// public:
//     int calPoints(vector<string>& ops) {
//         int sum = 0, score = 0;     //分别表示分数综合和每轮的分数
//         vector<int> roundVec;
//         for (string op : ops) {
//             if (op == "C") {
//                 sum -= roundVec.back();
//                 roundVec.pop_back();             //这儿没有产生本局分数，不可以push进去
//             }
//             else {
//                 if (op == "D") {
//                     score = 2 * roundVec.back(); 
//                     sum += score;
//                 }
//                 else if (op == "+") {
//                     int len = roundVec.size();
//                     score = roundVec[len-1] + roundVec[len-2];
//                     sum += score;
//                 }
//                 else {
//                     score = stoi(op);       //string转成int
//                     sum += score;
//                 }
//                 roundVec.push_back(score);
//             }
//         }
        
//         return sum;
//     }
// };


//写法二：将操作每步操作全部放入容器中，之后再相加即可
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> rounds;
        for (string op : ops) {
            if (op == "C") {
                rounds.pop_back();
            }
            else if (op == "D") {
                rounds.push_back(rounds.back()*2);
            }
            else if (op == "+") {
                int len = rounds.size();
                rounds.push_back(rounds[len-1] + rounds[len-2]);    //rounds.end()[-1];注意这种牛逼的写法
            }
            else {
                rounds.push_back(stoi(op));
            }
        }
            
        //把每轮的数值相加
        int sum = 0;
        for (int round : rounds) {
            sum += round;
        }
        
        return sum;
    }
};



