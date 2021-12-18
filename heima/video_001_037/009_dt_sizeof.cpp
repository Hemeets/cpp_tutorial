#include<iostream>
using namespace std;

int main(){
    // sizeof 求数据类型占用内存大小，语法：sizeof(变量类型/变量)

    short num1 = 10;
    
    cout << "short 占用内存大小为：" << sizeof(num1) << endl;
    cout << "int 占用内存大小为：" << sizeof(int) << endl;

    return 0;
}