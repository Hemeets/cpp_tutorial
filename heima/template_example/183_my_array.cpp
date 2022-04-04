#include <iostream>
using namespace std;
#include "MyArray.hpp"


void print_int_array(MyArray<int> & arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray<int> arr1(5);
    // MyArray<int> arr2(arr1);
    // MyArray<int> arr3(100);
    // arr3 = arr1;
    for (int i = 0; i < 5; i++)
    {
        arr1.Push_Back(i);
    }
    cout << "arr1: " << endl;
    print_int_array(arr1);
    cout << "arr1的容量：" << arr1.getCapacity() << endl;
    cout << "arr1的大小" << arr1.getSize() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2：" << endl;
    print_int_array(arr2);
    arr2.Pop_Back();
    cout << "arr2尾删后：" << endl;
    print_int_array(arr2);
    cout << "arr2的容量：" << arr2.getCapacity() << endl;
    cout << "arr2的大小" << arr2.getSize() << endl;
}


// 测试自定义数据类型
class Person
{
public:

    Person(){}
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }


    string m_name;
    int m_age;
};

void print_person_array(MyArray<Person> & arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "name: " << arr[i].m_name << " age: " << arr[i].m_age << endl;
    }
}

void test02()
{
    MyArray<Person> arr(10);
    Person p1("孙悟空", 999);
    Person p2("韩信", 30);
    Person p3("妲己", 20);
    Person p4("赵云", 27);

    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);

    print_person_array(arr);
    cout << "arr 容量: " << arr.getCapacity() << " arr 大小： " << arr.getSize() << endl;

}


int main() {

    // test01();
    test02();

    return 0;
}