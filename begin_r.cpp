#include<bits/stdc++.h>
#include"mainmenu.c"
using namespace std;
int main(){
    
    string lang;
    BEgin:;
    cout<<"请选择你的语言：\nEnglish\n简体中文\n";
    cin>>lang;
    if (lang == "English"||lang=="english")
    {
        std::cout << "not ready,choose another language,plz?\n";
        goto BEgin;
    }
    else if (lang == "简体中文"||lang=="chinese")
    {
        
    }
    else
        {
            system("cls");
        cout << "wrong,plz choose a language.//错误，请重新选择语言\n";
        
        goto BEgin;
    }
    string permis;
    cout<<"请输入你的身份:1.用户 2.管理\n";
    cin>>permis;
    secure(permis);//加语言种类
    return 0;
}