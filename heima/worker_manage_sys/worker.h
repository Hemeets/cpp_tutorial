#pragma once
#include <iostream>
#include <string>
using namespace std;

// worker abstract class
class Worker
{
public:

    virtual ~Worker()
    {
        // cout << "worker 析构函数被调用" << endl;
    }
    // show personal info
    virtual void showInfo() = 0;

    // get dept name
    virtual string getDeptName() = 0;

    // index
    int m_Id;

    // name
    string m_Name;

    // department
    int m_DeptId;

};