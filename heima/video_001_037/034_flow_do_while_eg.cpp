#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // 找出所有水仙花数，在所有三位数中：个位^3 + 十位^3 + 百位^3 = 本身

    int num = 0;

    do
    {
        int a = 0;  //个位
        int b = 0;
        int c = 0;

        a = num % 10;
        b = num / 10 % 10;
        c = num / 100;

        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout << num << endl;
        }
        
        num++;
    } while (num < 1000);
    

    
    return 0;
}