#include<iostream>
#include<time.h>
void timetostr(time_t t,char *str)
{
    struct tm *tmp;
    tmp=localtime(&t);
    strftime(str,100,"%Y-%m-%d %H:%M:%S",tmp);
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