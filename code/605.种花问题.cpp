/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // n朵花至少需要 2n-1 个花坛才可以中下
        // 比如3多花 10101
        
        int len = flowerbed.size();
        if (2 * len - 1 < n) {
            return false;
        }
        for (int i = 0; i < len; i += 2) {
            if (0 == flowerbed[i]) {
                if (i + 1 == len || 0 == flowerbed[i + 1]) {
                    n--;
                    if (n <= 0) {
                        return true;
                    }
                } else {
                    i++;
                }
            }
        }
        return n == 0;
    }
};
// @lc code=end

