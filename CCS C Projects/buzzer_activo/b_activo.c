#include <b_activo.h>
# use fast_io(B)

/* INFORMATION
Active Buzzer module consists of an active piezoelectric buzzer, it generates a sound of aproximately 2.5kHz when signal is high.

Operating Voltage    3.5V ~ 5.5V
Maximum Current   30mA / 5VDC
Resonance Frequency   2500Hz � 300Hz*/
void main()
{

   set_tris_b(0); //configuro como salida el port B
   output_b(0);   //pongo 0 todas las salidas del puerto B
   
   while(TRUE)
   {
      output_high(PIN_B0);
      delay_ms(400);
      
      output_low(PIN_B0);
      delay_ms(400);
   }

}
