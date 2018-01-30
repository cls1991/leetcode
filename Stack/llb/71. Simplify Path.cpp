/*
问题描述：
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
*/

/*
题目理解：
    1.连续出现的'/'，按照一个处理，即跳过重复的'/';
    2.如果是'.'，则不处理；
    3.如果出现'..'，则需要弹栈，如果栈为空，则不处理；
    4.如果为其他元素，则入栈。
    最后，再逐个取出栈中元素（即已保存的路径名），用'/'分隔并连接起来，不过要注意顺序。
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        for (int i=0; i < path.size(); ) {
            //1.跳过斜线
            while (i < path.size() && path[i] == '/') {
                ++i;
            } 
            //记录下路径名
            string s = "";
            while (i < path.size() && path[i] != '/') {
                s += path[i++];
            }
            
            //..需要弹栈，其他入栈
            if (".." == s && !ss.empty()) {
                ss.pop();
            }
            else if (s != "" && s != "." && s != "..") {
                ss.push(s);
            }
        }
        
        //中间条件判断,
        //如果栈为空，说明为根目录，只有斜线'/'
        if (ss.empty()) {
            return "/";
        }
        
        //如果栈里有元素，那么再逐个链接栈里的元素
        string s = "";
        while (!ss.empty()) {
            s = "/" + ss.top() + s;
            ss.pop();
        }
        
        return s;
    }
};
