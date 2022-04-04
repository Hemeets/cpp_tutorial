#include <iostream>
using namespace std;
#include <vector>
#include <map>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class Worker
{
public:
    string m_name;
    int m_salary;
};

void create_worker(vector<Worker> &v)
{
    string name_seed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Worker worker;
        worker.m_name = "employee_";
        worker.m_name += name_seed[i];
        worker.m_salary = rand() % 10000 + 10000;
        v.push_back(worker);
    }
}

void set_group(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int dept_id = rand() % 3;  // 0 1 2
        m.insert(make_pair(dept_id, *it));
    }
}

void show_worker_by_group(multimap<int, Worker> &m)
{
    cout << "策划部分: " << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "name: " << pos->second.m_name << " salary: " << pos->second.m_salary << endl;
    }
}



int main()
{
    // 1. 创建员工
    vector<Worker> v_worker;
    create_worker(v_worker);
    for (vector<Worker>::iterator it = v_worker.begin(); it != v_worker.end(); it++)
    {
        cout << "name: " << it->m_name << "salary: " << it->m_salary << endl;
    }

    // 2. 员工分组
    multimap<int, Worker> m_worker;
    set_group(v_worker, m_worker);

    // 3. 分组显示员工
    show_worker_by_group(m_worker);

}