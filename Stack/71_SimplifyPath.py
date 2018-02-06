# coding: utf8


"""
    题目链接: https://leetcode.com/problems/simplify-path/description.
    题目描述:

    Given an absolute path for a file (Unix-style), simplify it.

    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
    click to show corner cases.

    Corner Cases:
    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

"""


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if not path:
            return ''

        # 记录所有子目录
        stack = []
        i = 0
        while i < len(path):
            # 跳过类似'///'开头
            while i < len(path) and path[i] == '/':
                i += 1
            if i == len(path):
                break
            start = i
            while i < len(path) and path[i] != '/':
                i += 1
            end = i
            # 截取子目录
            sub = path[start:end]
            if sub == '..':
                if stack:
                    stack.pop()
            elif sub and sub != '.':
                stack.append(sub)

        if not stack:
            return '/'

        ans = ''
        for s in stack:
            ans += '/' + s

        return ans
