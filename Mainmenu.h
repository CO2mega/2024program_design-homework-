#include <iostream>
#include<admin.h>
#include<user.h>
void will()
{
    std::cout << "��û��";
}
void admin()
{ // ����Ա�˵�

    int choice; // ѡ��
    while (1)
    {
        system("cls"); // �鿨��ʲô����˭�����ſ���

        std::cout << "---------------------------\n1.��ӿ�\n2.��ѯ��\n3.��ֵ\n4.��ѯ���Ѽ�¼\n5.�˷�\n6.��ѯͳ��\n7.ע����\n8.�˳�\n---------------------------\n";
        std::cout << "��������ѡ�����ţ�\n";
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
            std::cout << "����������������������\n";
            std::system("pause");
            break;
        }
    }
adminEnd:;
    std::cout << "����Ա,��ӭ�ٴ�ʹ��";
    system("pause");
    return;
}

void user()
{ // �û��˵�
    int choice;
    while (1)
    {
        system("cls");
        std::cout << "---------------------------\n1.�ϻ�\n2.�»�\n3.��ѯ��\n4.��ֵ\n5.��ѯ���Ѽ�¼\n6.��ѯͳ��\n7.ע����\n8.�˳�\n---------------------------\n";
        std::cout << "��������ѡ�����ţ�\n";
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
            std::cout << "����������������������\n";
            std::getchar();
            break;
        }
    }
userEnd:;
    std::cout << "��ӭ�ٴ�ʹ��";
    system("pause");
    return;
}

bool oper(std::string op)
{
    if (op == "�û�" || op == "1")
    {
        std::cout << "��ӭ����Ʒѹ���ϵͳ";
        user();
    }
    else if (op == "����" || op == "2")
    {
        std::cout << "���������룺\n";
        std::string passwd;
        std::cin >> passwd;
        if (passwd == "114514")
            std::cout << "��ӭ�����̨����ϵͳ\n";
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
// ������
