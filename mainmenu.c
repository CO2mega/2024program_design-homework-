
#include "admin.h"
using namespace std;
/* struct Card
{
    char aName[20];
    char aPwd[20];
    int nStatus; // 0δ�ϻ�1�ϻ�  2��ע��3ʧЧ������
    time_t tStart, tEnd;
    float fTotaluse; // �ۼƽ��
    time_t tlast;
    int nUseCount;
    float fBalance;
    float nowmoney; // ��ǰ���
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
{ // ����Ա�˵�

    string choice; // ѡ��
    while (1)
    {
        system("cls");
        // �鿨��ʲô����˭�����ſ���

        cout << "---------------------------\n1.��ӿ�\n2.��ѯ��\n3.��ֵ\n4.��ѯ���Ѽ�¼\n5.�˷�\n6.��ѯͳ��\n7.ע����\n0.�˳�\n---------------------------\n";
        cout << "��������ѡ�����ţ�\n";
        cin >> choice;
        if (choice.length() > 1)
        {
            cout << "�������\n";
            system("pause");
            continue;
        }
        // if(!login()){system("cls");cout<<"������\n";}
        // ����Ա���ù����룬����ֱ�Ӳ�����
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
            cout << "�������\n";
            system("pause");
        }
    }
adminEnd:;
    cout << "����Ա,��ӭ�ٴ�ʹ��";
    system("pause");

    return;
}
void user()
{ // �û��˵�
#define USER USER
    string choice;
    while (1)
    {
        system("cls");
        cout << "---------------------------\n1.�ϻ�\n2.�»�\n3.��ѯ��\n4.��ֵ\n5.��ѯ���Ѽ�¼\n6.��ѯͳ��\n7.ע����\n0.�˳�\n---------------------------\n";
        cout << "��������ѡ�����ţ�\n";
        cin >> choice;
        if (choice.length() > 1)
        {
            cout << "�������\n";
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
            cout << "�������\n";
            system("pause");
            // break;
        }
    }
userEnd:;
    cout << "��ӭ�ٴ�ʹ��\n";
    system("pause");
#undef USER
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