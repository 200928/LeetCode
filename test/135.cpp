#include <iostream>
#include <vector>
using namespace std;

#define Status int
#define ll long long int

int candy(vector<int>& ratings)
{
    int size = ratings.size();
    if (size < 2) {
        return size;
    }
    // size个数组元素，每个初始化为 1
    vector<int> cur(size, 1);
    int left = 0;
    while (left < size - 1) {
        if (ratings.at(left) < ratings.at(left + 1)) {
            cur[left + 1] = cur[left] + 1;
        }
        left++;
    }
    int right = left;
    while (right > 0) {
        if (ratings.at(right) < ratings.at(right - 1)) {
            if (cur[right] + 1 > cur[right - 1]) {
                cur[right - 1] = cur[right] + 1;
            }
        }
        right--;
    }
    int sum = 0;
    vector<int>::iterator it;
    for (it = cur.begin(); it != cur.end(); it++) {
        sum += (*it);
    }
    // return accumulate(cur.begin(), cur.end(), 0);
    return sum;
}

int main() {
    ll a = 19;
    cout << a;
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    cout << candy(v) << "_";
}