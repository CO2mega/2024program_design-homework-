#include <bits/stdc++.h>
#include "./timetool.h"
using namespace std;

template <typename T>
class Vector
{
public:
    typedef T value_type;
    typedef T *iterator;

    Vector() : _start(nullptr), _finish(nullptr), _end(nullptr) {}

    size_t size() const
    {
        return _finish - _start;
    }

    size_t capacity() const
    {
        return _end - _start;
    }

    void push_back(const value_type &x)
    {
        if (capacity() == 0 || capacity() == size())
        {
            reserve((capacity() == 0) ? 1 : capacity() * 2);
        }
        *_finish = x;
        ++_finish;
    }

    void pop_back()
    {
        if (!empty())
        {
            --_finish;
            cout << "弹出元素: " << *_finish << endl;
        }
        else
        {
            cout << "容器为空，无法弹出元素." << endl;
        }
    }

    void insert(const value_type &x, const size_t &pos)
    {
        if (pos > size())
        {
            cout << "越界: 无法在指定位置插入元素." << endl;
            return;
        }
        if (capacity() == 0)
        {
            reserve(1);
            *_finish = x;
            ++_finish;
        }
        else if (size() == capacity())
        {
            size_t size1 = size();
            size_t cap = capacity();
            value_type *tmp = new value_type[2 * capacity()]();
            for (size_t i = 0; i < pos; i++)
            {
                tmp[i] = _start[i];
            }
            tmp[pos] = x;
            for (size_t i = pos; i < size1; i++)
            {
                tmp[i + 1] = _start[i];
            }
            delete[] _start;
            _start = tmp;
            _finish = _start + size1 + 1;
            _end = _start + 2 * cap;
        }
        else
        {
            for (int i = size(); i > pos; i--)
            {
                _start[i] = _start[i - 1];
            }
            _start[pos] = x;
            _finish = _start + size() + 1;
        }
    }

    void erase(const size_t &pos)
    {
        if (pos >= 0 && pos < size())
        {
            iterator begin = _start + pos;
            while (begin != _finish)
            {
                *begin = *(begin + 1);
                ++begin;
            }
            --_finish;
            //--_end;
        }
        else
        {
            cout << "越界: 无法删除指定位置的元素" << endl;
        }
    }

    void Print()
    {
        if (empty())
        {
            cout << "容器为空." << endl;
            return;
        }
        cout << "容器元素: ";
        for (size_t i = 0; i < size(); i++)
        {
            cout << _start[i] << "  ";
        }
        cout << endl;
    }

    void reserve(size_t newCapacity)
    {
        value_type *tmp = new value_type[newCapacity]();
        size_t size1 = size();
        if (_start)
        {
            for (size_t i = 0; i < size1; i++)
            {
                tmp[i] = _start[i];
            }
        }
        delete[] _start;
        _start = tmp;
        _finish = _start + size1;
        _end = _start + newCapacity;
    }

    bool empty() const
    {
        return _start == _finish;
    }

private:
    iterator _start;
    iterator _finish;
    iterator _end;
};

struct Card
{
    char aName[20];
    char aPwd[20];
    int nStatus = 0; // 0未上机1上机  2已注销3失效（？）
    time_t tStart, tEnd;
    float fTotaluse = 0; // 累计金额
                         // float fBalance = 0;
    time_t tlast;
    int nUseCount = 0;
    float fBalance = 0; // 当前余额
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
Card opcard;
extern vector<Card> cards;
int login() 
{
loginbe:
    system("cls");
    cout << "请输入用户名：";
    cin >> opcard.aName;

    auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return strcmp(s.aName, opcard.aName) == 0; });

    if (it == cards.end())
    {
        cout << "用户名错误\n";
        goto loginbe;
    }
    else
    {
        cout << "请输入密码：";
        cin >> opcard.aPwd;
        if (strcmp(it->aPwd, opcard.aPwd) != 0)
        {
            cout << "用户名或密码错误\n";
            goto loginbe;
        }
    }
    cout << "登录成功,开始计费" << endl;
    it->nStatus = 1;
    it->tStart = time(0);
    system("pause");
    return 1;
}
/* {

    cout << "请输入用户名：";
    cin >> opcard.aName;
} */

