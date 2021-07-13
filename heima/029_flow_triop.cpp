#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // 三目运算符 exp1 ? exp2: exp3, 如果exp1为真-->exp2，否则-->exp3
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a : b);
    cout << "c = " << c << endl;

    (a > b ? a : b) = 100;  // C++中三目运算符返回的是变量，可以赋值
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    
    return 0;
}