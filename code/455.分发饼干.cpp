/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 升序排列
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int cookie = 0;
        // 饼干可喂饱，饼干和孩子加一；否则只饼干加一
        while (child < g.size() && cookie < s.size()) {
            if (g.at(child) <= s.at(cookie)) {
                child++;
            }
            cookie++;
        }
        return child;
    }
};
// @lc code=end

