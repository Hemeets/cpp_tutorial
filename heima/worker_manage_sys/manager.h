#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager: public Worker
{
public:

    // 构造函数
    Manager(int id, string name, int did);

    // show personal info
    virtual void showInfo();

    // get dept name
    virtual string getDeptName();

    ~Manager();
};