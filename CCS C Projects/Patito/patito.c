#include <patito.h>

#use fast_io(B) //configuracion rapido para puerto B

void main()
{
   set_tris_b(0x00);          //configuro las entradas y salidas
 
 while(TRUE){
   
   output_high(PIN_B0);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   
   output_high(PIN_B2);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   
   output_high(PIN_B4);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos

   output_high(PIN_B6);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   
   output_low(PIN_B0);
   output_low(PIN_B2);
   output_low(PIN_B4);
   output_low(PIN_B6);
   
   delay_ms(500);
 }
   
   /*
   output_high(PIN_B0);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   
   output_high(PIN_B2);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   
   output_high(PIN_B4);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos

   output_high(PIN_B6);        //pongo el PB.1 a cero
   delay_ms(500);             //tiempo de retardo en milisegundos
   */
}
