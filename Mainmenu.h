#include <iostream>
#include "admin.h"
#include "user.h"
using namespace std;
void admin()
{ // ����Ա�˵�

    string choice; // ѡ��
    while (1)
    {
        system("cls");
        // �鿨��ʲô����˭�����ſ���

        std::cout << "---------------------------\n1.��ӿ�\n2.��ѯ��\n3.��ֵ\n4.��ѯ���Ѽ�¼\n5.�˷�\n6.��ѯͳ��\n7.ע����\n0.�˳�\n---------------------------\n";
        std::cout << "��������ѡ�����ţ�\n";
        std::cin >> choice;
        if (choice.length() > 1)
        {
            std::cout << "�������\n";
            system("pause");
            continue;
        }
        switch (choice[0])
        {
        case '1':
            /* code */
            break;
        case '2':
            /* code */
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
            goto adminEnd;
            break;
        default:
            std::cout << "�������\n";
            system("pause");
        }
    }
adminEnd:;
    std::cout << "����Ա,��ӭ�ٴ�ʹ��";
    system("pause");
    return;
}
void user()
{ // �û��˵�
    string choice;
    while (1)
    {
        system("cls");
        std::cout << "---------------------------\n1.�ϻ�\n2.�»�\n3.��ѯ��\n4.��ֵ\n5.��ѯ���Ѽ�¼\n6.��ѯͳ��\n7.ע����\n0.�˳�\n---------------------------\n";
        std::cout << "��������ѡ�����ţ�\n";
        std::cin >> choice;
        if(choice.length()>1)
        {
            std::cout << "�������\n";
            system("pause");
            continue;
        }
        switch (choice[0])
        {
        case '1':

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
            std::cout << "�������\n";
            system("pause");
            // break;
        }
    }
userEnd:;
    std::cout << "��ӭ�ٴ�ʹ��\n";
    system("pause");
    return;
}
void secure(string op)
{
    if (op == "�û�" || op == "1")
    {
        cout << "��ӭ����Ʒѹ���ϵͳ";
        user();
    }
    else if (op == "����" || op == "2")
    {
        cout << "���������룺\n";
        string passwd;
        cin >> passwd;
        if (passwd == "114514")
            cout << "��ӭ�����̨����ϵͳ\n";
        admin();
    }
    else
    {
        cout << "wrong";
    }
}