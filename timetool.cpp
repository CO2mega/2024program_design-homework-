#include<ctime>
#include<string>
using namespace std;
std::string timetostr(time_t t) {
    char buffer[100];
    struct tm *tmp = localtime(&t);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tmp);
    return std::string(buffer);
}
time_t strtotime(char *str)
{
    struct tm tm1;
    time_t tmp;
    sscanf(str,"%d-%d-%d %d:%d:%d",&tm1.tm_year,&tm1.tm_mon,&tm1.tm_mday,&tm1.tm_hour,&tm1.tm_min,&tm1.tm_sec);
    tm1.tm_year-=1900;
    tm1.tm_mon-=1;
    tm1.tm_isdst=-1;
    tm1.tm_sec=0;
    return mktime(&tm1);
}