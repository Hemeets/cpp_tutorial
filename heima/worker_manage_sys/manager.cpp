#include "manager.h"

Manager::Manager(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

// show personal info
void Manager::showInfo()
{
    cout << "职工编号： " << this->m_Id
         << "\t职工姓名： " << this->m_Name
         << "\t岗位： " << this->getDeptName()
         << "\t岗位职责：完成老板交给的任务，并且下发任务给员工" << endl;
}

// get dept name
string Manager::getDeptName()
{
    return string("经理");
}

Manager::~Manager()
{
    // cout << "Manager 析构函数被调用" << endl;
}