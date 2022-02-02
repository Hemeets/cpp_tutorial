#include <iostream>
using namespace std;

// 设计一个圆类，求圆的周长
// 2 * pi * 半径

const double PI = 3.14;

class Circle
{
    // 访问权限：公共权限
public:

    // 属性
    int m_r;

    // 行为
    double calculate_zc()
    {
        return 2 * PI * m_r;
    }
};

int main()
{
    Circle c1;
    c1.m_r = 10;

    cout << "圆周长为: " << c1.calculate_zc() << endl;
}