
#include<bits/stdc++.h>
using namespace std;
struct Card{
    char aName[20];
    char aPwd[20];
    int nStatus=0; // 0δ�ϻ�1�ϻ�  2��ע��3ʧЧ������
    time_t tStart, tEnd;
    float fTotaluse=0; // �ۼƽ��
    float nowmoney=0;  // ��ǰ���
    time_t tlast;
    int nUseCount=0;
    float fBalance=0;
    int nDel=0;
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
}opcard;
vector<Card> cards;
int login()//��������д��admin��˵
/* {
    cout << "�������û�����";
    cin >> opcard.aName;
    cout << "���������룺";
    cin >> opcard.aPwd;
    if ((find(cards.begin(), cards.end(), [](const Card &s)
              { return s.aName == opcard.aName && s.aPwd == opcard.aPwd; })) == cards.end())
    {
        cout << "�û������������\n";
        system("pause");
        return 0;
    }
    return 1;
} */
{

    cout << "�������û�����";
    cin >> opcard.aName;
#ifdef USER
#endif
}
void logout()
{
    opcard.clear();
}
void addcard()
{
    cout << "�������û�����";
    cin >> opcard.aName;
    cout << "���������룺";
    cin >> opcard.aPwd;
#ifndef USER // �û�Ĭ��Ϊ0Ԫ������Ա�����Զ���
    cout << "�������";
    cin >> opcard.nowmoney;
#else opcard.nowmoney = 0;
#endif
    cards.push_back(opcard);
    cout << "��ӳɹ�\n";
    auto it=cards.end()-1;
    cout << "��ǰ��" << it->nowmoney << endl;
        cout << "״̬��" << it->nStatus << endl;
        cout << "��ʼʱ�䣺" << it->tStart << endl;
        cout << "����ʱ�䣺" << it->tEnd << endl;
        cout << "�ۼƽ�" << it->fTotaluse << endl;
        cout << "�ϴ�ʹ��ʱ�䣺" << it->tlast << endl;
        cout << "ʹ�ô�����" << it->nUseCount << endl;
        cout << "��" << it->fBalance << endl;
        cout << "�Ƿ�ע����" << it->nDel << endl;
    system("pause");
}
void removecard()
{
}
void checkcard()
{kahao2:;
if(cards.size()==0){cout<<"�޿���Ϣ\n";system("pause");return ;}
    cout << "�������û�����";
    cin >> opcard.aName;
   // cout << "���������룺";
    //cin >> opcard.aPwd;
    
    auto it=find_if(cards.begin(), cards.end(), [](const Card &s)
              { return s.aName == opcard.aName ; });
    if (it == cards.end()+1){
        cout << "�û������������\n";goto kahao2;
              }
    else
    {it--;
       // cout << "�û�����" << it->aName << endl;
       // cout << "���룺" << it->aPwd << endl;
        cout << "��ǰ��" << it->nowmoney << endl;
        cout << "״̬��" << it->nStatus << endl;
        cout << "��ʼʱ�䣺" << it->tStart << endl;
        cout << "����ʱ�䣺" << it->tEnd << endl;
        cout << "�ۼƽ�" << it->fTotaluse << endl;
        cout << "�ϴ�ʹ��ʱ�䣺" << it->tlast << endl;
        cout << "ʹ�ô�����" << it->nUseCount << endl;
        cout << "��" << it->fBalance << endl;
        cout << "�Ƿ�ע����" << it->nDel << endl;
    }
    system("pause");
}
void editmoney(int a)
{ // 1Ϊ��ֵ/���ѣ�2Ϊ�˷�
kahao:;
    cout << "�������û�����";
    cin >> opcard.aName;
    cout << "���������룺";
    cin >> opcard.aPwd;
    auto it=find_if(cards.begin(), cards.end(), [](const Card &s)
              { return s.aName == opcard.aName && s.aPwd == opcard.aPwd; });
    //if (it == cards.end()+1){
      //  cout << "�û������������\n";goto kahao;
        //      }
}
void checkhistory()
{ // ��������ʷ
}
void checkmoney()
{ // �����
}