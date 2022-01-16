#include <iostream>
using namespace std;

class pig {
public:
   void wxy() {
       cout << "王晓云" << endl;
   }
};

int main() {
    pig* p = new pig[10]();
    for (int i = 0; i < 10; i++) {
        cout << "我的第" << i << "个对象是：";
        (p + i)->wxy();
    }
    return 0;
}




