#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m = n;
    int cot = 0;
    while (m / 3 == 0) {
        m /= 3;
        cot++;
    }
    for (int i = cot; i >= 0; i--) {
        int sum = pow(3, i);
        n -= n >= sum ? sum : 0;
        cout << "sum:" << sum << ",n:" << n << endl;
    }

    return 0;
}