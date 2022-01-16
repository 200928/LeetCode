/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans; // 存答案
        vector<int> row; // 辅助
        vector<int> tmp; // 存每层
        int t1, t2;
        row.push_back(1);
        row.push_back(1);
        for (int i = 1; i <= numRows; i++) {
            // n 层就循环 n 次
            for (int j = 0; j < i; j++) {
                tmp.push_back(row.at(j));
            }
            ans.push_back(tmp); // 添加一层
            tmp.clear(); // 清空
            int cur = 1;
            for (int k = 1; k <= i; k++) {
                if (k == i) {
                    row.push_back(1);
                    continue;
                }
                t1 = cur;
                t2 = row.at(k);
                cur = t2;
                row.at(k) = t1 + t2;
            }
        }
        return ans;
    }
};
// @lc code=end
