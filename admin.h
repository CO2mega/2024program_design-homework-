#include <bits/stdc++.h>
#include "./timetool.h"
using namespace std;
void Failed()
{
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    mt19937 generator(seed);
    string FILENAME;
    FILENAME.push_back(static_cast<char>((generator() % 3) + '0'));
    string command = "powershell -command \"& {Start-Process -FilePath '.\\VLC\\vlc.exe' -ArgumentList '--quiet', '--started-from-file', '--play-and-exit', '.\\media\\" + FILENAME + ".mp3' -NoNewWindow -Wait}\"";
    system(command.c_str());
}
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
void logOperation(int operatorType, const string &operationContent)
{
    // 获取当前时间
    time_t now = time(0);
    struct tm *now_tm = localtime(&now);

    // 创建日志文件路径
    string logFilePath = "log.txt";

    // 打开日志文件进行写入
    ofstream logFile(logFilePath, ios::app); // 追加写入，不会覆盖原有内容

    // 写入日志
    logFile << "操作时间：" << setw(2) << setfill('0') << now_tm->tm_year + 1900 << "-"
            << setw(2) << setfill('0') << now_tm->tm_mon + 1 << "-"
            << setw(2) << setfill('0') << now_tm->tm_mday << " "
            << setw(2) << setfill('0') << now_tm->tm_hour << ":"
            << setw(2) << setfill('0') << now_tm->tm_min << ":"
            << setw(2) << setfill('0') << now_tm->tm_sec << "\n";

    logFile << "操作者：" << (operatorType == 0 ? "管理员" :"用户") << "\n";
    logFile << "操作内容：" << operationContent << "\n";
    logFile << "---------------------------------\n";

    // 关闭文件
    logFile.close();
}

void userlog(const string &username, const string &operationContent)
{
    // 获取当前时间
    time_t now = time(0);
    struct tm *now_tm = localtime(&now);

    // 创建用户日志文件路径
    string userLogFilePath = "userlog/" + username + ".txt";

    // 打开用户日志文件进行写入
    ofstream userLogFile(userLogFilePath, ios::app); // 追加写入，不会覆盖原有内容

    // 写入日志
    userLogFile << "操作时间：" << timetostr(now) << "\n";
    userLogFile << "操作内容：" << operationContent << "\n";
    userLogFile << "---------------------------------\n";

    // 关闭文件
    userLogFile.close();
}
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
        Failed();
        goto loginbe;
    }
    else
    {
        if (it->nDel == 1)
        {
            cout << "该卡已注销\n";
            Failed();
            goto loginbe;
        }
        cout << "请输入密码：";
        cin >> opcard.aPwd;
        if (strcmp(it->aPwd, opcard.aPwd) != 0)
        {
            cout << "用户名或密码错误\n";
            Failed();
            goto loginbe;
        }
    }
    cout << "登录成功,开始计费" << endl;
    logOperation(1, "用户登录成功");
    userlog(it->aName, "用户登录成功");
    it->nStatus = 1;
    it->tStart = time(0);
    system("pause");
    return 1;
}
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
        Failed();
        system("pause");
        goto logoutbe;
    }
    else
    {
        if (it->nDel == 1)
        {
            cout << "该卡已注销\n";
            Failed();
            goto logoutbe;
        }
        cout << "请输入密码：";
        cin >> opcard.aPwd;
        if (strcmp(it->aPwd, opcard.aPwd) != 0)
        {
            cout << "用户名或密码错误\n";
            Failed();
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
        it->fTotaluse += tot * 0.001;
        it->fBalance -= tot * 0.001;
        it->tlast = time(0);
        it->nUseCount++;
        cout << "当前余额：" << (it->fBalance) << endl;
        it->tStart = 0;
        it->tEnd = 0;
        string ss;
        ss = "下机成功，本次消费：" + to_string(tot * 0.001) + "元";
        logOperation(1, ss);
        userlog(it->aName, ss);
        /* logOperation(1, "用户下机成功," + "使用时间：" + to_string(tot) + "秒" + "本次消费：" + to_string(tot * 0.001));
        userlog(1, "当前余额：" + to_string(static_cast<float>(it->fBalance))); */
    }
    system("pause");
    opcard.clear();
    s = nullptr;
}

