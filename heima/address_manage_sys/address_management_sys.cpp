// - 封装函数显示该界面 如void showMenu()
// - 在main 函数中调用封装好的函数
#include <iostream>
#include <unistd.h> // mac 中 pause 需引用这个
#include <string>
using namespace std;
#define MAX 1000

// 设计联系人的结构体
struct Person
{
    string m_Name;  // 姓名
    int m_Sex;      // 1. 男  2. 女
    int m_Age;      // 年龄
    string m_Phone; // 电话
    string m_Addr;  // 住址
};

// 设计通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX]; // 通讯录中保存的联系人数组
    int m_Size;                     // 通讯录中当前记录联系人个数
};

// 1. 添加联系人
void addPerson(Addressbooks *abs)
{
    // 判断通讯录是否已满，如果满了就不再添加
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加!" << endl;
        return;
    }
    else
    {
        //添加具体联系人
        // 姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 性别
        cout << "请输入性别: " << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2) // 如果输入是1或2可以退出循环
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入!" << endl;
        }

        // 年龄
        cout << "请输入年龄: " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 电话
        cout << "请输入联系电话: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 住址
        cout << "请输入家庭住址: " << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // 更新通讯录人数
        abs->m_Size++;
        cout << "添加成功!" << endl;

        // pause();
        // system("clear"); // 清屏操作
    }
}

// 2. 显示所有联系人
void showPerson(struct Addressbooks *abs)
{
    // 判断通讯录中人数是否为0，如果为0，提示记录结果为空
    // 如果不为0，显示记录的联系人信息
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空!" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "name: " << abs->personArray[i].m_Name << "\t";
            cout << "sex: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "age: " << abs->personArray[i].m_Age << "\t";
            cout << "phone: " << abs->personArray[i].m_Phone << "\t";
            cout << "address: " << abs->personArray[i].m_Addr << endl;
        }
    }
    // system("clear");
}

// 检测联系人是否存在，存在返回具体位置，不存在返回-1
int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 找到输入name
        if (abs->personArray[i].m_Name == name)
        {
            cout << "找到此人!" << endl;
            return i; // 找到了，返回该name的索引下标
        }
    }
    return -1;
}

// 3. 删除指定联系人
void deletePerson(Addressbooks *abs)
{
    cout << "请输入要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            // 数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功!" << endl;
    }
    else
    {
        cout << "查无此人!" << endl;
    }
}

// 4. 查找联系人
void findPerson(Addressbooks *abs)
{
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
        cout << "性别: " << abs->personArray[ret].m_Sex << "\t";
        cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
        cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
        cout << "地址: " << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人!" << endl;
    }
}

// 5. 修改联系人
void modifyPerson(Addressbooks *abs)
{
    cout << "请输入要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        // name
        string name;
        cout << "please input name: " << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        // sex
        cout << "please input sex: " << endl;
        cout << "1---male" << endl;
        cout << "2---female" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "input error, please input again!" << endl;
        }

        // age
        cout << "please input age: " << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;

        // phone
        cout << "please input phone num: " << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        // address
        cout << "please input address: " << endl;
        string addr;
        cin >> addr;
        abs->personArray[ret].m_Addr = addr;

    }
    else
    {
        cout << "查无此人!" << endl;
    }
}

// 6. 清空联系人
void cleanPerson(Addressbooks *abs)
{
    abs->m_Size = 0;  // 将当前记录联系人数量置为0，做逻辑清空操作
    cout << "通讯录已清空!" << endl;

}

// 菜单界面
void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "*************************" << endl;
}

int main()
{

    // 创建通讯录结构体变量
    Addressbooks abs;
    // 初始化通讯录中当前人员个数
    abs.m_Size = 0;

    int select = 0; // 创建用户选择输入的变量

    while (true)
    {
        // 菜单调用
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: // 1. 添加联系人
            addPerson(&abs);
            break;
        case 2: // 2. 显示联系人
            showPerson(&abs);
            break;
        case 3: // 3. 删除联系人
            deletePerson(&abs);
            break;
        case 4: // 4. 查找联系人
            findPerson(&abs);
            break;
        case 5: // 5. 修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 6. 清空联系人
            cleanPerson(&abs);
            break;
        case 0: // 0. 退出通讯录
            cout << "欢迎下次使用!" << endl;
            return 0;
            break;
        default:
            break;
        }
    }

    // pause();
}