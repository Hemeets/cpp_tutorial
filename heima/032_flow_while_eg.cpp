#include<iostream>
using namespace std;
#include<ctime>  // 系统时间

int main() {
    cout << "hello world!" << endl;

    //添加 利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int) time(NULL));
    // 系统生成随机数
    int num = rand() % 100 + 1;  // 1~100
    // cout << num << endl;
    
    // 玩家进行猜测
    int val = 0;

    while (1)
    {
        cout << "请输入: " << endl;
        cin >> val;
        // 判断玩家猜测
        if (val > num)
        {
            cout << "猜测过大" << endl;
        }
        else if (val < num)
        {
            cout << "猜测过小" << endl;
        }
        else
        {
            cout << "恭喜，猜对了！" << endl;
            break;
        }
        
    }


    return 0;
}