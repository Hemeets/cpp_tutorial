#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // 前置递增
    int a = 10;
    ++a;
    cout << a << endl;

    // 后置递增
    int b = 10;
    b++;
    cout << b << endl;

    // 前置与后置的区别
    // 前置递增：先让变量+1，然后进行表达式运算
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << a2 << endl;
    cout << b2 << endl;

    // 后置递增：先进行表达式运算，后让变量+1
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << a3 << endl;
    cout << b3 << endl;


    return 0;
}