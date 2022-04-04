#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>


// 设计演讲管理类
class SpeechManager
{
    public:

    // 构造函数
    SpeechManager();

    // show menu
    void show_menu();


    // exit
    void exit_sys();

    // 析构函数
    ~SpeechManager();

    // 初始化属性和容器
    void init_speech();

    // 创建12名选手
    void create_speaker();

    // 开始比赛
    void start_speech();

    // 抽签
    void speech_draw();

    // 比赛
    void speech_contest();

    // 展示分数
    void show_score();

    // 保存记录
    void save_record();

    // 读取记录
    void load_record();

    // 显示往届得分
    void show_record();

    // 清空记录
    void clear_record();

    // 成员属性
    vector<int> v1;  // 第一轮比赛选手编号

    vector<int> v2;  // 第一轮晋级选手编号

    vector<int> v_victory;  // 胜出前三名选手编号

    map<int, Speaker> m_speaker;  // 编号以及对应具体选手容器

    int m_index;  // 比赛轮数

    bool file_is_empty;  // 文件为空的标志

    map<int, vector<string> > m_record;  // 往届记录

};