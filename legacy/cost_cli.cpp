#include <iostream>
#include "Mainmenu.h"

int main()
{
BEgin:;
    std::cout << "choose your language\\��ѡ���������:\nEnglish\nChinese\\��������\n";
    std::string lang;
    std::cin >> lang;
    if (lang == "English"||lang=="english")
    {
        std::cout << "not ready,choose another language,plz?\n";
        goto BEgin;
    }
    else if (lang== "Chinese" || lang == "��������"||lang=="chinese")
    {
        
    }
    else
        {
            system("cls");
        std::cout << "wrong,plz choose a language.//����������ѡ������\n";
        
        goto BEgin;
    }
    std::string qualify;
    std::cout<<"������������:1.�û� 2.����\n";
    std::cin>>qualify;
    oper(qualify);

#ifdef DEBUG
    system("pause");
#endif
}
