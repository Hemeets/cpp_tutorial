#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // bool类型占用1个字节大小
    bool flag = true;
    cout << flag << endl;  // 输出1
    
    flag = false;
    cout << flag << endl;

    cout << "bool类型占空间 " << sizeof(bool) << endl;

    
    return 0;
}