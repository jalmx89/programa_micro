#include <adc_lcd.h>

#define use_portb_lcd TRUE //indico que usare el puerto B, primero configuro el puerto
#include <lcd.c>           //cargo la libreria

#define LCD_ENABLE_PIN  PIN_B0                                    ////
#define LCD_RS_PIN      PIN_B1                                    ////
#define LCD_RW_PIN      PIN_B2                                    ////
#define LCD_DATA4       PIN_B4                                    ////
#define LCD_DATA5       PIN_B5                                    ////
#define LCD_DATA6       PIN_B6                                    ////
#define LCD_DATA7       PIN_B7

void main(){
   unsigned int16 valor = 0;
   float voltaje = 0;
   
   lcd_init();    //inicio lcd
   delay_ms(10);  //tiempo de espera de configuracion de lcd
   
   ///////////////////configuracion de ADC
   setup_adc(ADC_CLOCK_INTERNAL); //configuramos el reloj para el ADC, le decimos que ser� el relojo interno
   setup_adc_ports(AN0); //elegimos el puerto del cual vamos a usar el ADC, en este caso el PORTA => AN0, por que solo se usar� uno
   
   set_adc_channel(0); //decimos que vamos a leer el canal 0,
   delay_ms(100);        //el tiempo que viene marcado en el datasshet para esperar la configuraci�n interna
   //////////////////////termina la configuraci�n de ADC
   
   lcd_putc("\fLeyendo ADC");
   delay_ms(900);
   
   while(TRUE){
      
      valor = read_adc(); //leemos el canal que acabamos de configurar
      
      printf(lcd_putc, "\fADC: %4Lu", valor);  //pongo en la lcd en parte superior el valor del ADC
      
      voltaje = (5 * valor)/1024.0; //convierto los bits en valor del voltaje
      //lcd_gotoxy(1,2); //mando al segundo renglon el cursor
      printf(lcd_putc, "\nVoltaje: %1.2fV", voltaje); //pongo en la lcd el texto con el valor del voltaje
      
      delay_ms(50);  //tiempo de espera para repetir el proceso
   }
}