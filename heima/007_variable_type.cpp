#include <iostream>

using namespace std;

int main(){

    // 变量创建的方法：数据类型 变量名 = 变量初始值
    short num1 = 32768;  // -2e8~2e8-1: -32768~32767
    int num2 = 32768;
    long num3 = 10;
    long long num4 = 10;

    cout << "num = " << num1 << endl;
    cout << "num = " << num2 << endl;
    cout << "num = " << num3 << endl;
    cout << "num = " << num4 << endl;

    return 0;
}