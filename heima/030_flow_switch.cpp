#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    cout << "请给电影进行打分" << endl;
    int score = 0;
    cin >> score;
    cout << "score = " << score << endl;


    switch (score)  // 缺点：只能是整型或者是字符型，不能判断区间；优点：执行效率高
    {
    case 10:  // 冒号
        cout << "经典电影" << endl;
        break;  // 如果没有break，程序会接着往下运行
    case 9:
        cout << "经典电影" << endl;
        break;

    default:
        cout << "烂片" << endl;
        break;
    }

    
    return 0;
}