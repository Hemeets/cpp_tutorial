#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // for(起始表达式;条件表达式;末尾循环体)

    for(int i = 0; i < 10; i++)  // i++ 可以放在循环体里面
    {
        cout << i << endl;
    }

    int i = 0;
    for (; ;) // for里面的东西都可以放在别处，但是代码就不简洁了
    {
        if (i >= 10)
        {
            break;
        }
        cout << i << endl;
        i++;
    }   
    return 0;
}