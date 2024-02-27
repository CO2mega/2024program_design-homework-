#include <iostream>
#include<admin.h>
#include<user.h>
void will()
{
    std::cout << "还没做";
}
void admin()
{ // 管理员菜单

    int choice; // 选择
    while (1)
    {
        system("cls"); // 查卡是什么？查谁拿哪张卡吗？

        std::cout << "---------------------------\n1.添加卡\n2.查询卡\n3.充值\n4.查询消费记录\n5.退费\n6.查询统计\n7.注销卡\n8.退出\n---------------------------\n";
        std::cout << "请输入你选择的序号：\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            goto adminEnd;
            break;
        default:
            std::cout << "输入错误，请在任意键后重试\n";
            std::system("pause");
            break;
        }
    }
adminEnd:;
    std::cout << "管理员,欢迎再次使用";
    system("pause");
    return;
}

void user()
{ // 用户菜单
    int choice;
    while (1)
    {
        system("cls");
        std::cout << "---------------------------\n1.上机\n2.下机\n3.查询卡\n4.充值\n5.查询消费记录\n6.查询统计\n7.注销卡\n8.退出\n---------------------------\n";
        std::cout << "请输入你选择的序号：\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            goto userEnd;
            break;
        default:
            std::cout << "输入错误，请在任意键后重试\n";
            std::getchar();
            break;
        }
    }
userEnd:;
    std::cout << "欢迎再次使用";
    system("pause");
    return;
}

bool oper(std::string op)
{
    if (op == "用户" || op == "1")
    {
        std::cout << "欢迎进入计费管理系统";
        user();
    }
    else if (op == "管理" || op == "2")
    {
        std::cout << "请输入密码：\n";
        std::string passwd;
        std::cin >> passwd;
        if (passwd == "114514")
            std::cout << "欢迎进入后台管理系统\n";
        admin();
    }
    else
    {
        std::cout << "wrong";
        return false;
    }
}
/* void test(){
    std::cout<<114514;
}; */
// 已弃用
