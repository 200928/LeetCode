#include <iostream>
using namespace std;
int main()
{
    int i, j, n, fight = 0;
    cin >> n;
    int a[n][n]; //定义整型二维数组
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j]; //输入每个元素的值}
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i == j) || (i + j == n - 1)) {
                fight = fight + a[i][j]; //计算对角线元素的值
            }
        }
    }
    cout << "\nX战警战斗力为：" << fight;
    return 0;
}
