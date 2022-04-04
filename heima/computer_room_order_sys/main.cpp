#include <iostream>
using namespace std;

int main()
{
    int select = 0;
    while (true)
    {
        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;
        switch (select)
        {
        case 1: // student
            break;
        case 2: // teacher
            break;
        case 3: // admin
            break;
        case 0: // exit
            cout << "欢迎下一次使用!" << endl;
            return 0;
            break;
        default:
            cout << "input error, please choose again!" << endl;
            break;
        }
    }

    return 0;
}