#include <semaforo.h>
#use fast_io(D)

void main()
{

   set_tris_d(0);
   output_d(0);
   
   while(TRUE)
   {
      output_high(PIN_D0); //prendido el rojo
      delay_ms(500);
      
      output_low(PIN_D0); //apago el rojo
      output_high(PIN_D2); //prendo el verde
      delay_ms(400); 
      
      output_low(PIN_D2); //parpadea el verde
      delay_ms(100);
      output_high(PIN_D2);
      delay_ms(100);
      output_low(PIN_D2);
      delay_ms(100);
      output_high(PIN_D2);
      delay_ms(100);
      output_low(PIN_D2); //apago el verde
      
      
      output_high(PIN_D1); //prendo ambar
      delay_ms(400);
      output_low(PIN_D1); //apago ambar
      
      
   }

}
