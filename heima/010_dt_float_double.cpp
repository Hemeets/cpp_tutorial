#include<iostream>
using namespace std;

// float 4字节，7位有效数字，3.14--3位有效
// double 8字节，

int main(){
    float f1 = 3.14f;  // 加f可以减少一步程序内部的转换
    double d1 = 3.1415926;  // 默认情况下，输出一个小数，会显示6位有效数字

    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << d1 << endl;

    cout << "float 占用的内存空间为：" << sizeof(float) << endl;
    cout << "double : " << sizeof(double) << endl;

    // 科学计算法
    float f2 = 3e2;
    cout << "f2: " << f2 << endl;
    float f3 = 3e-2;
    cout << "f3: " << f3 << endl;

    return 0;
}