#include "stime.h"
#include <time.h>
#include <cstdio>
stime::stime()//自动记录类创建时间 
{
	time_t t = time(NULL);
    struct tm* current_time = localtime(&t);//本地时间 
    year=1900 + current_time->tm_year;
    mon=1 + current_time->tm_mon;//此month的范围为0-11,
    if(mon==0) mon=12;
    day=current_time->tm_mday;
    hour=current_time->tm_hour;
    min=current_time->tm_min;
    sec=current_time->tm_sec;
}

void stime::show()//输出创建时间 
{
	printf("创建时间:%04d/%02d/%02d %02d:%02d:%02 d\n",year,mon,day,hour,min,sec);
}
