/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // 滑动窗口
        unordered_set<char> set;
        int l = 0;
        int max = 0;
        // 依次遍历看每个字符开头最长多长
        for (int i = 0; i < s.size(); i++) {
            // 如果右边界字符没有出现过，则不进入循环
            while (set.find(s[i]) != set.end()) {
                set.erase(s[l]);
                l++;
            }
            int len = i - l + 1;
            max = max >= len ? max : len;
            set.insert(s[i]);
        }
        return max;
    }
};
// @lc code=end
