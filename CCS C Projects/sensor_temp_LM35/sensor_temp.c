#include <sensor_temp.h>

#define LCD_DATA_PORT getenv("SFR:PORTD") 
#include <lcd.c>

#define LCD_ENABLE_PIN  PIN_D0                                    ////
#define LCD_RS_PIN      PIN_D1                                    ////
#define LCD_RW_PIN      PIN_D2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7   

void main()
{
  /////configuración del ADC
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   delay_ms(10);
   //termina config de ADC
   
   ///configuranción de LCD
   lcd_init();
   delay_ms(100);
   
   printf(lcd_putc, "\fLeyendo\ntemperatura");
   delay_ms(500);
   
   //declaro la variables a usar
   int16 valor = 0;  //variable en donde voy a guardar el valor del ADC
   float temperatura = 0;
   float voltaje = 0;
   
   while(TRUE)
   {
      valor= read_adc();
      temperatura =  (5.0 * valor * 100.0) / 1024.0;
      voltaje = (5 * valor)/1024.0; //convierto los bits en valor del voltaje
       
      printf(lcd_putc, "\f%Lu bits %2.4fV\n%f C", valor, voltaje, temperatura);
      delay_ms(200);
   }

}
