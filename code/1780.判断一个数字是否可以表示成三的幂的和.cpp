/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
class Solution {
public:
    bool checkPowersOfThree(int n)
    {
        int m = n;
        int cot = 0;
        // 先计算下 3^cot < n < 3^(cot+1)
        while (m / 3 != 0) {
            m /= 3;
            cot++;
        }
        // 3^cot 是能够减去的最大的，然后 cot 减小依次计算 3^cot
        for (int i = cot; i >= 0; i--) {
            int sum = pow(3, i);
            n -= n >= sum ? sum : 0;
        }
        return n == 0;
    }
};
// @lc code=end
