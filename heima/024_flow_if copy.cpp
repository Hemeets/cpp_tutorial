#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    // 
    int score = 0;
    cout << "请输入分数: " << endl;
    cin >> score;
    cout << "score = " << score << endl;

    if (score > 600)  // if 不能加分号
    {
        cout << "恭喜" << endl;
        
    }

    
    return 0;
}