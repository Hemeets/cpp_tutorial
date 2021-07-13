#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // 输入三只小猪体重，判断哪只最重
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "please input pig A's weight: " << endl;
    cin >> num1;

    cout << "please input pig B's weight: " << endl;
    cin >> num2;

    cout << "please input pig C's weight: " << endl;
    cin >> num3;

    cout << "pig A's weight: " << num1 << endl;
    cout << "pig B's weight: " << num2 << endl;
    cout << "pig C's weight: " << num3 << endl;


    if (num1 > num2)
    {
        if (num1 > num3)
        {
            cout << "pig A most weight" << endl;
        }
        else 
        {
            cout << "pig C most weight" << endl;
        }
    }
    else
    {
        if (num2 > num3)
        {
            cout << "pig B most weight" << endl;
        }
        else 
        {
            cout << "pig C most weight" << endl;
        }
    }
    

    
    return 0;
}