void logout()
{

logoutbe:
    system("cls");
    cout << "请输入用户名：";
    cin >> opcard.aName;

    auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return strcmp(s.aName, opcard.aName) == 0; });

    if (it == cards.end())
    {
        cout << "用户名错误\n";
        system("pause");
        goto logoutbe;
    }
    else
    {
        cout << "请输入密码：";
        cin >> opcard.aPwd;
        if (strcmp(it->aPwd, opcard.aPwd) != 0)
        {
            cout << "用户名或密码错误\n";
            system("pause");
            goto logoutbe;
        }
    }
    cout << "登录成功" << endl;
    char *s;
    cout << "当前时间是：" << timetostr(time(0))
         << endl;
    time_t tot = time(0) - it->tStart;

    cout << "开始时间是：" << timetostr(it->tStart)
         << endl;

    cout << "使用时间：" << tot << "秒" << endl;
    cout << "确定下机吗？1.确定 2.取消" << endl;
    int a;
    cin >> a;
    if (a == 1)
    {
        it->nStatus = 0;
        cout << "下机成功,本次消费：" << tot << endl; // 每分钟0.06元
        it->fTotaluse += tot *0.001;
        it->fBalance -= tot *0.001;
        it->tlast = time(0);
        it->nUseCount++;
        cout << "当前余额：" << (it->fBalance) << endl;
        it->tStart = 0;
        it->tEnd = 0;
    }
    system("pause");
    opcard.clear();
    s = nullptr;
}

void addcard(int qua)
{
    cout << "请输入用户名：";
    cin >> opcard.aName;
    cout << "请输入密码：";
    cin >> opcard.aPwd;
    if (!qua) // 用户默认为0元，管理员可以自定义
    {
        cout << "请输入金额：";
        cin >> opcard.fBalance;
    }
    else
        opcard.fBalance = 0;

    cards.push_back(opcard);
    cout << "添加成功\n";
    auto it = cards.end() - 1;
    // cout << "当前余额：" <<(double) it->fBalance << endl;
    cout << "状态：" << it->nStatus << endl;
    cout << "开始时间：" << timetostr(it->tStart) << endl;
    cout << "结束时间：" << timetostr(it->tEnd) << endl;
    cout << "累计金额：" << it->fTotaluse << endl;
    cout << "上次使用时间：" << timetostr(it->tlast) << endl;
    cout << "使用次数：" << it->nUseCount << endl;
    cout << "余额：" << it->fBalance << endl;
    cout << "是否注销：" << it->nDel << endl;
    system("pause");
}
void removecard()
{
}
void checkcard(int qua)
{
kahao2:;
    if (cards.size() == 0)
    {
        cout << "无卡信息\n";
        system("pause");
        return;
    }
    cout << "请输入用户名：";
    cin >> opcard.aName;

    auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return strcmp(s.aName, opcard.aName) == 0; });

    if (it == cards.end())
    {
        cout << "用户名错误\n";
        system("pause");
        goto kahao2;
    }
    else
    {
        if (qua)
        {
            cout << "请输入密码：";
            cin >> opcard.aPwd;
            if (strcmp(it->aPwd, opcard.aPwd) != 0)
            {
                cout << "用户名或密码错误\n";
                system("pause");
                goto kahao2;
            }
        }
        //  cout << "用户名：" << it->aName << endl;
        //  cout << "密码：" << it->aPwd << endl;
        cout << "状态：" << it->nStatus << endl;
        cout << "开始时间：" << timetostr(it->tStart) << endl;
        cout << "结束时间：" << timetostr(it->tEnd) << endl;
        cout << "累计金额：" << it->fTotaluse << endl;
        cout << "上次使用时间：" << timetostr(it->tlast) << endl;
        cout << "使用次数：" << it->nUseCount << endl;
        cout << "余额：" << it->fBalance << endl;
        cout << "是否注销：" << it->nDel << endl;
    }
    system("pause");
}
void editmoney(int a, int qua)
{ // 1为充值/消费，2为退费
kahao:;
    cout << "请输入用户名：";
    cin >> opcard.aName;
    cout << "请输入密码：";
    cin >> opcard.aPwd;
    auto it = find_if(cards.begin(), cards.end(), [](const Card &s)
                      { return s.aName == opcard.aName && s.aPwd == opcard.aPwd; });
    // if (it == cards.end()+1){
    //   cout << "用户名或密码错误\n";goto kahao;
    //       }
}
void checkhistory(int qual)
{ // 查消费历史
}
void checkmoney(int qual)
{ // 查余额
}