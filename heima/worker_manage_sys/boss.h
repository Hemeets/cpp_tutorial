#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss: public Worker
{
public:

    // 构造函数
    Boss(int id, string name, int did);

    // show personal info
    virtual void showInfo();

    // get dept name
    virtual string getDeptName();

    ~Boss();
};