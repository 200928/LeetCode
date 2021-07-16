#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool Cmp(vector<int>& a, vector<int>& b)
    {
        return a.at(1) < b.at(1);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
            return a.at(1) < b.at(1);
        });
        return 0;
    }
};

bool cmp(vector<int>&a, vector<int>&b) {
    return a.at(1) < b.at(1);
}

int main() {
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    v1.push_back(1);
    v1.push_back(2);

    v2.push_back(3);
    v2.push_back(4);

    v3.push_back(2);
    v3.push_back(3);

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    Solution test;
    test.eraseOverlapIntervals(v);

    // sort(v.begin(), v.end(), [](vector<int>&a, vector<int>&b) {
    //     return a[1] < b[1];
    // });
    // sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.at(i).size(); j++) {
            cout << v.at(i).at(j) << " ";
        }
        cout << endl;
    }
}