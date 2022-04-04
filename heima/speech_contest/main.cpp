#include <iostream>
using namespace std;
#include "speech_manager.h"
#include <ctime>


int main()
{

    //rand
    srand((unsigned int)time(NULL));
    // create obj
    SpeechManager sm;

    // test create speaker
    // for (map<int, Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
    // {
    //     cout << "选手编号: " << it->first << " name: " << it->second.m_name << " score: " << it->second.m_score[0] << endl;
    // }

    int choice = 0;
    while (true)
    {
        sm.show_menu();
        cout << "输入选择" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1: // 开始
                sm.start_speech();
                break;
            case 2: // 查看记录
                // sm.load_record();
                sm.show_record();
                break;
            case 3:  // 清空记录
                sm.clear_record();
                break;
            case 0:
                sm.exit_sys();
                break;
            default:
                break;
        }
    }

    // cout << "hello" << endl;
    return 0;
}