#include <bits/stdc++.h>
#include "admin.h"
using namespace std;
vector<string> passwords;
void admin()
{ // 管理员菜单

    string choice; // 选择
    while (1)
    {
        system("cls");
        // 查卡是什么？查谁拿哪张卡吗？

        cout << "---------------------------\n1.添加卡\n2.查询卡\n3.充值\n4.查询消费记录\n5.退费\n6.查询统计\n7.注销卡\n8.修改密码\n9.手动保存\n0.退出\n---------------------------\n";
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
            addcard(0);
            break;
        case '2':
            checkcard(0);
            break;
        case '3':
            editmoney(1, 0); // 1加钱
            break;
        case '4':
            checkhistory(0);
            break;
        case '5':
            editmoney(2, 0); // 2扣钱
            break;
        case '6':
            checkhistory(0);
            break;
        case '7':
            removecard(0);
            break;
        case '8':
            passwdchange();
            break;
        case '9':
            manualsave();
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
    string choice;
    while (1)
    {
        system("cls");
        cout << "---------------------------\n1.上机\n2.下机\n3.查询卡\n4.充值\n5.查询消费记录\n6.查询统计\n7.注销卡\n8.新建卡\n0.退出\n---------------------------\n";
        cout << "请输入你选择的序号：\n";
        cin.clear();
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
            logout();
            break;
        case '3':
            checkcard(1);
            break;
        case '4':
            editmoney(1, 1);
            break;
        case '5':
            checkhistory(1);
            break;
        case '6':

            break;
        case '7':
            removecard(1);
            break;
        case '8':
            addcard(1);
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
adminbegin:;
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
        // 密码验证
       

       //没写文件解析

        bool flag = 1;//！
        for (auto i : passwords)
        {
            cout << i << endl;
            if (i == passwd)
            {
                break;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            cout << "欢迎进入后台管理系统\n";
            system("pause");
            system("cls");
            admin();
        }
        else
        {
            cout << "密码错误";
            system("pause");
            system("cls");
            goto adminbegin;
        }
    }
}
