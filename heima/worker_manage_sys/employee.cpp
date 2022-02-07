#include "employee.h"



Employee::Employee(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

// show personal info
void Employee::showInfo()
{
    cout << "职工编号： " << this->m_Id
         << "\t职工姓名： " << this->m_Name
         << "\t岗位： " << this->getDeptName()
         << "\t岗位职责：完成经理交给的任务" << endl;
}

// get dept name
string Employee::getDeptName()
{
    return string("员工");
}

Employee::~Employee(){
    // cout << "Employee 析构函数被调用" << endl;
}