#include <bits/stdc++.h>

#include <fstream>
#include "mainmenu.hpp"
using namespace std;
int read();
void write();
vector<Card> cards;
int main()
{
    system("chcp 65001");
    system("cls");
    cout << "读取中...\n";
    int i = read();
    if (i == -1)
    {
        system("pause");
        return 0;
    }
    cout << "读取成功\n";

    string lang;
BEgin:;
    cout << "请选择你的语言：\nEnglish\n简体中文\n";
    cin >> lang;
    if (lang == "English" || lang == "english"||lang=="ENGLISH")
    {
        std::cout << "haha, you 've been cheated,\n I havn't finished it yet, so choose another language,plz?\nI have a small video to show my apologize\ntype \"agree\" to enjoy it, or type \"any other text\" to choose another language\n";
        string temp;
        cin >> temp;
        if (temp == "agree")
        {
            std::string command = "powershell -command \"& {Start-Process -FilePath '.\\VLC\\vlc.exe' -ArgumentList '--quiet', '--started-from-file', '--play-and-exit', '.\\media\\never.mp4' -NoNewWindow -Wait}\"";
            system(command.c_str());
        }
        else
        {
        }
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
    write();

    system("pause");
    return 0;
}
int read()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);

    printf("当前时间%d/%d/%d %02d:%02d:%02d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

    ifstream csv_data("..//test.csv", ios::in);
    string line;

    if (!csv_data.is_open())
    {
        cout << "Error: opening file fail,  check the file and re open this program." << endl;
        return -1;
    }
    istringstream sin;    // 将整行字符串line读入到字符串istringstream中
    vector<string> words; // 声明一个字符串向量
    string word;

    getline(csv_data, line); // 读取第一行标题

    while (getline(csv_data, line)) // 读取每行
    {
        sin.str(line);
        while (getline(sin, word, ','))
        {
            words.push_back(word);
        }
        Card temp;
        strcpy(temp.aName, words[0].c_str());
        strcpy(temp.aPwd, words[1].c_str());
        temp.nStatus = atoi(words[2].c_str());
        temp.tStart = atoi(words[3].c_str());
        temp.tEnd = atoi(words[4].c_str());
        temp.fTotaluse = atof(words[5].c_str());
        temp.tlast = atoi(words[6].c_str());
        temp.nUseCount = atoi(words[7].c_str());
        temp.fBalance = atof(words[8].c_str());
        //  temp.nowmoney = atof(words[9].c_str());
        temp.nDel = atoi(words[9].c_str());
        cards.push_back(temp);
        words.clear();
        sin.clear();
    }
    return 0;
}
void write()
{
    cout << "正在保存，请稍后";
    std::ofstream outFile;
    outFile.open("..//test.csv", std::ios::out | std::ios::trunc);
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
            << "是否删除" << std::endl;
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
}