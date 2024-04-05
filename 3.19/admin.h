#include <bits/stdc++.h>
using namespace std;
struct Card
{
    char aName[20];
    char aPwd[20];
    int nStatus = 0; // 0未上机1上机  2已注销3失效（？）
    time_t tStart, tEnd;
    float fTotaluse = 0; // 累计金额
    float nowmoney = 0;  // 当前余额
    time_t tlast;
    int nUseCount = 0;
    float fBalance = 0;
    int nDel = 0;
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
};
struct node
{
    Card data;
    node *next;

    void push_back(Card c)
    {
        node *newNode = new node;
        newNode->data = c;
        newNode->next = NULL;

        node *current = this;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    void remove(Card c)
    {
        node *p = this;
        while (p->next != NULL)
        {
            if (p->next->data.aName == c.aName)
            {
                node *temp = p->next;
                p->next = p->next->next;
                delete temp;
                return;
            }
            p = p->next;
        }
    }

    /* void clear()
    {
        data = Card();
        next = NULL;
    } */
};

Card opcard;
extern node head;
extern node *tail;
extern node *current;
// extern (vector<Card> cards;
void login();
/*void login() // 不急，先写完admin再说
 {
    cout << "请输入用户名：";
    cin >> opcard.aName;
    cout << "请输入密码：";
    cin >> opcard.aPwd;
    if ((find(cards.begin(), cards.end(), [](const Card &s)
              { return s.aName == opcard.aName && s.aPwd == opcard.aPwd; })) == cards.end())
    {
        cout << "用户名或密码错误\n";
        system("pause");
        return 0;
    }
    return 1;
} 
{

    cout << "请输入用户名：";
    cin >> opcard.aName;
#ifdef USER
#endif
}
 */
void logout()
{
    opcard.clear();
    free(current);
}

void addcard()
{
    cout << "请输入用户名：";
    cin >> opcard.aName;
    cout << "请输入密码：";
    cin >> opcard.aPwd;
#ifndef USER // 用户默认为0元，管理员可以自定义
    cout << "请输入金额：";
    cin >> opcard.nowmoney;
#else
    opcard.nowmoney = 0;
#endif
    head.push_back(opcard);
    current = current->next;
    cout << "添加成功\n";
    // auto it = cards.end() - 1;
    /* cout << "当前余额：" << it->nowmoney << endl;
    cout << "状态：" << it->nStatus << endl;
    cout << "开始时间：" << it->tStart << endl;
    cout << "结束时间：" << it->tEnd << endl;
    cout << "累计金额：" << it->fTotaluse << endl;
    cout << "上次使用时间：" << it->tlast << endl;
    cout << "使用次数：" << it->nUseCount << endl;
    cout << "余额：" << it->fBalance << endl;
    cout << "是否注销：" << it->nDel << endl; */
    cout << "当前余额" << current->data.nowmoney << endl;
    cout << "当前状态" << current->data.nStatus << endl;
    cout << "开始时间" << current->data.tStart << endl;
    cout << "结束时间" << current->data.tEnd << endl;
    cout << "累计金额" << current->data.fTotaluse << endl;
    cout << "上次使用时间" << current->data.tlast << endl;
    cout << "使用次数" << current->data.nUseCount << endl;
    cout << "余额" << current->data.fBalance << endl;
    cout << "是否注销" << current->data.nDel << endl;
    system("pause");
}
void removecard()
{
}
void checkcard()
{
kahao2:
    system("pause");

    opcard.clear();

    /* if (head.empty())
    {
        cout << "无卡信息\n";
        system("pause");
        return;
    } */
    current = &head;
    cout << "请输入用户名：";
    cin >> opcard.aName;
    do
    {
        if (current->data.aName == opcard.aName)
        {
            break;
        }
        else
        {
            current = current->next;
        }
    } while (current->next != NULL);
    if (current->data.aName != opcard.aName)
    {
        cout << "没有找到该用户" << endl;
        goto kahao2;
    }
    // 判断是否没找到

    cout << "请输入密码：";
    cin >> opcard.aPwd;

    /* auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return s.aName == opcard.aName; }); */
    if (strcpy(opcard.aPwd, current->data.aPwd))
    {
        cout << "密码错误\n";
        goto kahao2;
    }
    else
    {
        // it--;
        //  cout << "用户名：" << it->aName << endl;
        //  cout << "密码：" << it->aPwd << endl;
        cout << "当前余额" << current->data.nowmoney << endl;
        cout << "当前状态" << current->data.nStatus << endl;
        cout << "开始时间" << current->data.tStart << endl;
        cout << "结束时间" << current->data.tEnd << endl;
        cout << "累计金额" << current->data.fTotaluse << endl;
        cout << "上次使用时间" << current->data.tlast << endl;
        cout << "使用次数" << current->data.nUseCount << endl;
        cout << "余额" << current->data.fBalance << endl;
        cout << "是否注销" << current->data.nDel << endl;
    }
    system("pause");
}
void editmoney(int a)
{ // 1为充值/消费，2为退费
/* kahao:;
    cout << "请输入用户名：";
    cin >> opcard.aName;
    cout << "请输入密码：";
    cin >> opcard.aPwd;
    auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return s.aName == opcard.aName && s.aPwd == opcard.aPwd; });
    // if (it == cards.end()+1){
    //   cout << "用户名或密码错误\n";goto kahao;
    //       } */
}
void checkhistory()
{ // 查消费历史
}
void checkmoney()
{ // 查余额
}