/*
# ================================================================================
#  LeetCode - Algorithms - 3. Longest Substring Without Repeating Characters
#  https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# 
#  Language: C++
#  Author: ConradG
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   比较典型的滑动窗口结构。
# ================================================================================
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 记录每一个字符在滑动窗口中出现的绝对位置
        int pos[256];
        for(int &e : pos) e = -1;
        
        int left = 0, right = 0, max = 0;
        for(char ch : s){
            
            // 如果当前字符在记录的绝对位置不为-1，窗口的左边界移动到上次出现位置的右侧
            if(pos[ch] > -1){
                int temp = pos[ch];
                for(int i = left; i <= pos[ch]; i++) pos[s[i]] = -1;
                left = temp + 1;
            }
            
            // 滑动右边界
            pos[ch] = right++;
            
            // 更新最大值
            if(right - left > max) max = right - left;
        }
        
        return max;
    }
};

/*
# 983 / 983 test cases passed.
# Status: Accepted
# Runtime: 20 ms
# Your runtime beats 87.30 % of cpp submissions.
*/
