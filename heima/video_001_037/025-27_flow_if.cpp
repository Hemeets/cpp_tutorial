#include<iostream>
using namespace std;


int main() {
    cout << "hello world!" << endl;

    int score = 0;
    cout << "请输入分数" << endl;
    cin >> score;
    cout << "score = " << score << endl;

    // if (score > 600)
    // {
    //     cout << "恭喜" << endl;
    // }
    // else
    // {
    //     cout << "未考上" << endl;
    // }
    
    if (score > 600)
    {
        cout << "congratulation" << endl;
        if (score > 700)
        {
            cout << "pku congratulation" << endl;
        }
        else if (score > 650)
        {
            cout << "thu congratulation" << endl;
        }
        else
        {
            cout << "renming cng" << endl;
        }
        

    }
    else if (score > 500)
    {
        cout << "congratulation 2" << endl;
    }
    else if (score > 400)
    {
        cout << "congratulation 3" << endl;
    }
    else
    {
        cout << "sorry" << endl;
    }
    


    
    return 0;
}