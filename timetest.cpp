#include<iostream>
using namespace std;
#include".\timetest.h"
int main(){
    char t[100];
    timetostr(time(NULL),t);
    cout<<"time to str"<<t<<endl;
    cout<<strtotime(t);
    system("pause");
}