/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a.at(1) < b.at(1);
        });
        int size = intervals.size();
        int pre = intervals.at(0).at(1);
        int count = 0;
        for (int i = 1; i < size; i++) {
            // 如果重合count++
            if (intervals.at(i).at(0) < pre) {
                count++;
                continue;
            }
            pre = intervals.at(i).at(1);
        }
        return count;
    }
};
// @lc code=end
