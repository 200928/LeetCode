# include <iostream>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
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
                if (stack.empty()) {
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
        return true;
    }
};

int main() {
    Solution test;
    test.isValid("{[]}");
    return 0;
}