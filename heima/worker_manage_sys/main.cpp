#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
    // // 测试代码
    // Worker *worker = NULL;
    // worker = new Employee(1, "张三", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(2, "李四", 2);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(3, "王五", 3);
    // worker->showInfo();
    // delete worker;

    // 实例化管理者对象
    WorkerManager wm;

    // 用来存储用户的选项
    int choice = 0;
    while (true)
    {
        wm.Show_Menu();
        cout << "请输入选择：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: // exit
            wm.ExistSystem();
            break;
        case 1: // add
            wm.Add_Emp();
            break;
        case 2: // show all
            wm.Show_Emp();
            break;
        case 3: // delete
            wm.Del_Emp();
            break;
        case 4: // modify
            wm.Mod_Emp();
            break;
        case 5: // find
            wm.Find_Emp();
            break;
        case 6: // sort
            wm.Sort_Emp();
            break;
        case 7: // clean
            wm.Clean_File();
            break;
        default:
            break;
        }
    }

    return 0;
}