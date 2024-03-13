#include <bits/stdc++.h>
#include "mainmenu.c"
using namespace std;
// void read();
// void write();
vector<Card> cards;
int main()
{cout<<"hello";
    freopen("database.txt", "w", stdout);
    cout << 0;


    
   // fclose(stdout);
   system("pause");
  /*  cout << 114;
    // read();
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);

    printf("当前时间%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    freopen("database.txt", "r", stdin);
    int n;
    cin >> n;
    cout << n;
    for (int i = 0; i < n; i++)
    {
        Card temp;
        cin >> temp.aName >> temp.aPwd >> temp.nStatus >> temp.tStart >> temp.tEnd >> temp.fTotaluse >> temp.tlast >> temp.nUseCount >> temp.fBalance >> temp.nowmoney >> temp.nDel;
        cards.push_back(temp);
    }
    if (n != 0)
        cin >> p->tm_year >> p->tm_mon >> p->tm_mday >> p->tm_hour >> p->tm_min >> p->tm_sec;
    fclose(stdin);
    if (n != 0)
        cout << "上次保存时间：" << p->tm_year << "/" << p->tm_mon << "/" << p->tm_mday << " " << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec << endl;
    system("pause");
 */


    string lang;
BEgin:;
    cout << "请选择你的语言：\nEnglish\n简体中文\n";
    cin >> lang;
    if (lang == "English" || lang == "english")
    {
        std::cout << "not ready,choose another language,plz?\n";
        goto BEgin;
    }
    else if (lang == "简体中文" || lang == "chinese")
    {
    }
    else
    {
        system("cls");
        cout << "wrong,plz choose a language.//错误，请重新选择语言\n";

        goto BEgin;
    }
    string permis;
    cout << "请输入你的身份:1.用户 2.管理\n";
    cin >> permis;
    secure(permis); // 加语言种类
    // write();
    return 0;
}
/* void read()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);

    printf("当前时间%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    freopen("database.txt", "r", stdin);
    int n;
    cin >> n;
    cout << n;
    if (n == 0)
        return;
    for (int i = 0; i < n; i++)
    {
        Card temp;
        cin >> temp.aName >> temp.aPwd >> temp.nStatus >> temp.tStart >> temp.tEnd >> temp.fTotaluse >> temp.tlast >> temp.nUseCount >> temp.fBalance >> temp.nowmoney >> temp.nDel;
        cards.push_back(temp);
    }
    if (n != 0)
        cin >> p->tm_year >> p->tm_mon >> p->tm_mday >> p->tm_hour >> p->tm_min >> p->tm_sec;
    fclose(stdin);
    if (n != 0)
        cout << "上次保存时间：" << p->tm_year << "/" << p->tm_mon << "/" << p->tm_mday << " " << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec << endl;
}
void write()
{
    cout << "正在保存，请稍后";
    freopen("database.txt", "w", stdout);
    cout << cards.size() << endl;
    for (auto it : cards)
    {
        cout << it.aName << ' ' << it.aPwd << ' ' << it.nStatus << ' ' << it.tStart << ' ' << it.tEnd << ' ' << it.fTotaluse << ' ' << it.tlast << ' ' << it.nUseCount << ' ' << it.fBalance << ' ' << it.nowmoney << ' ' << it.nDel << endl;
    }

    time_t timep;
    struct tm *p;
    time(&timep);          // 获取从1970至今过了多少秒，存入time_t类型的timep
    p = localtime(&timep); // 用localtime将秒数转化为struct tm结构体

    printf("%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

    fclose(stdout);
    printf("保存时间%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
} */