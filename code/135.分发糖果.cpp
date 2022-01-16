/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int size = ratings.size();
        if (size < 2) {
            return size;
        }
        // size个数组元素赋值为1(因为每个小朋友都至少一个)
        vector<int> cur(size, 1);
        int p = 0;
        while (p < size - 1) {   // 从左边遍历
            if (ratings.at(p) < ratings.at(p + 1)) {
                cur[p + 1] = cur[p] + 1;
            }
            p++;
        }
        while (p > 0) { // 从右边遍历
            if (ratings.at(p) < ratings.at(p - 1)) {
                if (cur[p] + 1 > cur[p - 1]) {
                    cur[p - 1] = cur[p] + 1;
                }
            }
            p--;
        }
        return accumulate(cur.begin(), cur.end(), 0);
    }
};

// @lc code=end
