/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
// @lc code=start

/**
 * @brief 碰到左括号入栈，右括号匹配栈顶元素
 * 
 */
/* class Solution {
public:
    bool isValid(string s)
    {
        int len = s.size();
        if (len & 1) { // 如果是奇数位
            return false;
        }
        stack<char> stack;
        for (int i = 0; i < len; i++) {
            // 如果为左边，进栈
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.empty()) { // 表示没有左括号与右括号匹配
                    return false;
                } else if (s[i] == ')' && stack.top() == '(') {
                    stack.pop();
                    continue;
                } else if (s[i] == '}' && stack.top() == '{') {
                    stack.pop();
                    continue;
                } else if (s[i] == ']' && stack.top() == '[') {
                    stack.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        // 栈不为空则不匹配
        return stack.size() == 0;
    }
}; */

/**
 * @brief 只是相比上面代码更加简单，无本质区别
 * 
 */
class Solution {
public:
    bool isValid(string s)
    {
        int len = s.size();
        if (len & 1) {
            return false;
        }
        stack<char> stack;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stack.push(')');
            } else if (s[i] == '{') {
                stack.push('}');
            } else if (s[i] == '[') {
                stack.push(']');
            } else { // 如果是右括号，下面开始匹配
                if (!stack.empty() && (s[i] == stack.top())) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.size() == 0;
    }
};


// @lc code=end

