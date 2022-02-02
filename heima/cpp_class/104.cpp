#include <iostream>
using namespace std;
#include "104_cube.h"

// class Cube
// {
// private:
//     int m_l;
//     int m_w;
//     int m_h;

// public:
//     // 行为
//     void set_l(int l)
//     {
//         m_l = l;
//     }
//     void set_w(int w)
//     {
//         m_w = w;
//     }
//     void set_h(int h)
//     {
//         m_h = h;
//     }

//     int get_l()
//     {
//         return m_l;
//     }
//     int get_w()
//     {
//         return m_w;
//     }
//     int get_h()
//     {
//         return m_h;
//     }

//     int calculate_s()
//     {
//         return 2 * (m_l * m_w + m_l * m_h + m_h * m_w);
//     }

//     int calculate_v()
//     {
//         return m_l * m_w * m_h;
//     }

//     // 利用成员函数判断立方体是否相等
//     bool isSameByClass(Cube &c)
//     {
//         if (m_l == c.get_l() && m_w == c.get_w() && m_h == c.get_h())
//         {
//             return true;
//         }
//         return false;
//     }
// };

// 利用全局函数判断两个立方体是否相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w() && c1.get_h() == c2.get_h())
    {
        return true;
    }
    return false;
}

int main()
{
    Cube c1;
    c1.set_l(10);
    c1.set_w(10);
    c1.set_h(10);
    cout << "c1 面积: " << c1.calculate_s() << endl;
    cout << "c1 体积: " << c1.calculate_v() << endl;

    Cube c2;
    c2.set_l(10);
    c2.set_w(10);
    c2.set_h(10);

    // 利用全局函数判断
    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "c1 c2 相等" << endl;
    }
    else
    {
        cout << "c1 c2 不相等" << endl;
    };

    // 利用成员函数判断
    ret = c1.isSameByClass(c2);
        if (ret)
    {
        cout << "成员函数判断 c1 c2 相等" << endl;
    }
    else
    {
        cout << "成员函数判断 c1 c2 不相等" << endl;
    };

}
