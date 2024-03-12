
#include "admin.h"
using namespace std;
/* struct Card
{
    char aName[20];
    char aPwd[20];
    int nStatus; // 0未上机1上机  2已注销3失效（？）
    time_t tStart, tEnd;
    float fTotaluse; // 累计金额
    time_t tlast;
    int nUseCount;
    float fBalance;
    float nowmoney; // 当前余额
    int nDel;
    void clear()
    {
        memset(aName, 0, sizeof(aName));
        memset(aPwd, 0, sizeof(aPwd));
        nStatus = 0;
        tStart = 0;
        tEnd = 0;
        fTotaluse = 0;
        tlast = 0;
        nUseCount = 0;
        fBalance = 0;
        nDel = 0;
    }
}; */
void admin()
{ // 管理员菜单

    string choice; // 选择
    while (1)
    {
        system("cls");
        // 查卡是什么？查谁拿哪张卡吗？

        cout << "---------------------------\n1.添加卡\n2.查询卡\n3.充值\n4.查询消费记录\n5.退费\n6.查询统计\n7.注销卡\n0.退出\n---------------------------\n";
        cout << "请输入你选择的序号：\n";
        cin >> choice;
        if (choice.length() > 1)
        {
            cout << "输入错误，\n";
            system("pause");
            continue;
        }
        // if(!login()){system("cls");cout<<"请重试\n";}
        // 管理员不用管密码，可以直接操作卡
        switch (choice[0])
        {
        case '1':
            addcard();
            break;
        case '2':
            checkcard();
            break;
        case '3':
            editmoney(1);
            break;
        case '4':
            checkhistory();
            break;
        case '5':
            editmoney(2);
            break;
        case '6':
            checkhistory();
            break;
        case '7':
            removecard();
            break;
        case '0':
            goto adminEnd;
            break;
        default:
            cout << "输入错误，\n";
            system("pause");
        }
    }
adminEnd:;
    cout << "管理员,欢迎再次使用";
    system("pause");

    return;
}
void user()
{ // 用户菜单
#define USER USER
    string choice;
    while (1)
    {
        system("cls");
        cout << "---------------------------\n1.上机\n2.下机\n3.查询卡\n4.充值\n5.查询消费记录\n6.查询统计\n7.注销卡\n0.退出\n---------------------------\n";
        cout << "请输入你选择的序号：\n";
        cin >> choice;
        if (choice.length() > 1)
        {
            cout << "输入错误，\n";
            system("pause");
            continue;
        }
        switch (choice[0])
        {
        case '1':
            login();
            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':

            break;
        case '7':

            break;
        case '0':
            goto userEnd;
            break;
        default:
            cout << "输入错误，\n";
            system("pause");
            // break;
        }
    }
userEnd:;
    cout << "欢迎再次使用\n";
    system("pause");
#undef USER
    return;
}
void secure(string op)
{
    if (op == "用户" || op == "1")
    {
        cout << "欢迎进入计费管理系统";
        user();
    }
    else if (op == "管理" || op == "2")
    {
        cout << "请输入密码：\n";
        string passwd;
        cin >> passwd;
        if (passwd == "114514")
            cout << "欢迎进入后台管理系统\n";
        admin();
    }
    else
    {
        cout << "wrong";
    }
}