/*
问题描述：
We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //思路：其实就是组合能组成10、11、0，不能组成01、00这样的，然后判断最后最后剩余的
        int i = 0;
        while (i < bits.size()-1){
            if (bits[i] == 1){
                i += 2;
            }else{
                i++;
            }
        }
        return i == bits.size()-1;
    }
};
