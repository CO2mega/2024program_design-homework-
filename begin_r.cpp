#include<bits/stdc++.h>
#include"mainmenu.c"
using namespace std;
int main(){
    
    string lang;
    BEgin:;
    cout<<"��ѡ��������ԣ�\nEnglish\n��������\n";
    cin>>lang;
    if (lang == "English"||lang=="english")
    {
        std::cout << "not ready,choose another language,plz?\n";
        goto BEgin;
    }
    else if (lang == "��������"||lang=="chinese")
    {
        
    }
    else
        {
            system("cls");
        cout << "wrong,plz choose a language.//����������ѡ������\n";
        
        goto BEgin;
    }
    string permis;
    cout<<"������������:1.�û� 2.����\n";
    cin>>permis;
    secure(permis);//����������
    return 0;
}