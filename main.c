#include "DIO.h"
#include "GPIO_INTERRUPT.h"
#include "LCD.h"
#include "stdlib.h"
#include "stdio.h"
#include "Systick.h"

#define PUSHBUTTON1 0
#define PUSHBUTTON2 4



volatile uint8_t button = 0;



int main(void)
{
    delay_ms(50);
    LCD_INIT();


    DIO_INIT(PORTF, 0b00000000, 0b00010001);
    interrupt_init(PORTF, PUSHBUTTON1);
    interrupt_init(PORTF, PUSHBUTTON2);

    while(1)
    {

        if(button == 1)
        {
          Systic_INIT();
        }
        else if(button == 0)
        {
            SYS_stop();
        }
        else;


    }

	return 0;
}


void GPIOF_isr()
{

    if((CHECKBIT(GPIO_PORTF_DATA_R, PUSHBUTTON1) & 1))
    {
        SETBIT(GPIO_PORTF_ICR_R,PUSHBUTTON1);
        button = 1;
    }
    else if((CHECKBIT(GPIO_PORTF_DATA_R, PUSHBUTTON2) & 1))
    {
       SETBIT(GPIO_PORTF_ICR_R,PUSHBUTTON2);
       button = 0;
    }
    delay_ms(20);
    SETBIT(GPIO_PORTF_ICR_R,0);
    SETBIT(GPIO_PORTF_ICR_R,4);
    SETBIT(NVIC_UNPEND0_R, 30);
}

void SYSTICK_isr()
{
    if(button)
    {
        SYS_display();
    }
    else;


}