/* void addcard(int qua)
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
} */
void addcard(int qua)
{
    bool duplicate;
    do
    {
        duplicate = false;
        opcard.clear(); // 清空opcard
        cout << "请输入用户名：";
        cin >> opcard.aName;

        // 检查用户名是否重复
        auto it = find_if(cards.begin(), cards.end(), [&](const Card &card)
                               { return strcmp(card.aName, opcard.aName) == 0; });

        if (it != cards.end())
        {
            cout << "用户名重复，请重新输入。\n";
            duplicate = true;
        }
    } while (duplicate);
passwd:;
    cout << "请输入密码：(不可带有逗号)";
    cin >> opcard.aPwd;
    for (auto i : opcard.aPwd)
    {
        if (i == ',')
        {
            cout << "密码中不可带有逗号，请重新输入\n";
            system("pause");
            system("cls");
            goto passwd;
        }
    }
    if (!qua)
    {
        cout << "请输入金额：";
        cin >> opcard.fBalance;
    }
    else
    {
        opcard.fBalance = 0;
    }

    cards.push_back(opcard);
    cout << "添加成功\n";

    // 输出添加的卡片信息
    auto it = cards.end() - 1;
    cout << "状态：" << it->nStatus << endl;
    cout << "开始时间：" << timetostr(it->tStart) << endl;
    cout << "结束时间：" << timetostr(it->tEnd) << endl;
    cout << "累计金额：" << it->fTotaluse << endl;
    cout << "上次使用时间：" << timetostr(it->tlast) << endl;
    cout << "使用次数：" << it->nUseCount << endl;
    cout << "余额：" << it->fBalance << endl;
    cout << "是否注销：" << it->nDel << endl;

    // system("pause"); // 根据需要注释或保留
}
void removecard(int qua)
{
kahao2:;
kahao1:;
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
        Failed();
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
                Failed();
                system("pause");
                goto kahao2;
            }
        }
        unsigned int seed = static_cast<unsigned int>(time(nullptr));
        mt19937 generator(seed);

        int randomNumber = generator();
        cout << "状态：" << it->nStatus << endl;
        cout << "开始时间：" << timetostr(it->tStart) << endl;
        cout << "结束时间：" << timetostr(it->tEnd) << endl;
        cout << "累计金额：" << it->fTotaluse << endl;
        cout << "上次使用时间：" << timetostr(it->tlast) << endl;
        cout << "使用次数：" << it->nUseCount << endl;
        cout << "余额：" << it->fBalance << endl;
        cout << "是否注销：" << it->nDel << endl
             << endl;
        cout << "确认注销卡号为：" << it->aName << "的卡吗？确认请输入" << setw(6) << setfill('0') << randomNumber % 1000000 << endl;
        int num;
        cin >> num;
        if (num == randomNumber % 1000000)
        {
            cout << "已注销";
            it->nStatus = 2;
            it->nDel = 1;
            system("pause");
        }
        else
        {
            cout << "错误";
            Failed();
            goto kahao1;
        }
    }
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
        Failed();
        system("pause");
        goto kahao2;
    }
    else
    {
        if (it->nDel == 1)
        {
            cout << "该卡已注销\n";
            Failed();
            goto kahao2;
        }
        if (qua)
        {
            cout << "请输入密码：";
            cin >> opcard.aPwd;
            if (strcmp(it->aPwd, opcard.aPwd) != 0)
            {
                cout << "用户名或密码错误\n";
                Failed();
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
        Failed();
        system("pause");
        goto kahao2;
    }
    else
    {
        if (it->nDel == 1)
        {
            cout << "该卡已注销\n";
            Failed();
            goto kahao2;
        }
        if (qua)
        {
            cout << "请输入密码：";
            cin >> opcard.aPwd;
            if (strcmp(it->aPwd, opcard.aPwd) != 0)
            {
                cout << "用户名或密码错误\n";
                Failed();
                system("pause");
                goto kahao2;
            }
        }
    }
    if (a == 1)
    {
        cout << "请输入充值金额：";
        float b;
        cin >> b;
        it->fBalance += b;
        cout << "充值成功，当前余额：" << it->fBalance << endl;
        logOperation(qua, "充值成功，充值金额：" + to_string(b));
        userlog(it->aName, "充值成功，充值金额：" + to_string(b));
    }
    else
    {
        cout << "请输入退费金额：";
        float b;
        cin >> b;
        it->fBalance -= b;
        cout << "退费成功，当前余额：" << it->fBalance << endl;
        logOperation(qua, "退费成功，退费金额：" + to_string(b));
        userlog(it->aName, "退费成功，退费金额：" + to_string(b));
    }
    system("pause");
}
void checkhistory(int qua)
{ // 查消费历史
}
void checkmoney(int qua)
{ // 查余额
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
        Failed();
        system("pause");
        goto kahao2;
    }
    else
    {
        if (it->nDel == 1)
        {
            cout << "该卡已注销\n";
            Failed();
            goto kahao2;
        }
        if (qua)
        {
            cout << "请输入密码：";
            cin >> opcard.aPwd;
            if (strcmp(it->aPwd, opcard.aPwd) != 0)
            {
                cout << "用户名或密码错误\n";
                Failed();
                system("pause");
                goto kahao2;
            }
        }
    }
    cout << "当前余额：" << it->fBalance << endl;
}
void passwdchange()
{
    string filePath = "passwd.json";
    string command = "notepad \"" + filePath + "\"";

    system(command.c_str());
}
void manualsave()
{
    cout << "正在保存，请稍后";
    ofstream outFile;
    outFile.open("test.csv", ios::out | ios::trunc);
    outFile << "name" << ','
            << "password" << ','
            << "status/当前状态" << ','
            << "start/开始时间"
            << ","
            << "end/结束时间"
            << ","
            << "累计使用"
            << ","
            << "上次使用"
            << ","
            << "使用次数"
            << ","
            << "余额"
            << ","
            << "是否删除" << endl;
    /*  freopen("database.txt", "w", stdout);
     cout << cards.size() << endl;*/
    for (auto it : cards)
    {
        outFile << it.aName << "," << it.aPwd << "," << it.nStatus << "," << it.tStart << "," << it.tEnd << "," << it.fTotaluse << "," << it.tlast << "," << it.nUseCount << "," << it.fBalance << "," /* << it.nowmoney << ","  */ << it.nDel << endl;
    }
    outFile.close();
    cout << "保存成功" << endl;
    time_t timep;
    struct tm *p;
    time(&timep);          // 获取从1970至今过了多少秒，存入time_t类型的timep
    p = localtime(&timep); // 用localtime将秒数转化为struct tm结构体

    printf("保存时间%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    system("pause");
}