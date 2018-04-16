#include <teclado_tres_tres.h>

#define LCD_DATA_PORT getenv("SFR:PORTD")                         ////
#include <lcd.c>
#define LCD_ENABLE_PIN  PIN_D0                                    ////
#define LCD_RS_PIN      PIN_D1                                    ////
#define LCD_RW_PIN      PIN_D2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7               

#include <kbd.c>
#define use_portb_kbd TRUE

void main()
{
   lcd_init();
   kbd_init();
   
   delay_ms(100);
   printf(lcd_putc, "\fListo");

   while(TRUE)
   {
      char key = kbd_getc();
      
      if(key != 0){
         printf(lcd_putc, "\fDigito: %c", key);
      }
      delay_ms(100);
   }

}
