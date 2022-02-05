#include "workerManager.h"

WorkerManager::WorkerManager()
{

}

// 展示函数
void WorkerManager::Show_Menu()
{
    cout << "******************************************" << endl;
    cout << "********** 欢迎使用职工管理系统 **********" << endl;
    cout << "*********** 0. 退出管理系统 **************" << endl;
    cout << "*********** 1. 增加职工信息 **************" << endl;
    cout << "*********** 2. 显示职工信息 **************" << endl;
    cout << "*********** 3. 删除离职职工 **************" << endl;
    cout << "*********** 4. 修改职工信息 **************" << endl;
    cout << "*********** 5. 查找职工信息 **************" << endl;
    cout << "*********** 6. 按照编号排序 **************" << endl;
    cout << "*********** 7. 清空所有文档 **************" << endl;
    cout << "******************************************" << endl;
    cout << endl;
}

// 退出系统
void WorkerManager::ExistSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);  // 退出程序
}


WorkerManager::~WorkerManager()
{

}