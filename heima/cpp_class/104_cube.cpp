#include "104_cube.h"


void Cube::set_l(int l)
{
    m_l = l;
}
void Cube::set_w(int w)
{
    m_w = w;
}
void Cube::set_h(int h)
{
    m_h = h;
}

int Cube::get_l()
{
    return m_l;
}
int Cube::get_w()
{
    return m_w;
}
int Cube::get_h()
{
    return m_h;
}

int Cube::calculate_s()
{
    return 2 * (m_l * m_w + m_l * m_h + m_h * m_w);
}

int Cube::calculate_v()
{
    return m_l * m_w * m_h;
}

// 利用成员函数判断立方体是否相等
bool Cube::isSameByClass(Cube &c)
{
    if (m_l == c.get_l() && m_w == c.get_w() && m_h == c.get_h())
    {
        return true;
    }
    return false;
}