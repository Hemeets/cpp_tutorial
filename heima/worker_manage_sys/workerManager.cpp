#include "workerManager.h"

WorkerManager::WorkerManager()
{
    // 1. 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // read file
    if (!ifs.is_open())
    {
        cout << "file not exist!" << endl;
        // 初始化属性
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FIleIsEmpty = true;
        ifs.close();
        return;
    }
    // 2. 文件存在 数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // 文件为空
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FIleIsEmpty = true;
        ifs.close();
        return;
    }
    // 3. 文件存在，并记录数据
    int num = this->get_EmpNum();
    cout << "职工人数为： " << num << endl;
    this->m_EmpNum = num;
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中数据存到数组中
    this->init_Emp();
    // // 测试代码
    // for (int i=0; i<this->m_EmpNum; i++)
    // {
    //     cout << "index: " << this->m_EmpArray[i]->m_Id
    //          << " name: " << this->m_EmpArray[i]->m_Name
    //          << " did: " << this->m_EmpArray[i]->m_DeptId << endl;
    // }
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
    exit(0); // 退出程序
}

// 添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加的职工的数量： " << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // add
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;
        // 开辟新空间
        Worker **newSpace = new Worker *[newSize];
        // 将原来空间下数据，拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // 添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dselect;
            cout << "请输入第" << i + 1 << " 个新职工编号：" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << " 个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择职工岗位：" << endl;
            cout << "1. 普通职工" << endl;
            cout << "2. 经理" << endl;
            cout << "3. 老板" << endl;
            cin >> dselect;

            Worker *worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            // 将创建职工职责，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }
        // 释放原有空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新职工人数
        this->m_EmpNum = newSize;

        // 更新文件不为空
        this->m_FIleIsEmpty = false;
        // 成功添加后保存到文件
        this->save();

        // 提示添加成功
        cout << "成功添加" << addNum << "名职工" << endl;
    }
    else
    {
        cout << "input error" << endl;
    }
}

// 保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 用输出方式打开，即写文件
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}

// 统计文件中的人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
};

// 初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if (did == 1)
        {
            worker = new Employee(id, name, did);
        }
        else if (did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

// 显示职工
void WorkerManager::Show_Emp()
{
    // 判断文件是否为空
    if (this->m_FIleIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
}

// 删除职工
void WorkerManager::Del_Emp()
{
    if (this->m_FIleIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入要删除的职工的编号" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--; // 更新数组中记录人员个数
            this->save();     // 数据同步到文件中
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
}

// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

// 修改职工
void WorkerManager::Mod_Emp()
{
    if (this->m_FIleIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入修改职工编号" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];
            int newid = 0;
            string newname = "";
            int dselect = 0;

            cout << "查到： " << id << "号职工， 请输入新的职工号" << endl;
            cin >> newid;
            cout << "请输入新姓名: " << endl;
            cin >> newname;
            cout << "请输入岗位: " << endl;
            cout << "1. 普通职工" << endl;
            cout << "2. 经理" << endl;
            cout << "3. 老板" << endl;
            cin >> dselect;

            Worker *worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(newid, newname, 1);
                break;
            case 2:
                worker = new Manager(newid, newname, 2);
                break;
            case 3:
                worker = new Boss(newid, newname, 3);
                break;
            default:
                break;
            }

            // 更新到数组中
            this->m_EmpArray[ret] = worker;
            cout << "修改成功！" << endl;
            this->save(); // 保存到文件
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
}

// 查找职工
void WorkerManager::Find_Emp()
{
    if (this->m_FIleIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        cout << "请输入查找到方式：" << endl;
        cout << "1. 按职工编号查找" << endl;
        cout << "2. 按职工姓名查找" << endl;

        int select = 0;
        cin >> select;
        if (select == 1)
        {
            int id;
            cout << "please input worker index: " << endl;
            cin >> id;
            int ret = IsExist(id);
            if (ret != -1)
            {
                cout << "find successfully, worker info: " << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "find fail, no this person" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "please input name: " << endl;
            cin >> name;
            bool flag = false; // default not find worker
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    cout << "find name successfully" << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "find fail , no this person" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
}


// 排序职工
void WorkerManager::Sort_Emp()
{
    if (this->m_FIleIsEmpty)
    {
        cout << "file not exist or record is empty" << endl;
    }
    else
    {
        cout << "please choose sort type: " << endl;
        cout << "1. ascend by index" << endl;
        cout << "2. descend by index" << endl;
        int select = 0;
        cin >> select;
        for (int i=0; i < this->m_EmpNum; i++)
        {
            int minormax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if (select == 1)
                {
                    if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        minormax = j;
                    }
                }
                else
                {
                    if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id)
                    {
                        minormax = j;
                    }
                }
            }
            if (i != minormax)
            {
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minormax];
                this->m_EmpArray[minormax] = temp;
            }

        }
        cout << "sort successfully, result is:" << endl;
        this->save();
        this->Show_Emp();

    }
}


// 情况文件
void WorkerManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1. 确定" << endl;
    cout << "2. 返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs (FILENAME, ios::trunc);  // 删除文件后重新创建，即清空操作
        ofs.close();
        if (this->m_EmpArray != NULL)
        {
            // 删除堆区的每个职工对象
            for (int i=0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
            delete [] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FIleIsEmpty = true;
        }
        cout << "清空成功" << endl;
    }

}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}