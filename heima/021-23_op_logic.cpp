#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // !, &&, ||
    int a = 10;
    cout << !a << endl;

    a = 10;
    int b = 10;
    cout << (a && b) << endl;

    a = 0;
    b = 10;
    cout << (a || b) << endl;

    
    return 0;
}