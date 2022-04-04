#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>


class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }

    string m_name;
    int m_score; // avg score
};

void createPerson(vector<Person> &v)
{
    string name_seed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += name_seed[i];
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 将评委分数放入deque容器
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score = rand()%41 + 60; // 60 ~ 100
            d.push_back(score);
        }
        // cout << "选手： " << it->m_name << " score: " << endl;
        // for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        //     cout << *dit << " ";
        // }
        // cout << endl;

        // sort
        sort(d.begin(), d.end());
        // rm highest and lowest score
        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();

        it->m_score = avg;

    }
}


void showScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << it->m_name << " avg score: " << it->m_score << endl;
    }
}


int main()
{

    srand( (unsigned int) time(NULL));
    // 1. 创建5名选手
    vector<Person> v;
    createPerson(v);
    // test
    // for (vector<Person>::iterator it=v.begin(); it!=v.end(); it++)
    // {
    //     cout << "name: " << (*it).m_name << " score: " << (*it).m_score << endl;
    // }

    // 2. 给5个人打分
    setScore(v);
    showScore(v);

    // 3. 显示最后得分
}