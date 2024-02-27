#include <iostream>
#include "Mainmenu.h"

int main()
{
BEgin:;
    std::cout << "choose your language\\请选择你的语言:\nEnglish\nChinese\\简体中文\n";
    std::string lang;
    std::cin >> lang;
    if (lang == "English"||lang=="english")
    {
        std::cout << "not ready,choose another language,plz?\n";
        goto BEgin;
    }
    else if (lang== "Chinese" || lang == "简体中文"||lang=="chinese")
    {
        
    }
    else
        {
            system("cls");
        std::cout << "wrong,plz choose a language.//错误，请重新选择语言\n";
        
        goto BEgin;
    }
    std::string qualify;
    std::cout<<"请输入你的身份:1.用户 2.管理\n";
    std::cin>>qualify;
    oper(qualify);

#ifdef DEBUG
    system("pause");
#endif
}
