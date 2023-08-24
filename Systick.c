#include "Systick.h"


void Systic_INIT()
{

    SETBIT(NVIC_ST_CTRL_R, 0);
    SETBIT(NVIC_ST_CTRL_R, 1);
    SETBIT(NVIC_ST_CTRL_R, 2);

    NVIC_ST_RELOAD_R = 1600000-1;


}

void SYS_display()
{
    static int ms = 0;
    static int sec = 0;
    static int minutes = 0;

    char m[130]={};
    char s[100]={};
    char MS[101]={};


    ms++;
    ltoa(minutes, m);
    strcat(m, ":");
    ltoa(sec , s);
    strcat(s, ".");
    strcat(m, s);
    ltoa(ms, MS);
    strcat(m, MS);

    if(ms%10 == 0 && ms!=0)
    {
        sec++;
        ms=0;
    }
    else if(sec%60 == 0 && sec!=0)
    {
        minutes++;
        sec=0;
    }
    SEND_STRING(m);


}

void SYS_stop()
{
    CLEARBIT(NVIC_ST_CTRL_R, 0);

}
