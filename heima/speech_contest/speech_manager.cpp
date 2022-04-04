#include "speech_manager.h"

// 构造函数
SpeechManager::SpeechManager()
{
    // init
    this->init_speech();

    // 创建12名选手
    this->create_speaker();

    // load
    this->load_record();
}

// show menu
void SpeechManager::show_menu()
{
    cout << "***" << endl;
    cout << "欢迎参加演讲比赛" << endl;
    cout << "1. 开始；2. 查看往届记录；3. 清空比赛记录；0. 退出比赛程序" << endl;
    cout << "***" << endl;
    cout << endl;
}

// exit
void SpeechManager::exit_sys()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

// 析构函数
SpeechManager::~SpeechManager()
{
}

void SpeechManager::init_speech()
{
    // 容器都置空
    this->v1.clear();
    this->v2.clear();
    this->v_victory.clear();
    this->m_speaker.clear();
    this->m_index = 1;
    this->m_record.clear();
}

// 创建12名选手
void SpeechManager::create_speaker()
{
    string name_seed = "ABCDEFGHIJKL";
    for (int i = 0; i < name_seed.size(); i++)
    {
        string name = "选手";
        name += name_seed[i];
        Speaker sp;
        sp.m_name = name;
        for (int j = 0; j < 2; j++)
        {
            sp.m_score[j] = 0;
        }

        // 创建选手编号，并且放入到v1容器中
        this->v1.push_back(i + 10001);
        // 选手编号以及对应选手放入到map容器中
        this->m_speaker.insert(make_pair(i + 10001, sp));
    }
}

// 开始比赛
void SpeechManager::start_speech()
{
    // epoch 1

    // 1. 抽签
    this->speech_draw();

    // 2. 比赛
    this->speech_contest();

    // 3. 显示晋级结果
    this->show_score();

    // epoch 2
    this->m_index++;

    // 1. 抽签
    this->speech_draw();

    // 2. 比赛
    this->speech_contest();

    // 3. 显示最终结果
    this->show_score();

    // 4. 保存分数到文件中
    this->save_record();

    // 重置比赛
    // init
    this->init_speech();
    // 创建12名选手
    this->create_speaker();
    // load
    this->load_record();

    cout << "本届比赛完毕" << endl;
}

void SpeechManager::speech_draw()
{
    cout << "epoch " << this->m_index << " 选手正在抽签" << endl;
    cout << "----------------" << endl;
    cout << "抽签后演讲顺序如下： " << endl;
    if (this->m_index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

void SpeechManager::speech_contest()
{
    cout << "第 " << this->m_index << "比赛正式开始" << endl;

    // 用临时容器存小组成绩
    multimap<double, int, greater<double> > group_score;
    int num = 0; // 记录人员个数

    vector<int> v_src; // 比赛选手容器
    if (this->m_index == 1)
    {
        v_src = v1;
    }
    else
    {
        v_src = v2;
    }
    // 遍历所有选手进行比赛
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f; // 600~1000
            // cout << score << " ";
            d.push_back(score);
        }
        // cout << endl;
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front(); // 去除最高分
        d.pop_back();  // 去除最低分
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double)d.size(); // 除以整数是整数，所以要转成double

        // 将平均分放入到map容器中
        this->m_speaker[*it].m_score[this->m_index - 1] = avg;
        // cout << "index: " << *it << " name: " <<
        //      this->m_speaker[*it].m_name << " avg: " << avg << endl;

        // 打分数据放入临时小组容器中
        group_score.insert(make_pair(avg, *it)); // key 是得分，value是选手编号
        // 每6人取前三名
        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次" << endl;
            for (multimap<double, int, greater<double> >::iterator it = group_score.begin(); it != group_score.end(); it++)
            {
                cout << "index: " << it->second << " name: " << this->m_speaker[it->second].m_name
                     << " grade: " << this->m_speaker[it->second].m_score[this->m_index - 1] << endl;
            }

            // 取走前三名
            int count = 0;
            for(multimap<double, int, greater<double> >::iterator it = group_score.begin(); it != group_score.end() && count < 3; it++, count++)
            {
                if (this->m_index == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    v_victory.push_back((*it).second);
                }
            }

            group_score.clear();
            cout << endl;
        }

    }
    cout << "epoch: " << this->m_index << " contest over" << endl;
}


// 显示得分
void SpeechManager::show_score()
{
    cout << " epoch: " << this->m_index << "晋级选手信息如下：" << endl;
    vector<int> v;
    if (this->m_index==1)
    {
        v = v2;
    }
    else
    {
        v = v_victory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "index: " << *it << " name: " << this->m_speaker[*it].m_name << " score: "
            << this->m_speaker[*it].m_score[this->m_index - 1] << endl;
    }
    cout << endl;

    this->show_menu();
}


// 保存记录
void SpeechManager::save_record()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++)
    {
        ofs << *it << "," << m_speaker[*it].m_score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录已经保存" << endl;

    this->file_is_empty = false; // 更新文件不为空状态

}


void SpeechManager::load_record()
{
    ifstream ifs("speech.csv", ios::in);  //  读文件
    if (!ifs.is_open())
    {
        this->file_is_empty = true;
        cout << "file not exist" << endl;
        ifs.close();
        return;
    }

    // file clear
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "file is empty" << endl;
        this->file_is_empty = true;
        ifs.close();
        return;
    }

    // file not empty
    this->file_is_empty = false;
    ifs.putback(ch);  // 将上面读取的单个字符放回来
    string data;
    // while (ifs >> data)
    int index = 0;
    while (getline(ifs, data))
    {
        // cout << data << endl;
        vector<string> v;  // 存放字符串
        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            string temp = data.substr(start, pos - start);
            // cout << temp << endl;
            v.push_back(temp);
            start = pos + 1;
        }

        // 存放
        this->m_record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();

    // for (map<int, vector<string> >::iterator it = m_record.begin(); it != m_record.end(); it++)
    // {
    //     cout << it->first << "冠军编号: " << it->second[0]
    //         << " score: " << it->second[1] << endl;
    // }
}


// 显示往届记录
void SpeechManager::show_record()
{
    if (this->file_is_empty)
    {
        cout << "file is empty or file not exist!" << endl;
    }
    for (int i = 0; i < this->m_record.size(); i++)
    {
        cout << "第" << i + 1 << "届" << "冠军编号" << this->m_record[i][0]
            << " score: " << this->m_record[i][1] << endl;
    }
}


// clear
void SpeechManager::clear_record()
{
    cout << "确认清空？" << endl;
    cout << "1. yes" << endl;
    cout << "2. no" << endl;
    int select = 0;

    cin >> select;
    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);  // trunc 重新创建，即清空
        ofs.close();

        // init
        this->init_speech();

        // 创建12名选手
        this->create_speaker();

        // load
        this->load_record();

        cout << "清空成功" << endl;

    }
}