// 普通员工文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"


class Employee: public Worker
{
public:
    // 构造函数
    Employee(int id, string name, int did);

    // show personal info
    virtual void showInfo();

    // get dept name
    virtual string getDeptName();

    ~Employee();
};