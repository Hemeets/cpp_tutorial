#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    int num = 0;

    do
    {
        cout << num << endl;
        num++;
    }
    while (num < 10);

    // dowhile 和 while 的区别是前者会先执行一次

    
    return 0;
}