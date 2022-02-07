#include "boss.h"


Boss::Boss(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

// show personal info
void Boss::showInfo()
{
    cout << "职工编号： " << this->m_Id
         << "\t职工姓名： " << this->m_Name
         << "\t岗位： " << this->getDeptName()
         << "\t岗位职责：管理公司所有的事务" << endl;
}

// get dept name
string Boss::getDeptName()
{
    return string("总裁");
}


Boss::~Boss(){
    // cout << "Boss 析构函数被调用" << endl;
}