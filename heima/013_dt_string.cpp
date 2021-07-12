#include<iostream>
using namespace std;
#include<string>

int main() {
    
    // C风格字符串：char var[] = "字符串"
    char str[] = "hello world";  // 注意，1.要有中括号 []；2. 双引号
    cout << str << endl;

    // C++ 风格：string
    string str2 = "hello world";  // 可能需要#include<string>
    cout << str2 << endl;
    
    return 0;
}