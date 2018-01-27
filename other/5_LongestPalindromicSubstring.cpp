/*
# ================================================================================
#  LeetCode - Algorithms - 5. Longest Palindromic Substring
#  https://leetcode.com/problems/longest-palindromic-substring/description/
# 
#  Language: C++
#  Author: ConradG
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   与轴对称相关的问题，通常都可以考虑使用“插板法”，即在原有的每个元素之间（包括首尾）插入
# 一个新的元素，以统一处理对称轴为元素或元素之间的情况。
# ================================================================================
*/

class Solution {    
public:
    string longestPalindrome(string s) {
        
        if(s.size() == 0) return s;
        
        // 从这里开始使用“插板法”，将字符串s填充为s'，长度从s.size()变成 2 * s.size() + 1        
        
        // 从s'的中间开始向两边遍历。
        int max_i = s.size();
        int max_len = findPalindrome(s, max_i);
        
        for(int i = 0; i <= s.size(); i++){
            
            //对称轴到边界的距离不能够支持构造比当前更大的回文串时即中止
            if ((s.size() - i) * 2 + 1 <= max_len) break;
            
            int len_left = findPalindrome(s, s.size() - i);
            if(len_left > max_len){
                max_i = s.size() - i;
                max_len = len_left;
            }
            
            int len_right = findPalindrome(s, s.size() + i);
            if(len_right > max_len){
                max_i = s.size() + i;
                max_len = len_right;
            }
        }
        
        return s.substr((max_i - max_len / 2) / 2, max_len / 2);        
    }
    
private:    
    char getChar(string &s, int i){
        return i % 2 == 1 ? s[i / 2] : 1;
    }    
    
    int findPalindrome(string &s, const int i){
        
        int length = s.size() * 2 + 1;
        int left = i, right = i;
        
        while(left >= 0 && right <= length && getChar(s, left) == getChar(s, right)){
            left--; right++;
        }
        
        return right - left - 1;
    }
};

/*
# 94 / 94 test cases passed.
# Status: Accepted
# Runtime: 10 ms
# Your runtime beats 77.04 % of cpp submissions.
*/
