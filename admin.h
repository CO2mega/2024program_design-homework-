#ifndef ADMIN_H
#define ADMIN_H

#include <bits/stdc++.h>
#include "./timetool.h"
using namespace std;

// Function prototypes
void Failed();
template <typename T> class Vector;
void logOperation(int operatorType, const string &operationContent);
void userlog(const string &username, const string &operationContent);
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
extern vector<Card> cards;

// Additional function prototypes
void admin();
void user();
void login();
void logout();
void secure(string op);
void addcard(int qua);
void removecard(int qua);
void checkcard(int qua);
void editmoney(int a, int qua);
void checkhistory(int qua);
void checkmoney(int qua);
void passwdchange();
void manualsave();
void usrpasswd();

#endif // ADMIN_H
