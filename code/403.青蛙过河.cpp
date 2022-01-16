/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution {
public:

    int isElement(vector<int>& v, int index, int k) {
        for (int i = index; i < v.size(); i++) {
            if (v.at(index) + k + 1 == v.at(i)) {
                return i;
            }
        }
        return -1;
    }

    bool canCross(vector<int>& stones) {
        if (stones.size() <= 1) {
            return false;
        }
        if (stones.at(1) - stones.at(0) > 1) {
            return false;
        }
        int k = 1;
        for (int i = 1; i < stones.size() - 1; i++) {
            int cur1 = isElement(stones, i, k + 1);
            int cur2 = isElement(stones, i, k);
            int cur3 = isElement(stones, i, k - 1); 
            int j = i;
            if (cur1 != -1) {
                i = cur1 - 1;
                k = stones.at(i + 1) - stones.at(j);
                continue;
            } else if (cur2 != -1) {
                i = cur2 - 1;
                continue;
            } else if (cur3 != -1) {
                i = cur3 - 1;
                k = stones.at(i + 1) - stones.at(j);
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};I am your dad you know?long long ago ,we are 
// @lc code=end

