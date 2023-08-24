#include "DIO.h"
#include "GPIO_INTERRUPT.h"
#include "LCD.h"
#include "Keypad.h"
#include "parse.h"
#include "stdlib.h"
#include "stdio.h"
#include "Systick.h"

#define PUSHBUTTON1 0
#define PUSHBUTTON2 4

extern int LCD_pos;
extern int LCD_counter;

uint8_t counter = 0;

float parse(char *s);
char s[100];

volatile uint8_t button = 0;



int main(void)
{
    Keypad_INIT();
    delay_ms(50);
    LCD_INIT();
    SEND_DATA(':');

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



/*
//
//void Read_Keypad()
//{
//        uint8_t Keypad[4][4]=   {{'1','2','3','+'},
//                                {'4','5','6','-'},
//                                {'7','8','9','*'},
//                                {'#','0','=','/'}}; // Initializing array to loop on it
//        // Clearing the interrupt Flag
//        GPIO_PORTB_ICR_R=0xFF;
//        uint8_t row = 0;
//        uint8_t col = 0;
//        for (row = 0; row < 4; row++)
//        {
//            int temp = bit_check(GPIO_PORTB_DATA_R, row);
//            if(!temp)
//            {
//                break;
//            }
//        }
//
//
//        for (col = 4; col < 8; col++)
//        {
//            bitset(GPIO_PORTB_DATA_R, col);
//
//            if (bit_check(GPIO_PORTB_DATA_R, row))
//            {
//                //reset the state of the columns back to 0
//                bitclear(GPIO_PORTB_DATA_R, 4);
//                bitclear(GPIO_PORTB_DATA_R, 5);
//                bitclear(GPIO_PORTB_DATA_R, 6);
//                bitclear(GPIO_PORTB_DATA_R, 7);
//                if(row!=4 &&Keypad[row][col-4]!= '=')
//                {
//                    if(Keypad[row][col-4] == '#') // Reset
//                    {
//                        clear_display();
//                        return_home();
//                        LCD_pos = 0;
//                        LCD_counter = 0;
//                        counter = 0;
//                    }
//                    else
//                    {
//                    SEND_DATA(Keypad[row][col-4]);
//                    s[counter] = Keypad[row][col-4];
//                    counter++;
//                    }
//                }
//                else if(Keypad[row][col-4]== '=')
//                {
//                    float temp = parse(s);
//                    /*
//                    if((int)temp == (int)SyntaxError)
//                    {
//                        clear_display();
//                        LCD_pos = 0;
//                        LCD_counter = 0;
//                        SEND_STRING("Syntax Error");
//                        delay_ms(1000);
//                        clear_display();
//                        return_home();
//                        LCD_pos = 0;
//                        LCD_counter = 0;
//                        counter = 0;
//
//                    }
//
//                    else if(((int)temp == (int)MathError) < 1e-9)
//                    {
//                        clear_display();
//                        LCD_pos = 0;
//                        LCD_counter = 0;
//                        SEND_STRING("Math Error");
//                        delay_ms(1000);
//                        clear_display();
//                        return_home();
//                        LCD_pos = 0;
//                        LCD_counter = 0;
//                        counter = 0;
//                    }
//                    else
//                   {*/
//                       // sprintf(s, "%f", parse(s));
//                        ltoa((int)temp, s);
//                        clear_display();
//                        SEND_STRING(s);
//                  // }
//                }
//                delay_ms(50);
//                GPIO_PORTB_ICR_R=0xFF;
//                SETBIT(NVIC_UNPEND0_R, 1);
//                return;
//            }
//
//        }
//
//}*/
