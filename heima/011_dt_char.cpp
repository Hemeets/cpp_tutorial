#include<iostream>
using namespace std;

int main(){

    // 语法： char ch = 'a';  用于显示单个字符，注意是单个；注意是单引号；
    // c和c++ 中字符型变量只占用1个字节
    // 字符型变量并不是把字符本身放到内存中，而是将对应的ascii码放入存储单元

    char ch = 'A';  // 创建方式
    cout << ch << endl;

    cout << "字符型占用内存空间 " << sizeof(char) << endl;

    // char ch2 = "b";  //常见错误
    // char ch2 = 'abcd' 

    // 字符型变量对应的ascii编码
    cout << (int)ch << endl;  // 字符型强制转整形

    return 0;

}