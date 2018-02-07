# coding: utf8


"""
    题目链接: https://leetcode.com/problems/remove-duplicate-letters/description.
    题目描述:

    Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and
    only once. You must make sure your result is the smallest in lexicographical order among all possible results.

    Example:
    Given "bcabc"
    Return "abc"

    Given "cbacdcbc"
    Return "acdb"

    Credits:
    Special thanks to @dietpepsi for adding this problem and creating all test cases.

"""


class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s or len(s) < 2:
            return s

        vis = [0] * 26
        cnt = [0] * 26
        ans = []
        for c in s:
            cnt[ord(c) - 97] += 1
        # 遍历, 若当前字符已入栈, 跳过
        # 否则, 与栈顶字符比较, 若小于栈顶字符且cnt[c] > 0(证明后面还会出现该字符), 出栈, 同时访问标记置为0
        # 当前字符入栈, 访问标记置为1
        for c in s:
            idx = ord(c) - 97
            cnt[idx] -= 1
            if vis[idx]:
                continue
            while ans and c < ans[-1] and cnt[ord(ans[-1]) - 97]:
                vis[ord(ans[-1]) - 97] = 0
                ans.pop()
            ans.append(c)
            vis[idx] = 1

        return ''.join(ans)
