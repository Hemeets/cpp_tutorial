#pragma once
#include <iostream>

class Cube
{
private:
    int m_l;
    int m_w;
    int m_h;

public:
    // 行为
    void set_l(int l);

    void set_w(int w);

    void set_h(int h);

    int get_l();

    int get_w();

    int get_h();

    int calculate_s();

    int calculate_v();

    // 利用成员函数判断立方体是否相等
    bool isSameByClass(Cube &c);

};