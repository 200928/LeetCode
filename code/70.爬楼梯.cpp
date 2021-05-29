/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) {
            return 1;
        }
        if (2 == n) {
            return 2;
        }
        int fast = 1;
        int last = 2;
        for (int i = 2; i < n; i++) {
            last += fast;
            fast = last - fast;
        }
        return last;
    }
};
// @lc code=end

