#include <iostream>
using namespace std;
#include "workerManager.h"

int main()
{

    WorkerManager wm; // 实例化管理者对象

    int choice = 0; // 用来存储用户的选项
    while (true)
    {
        wm.Show_Menu();
        cout << "请输入选择：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:  // exit
            wm.ExistSystem(); 
            break;
        case 1:  // add
            break;
        case 2:  // show all
            break;
        case 3:  // delete
            break;
        case 4:  // modify
            break;
        case 5:  // find
            break;
        case 6:  // sort
            break;
        case 7:  // clean
            break;
        default:
            break;
        }
    }

    return 0;
}