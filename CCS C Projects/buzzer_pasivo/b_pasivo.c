#include <b_pasivo.h>

#use fast_io(B)

/* INFORMATION
The KY-006 Buzzer Module consists of a passive piezoelectric buzzer, it can
generate tones between 1.5 to 2.5 kHz by switching it on and off at different
frequencies either using delays or PWM.

Operating Voltage   1.5 ~ 15V DC
Tone Generation Range   1.5 ~ 2.5kHz
*/
void main()
{


   set_tris_b(0);//configuro mi puerto B como salida
   output_b(0);     //pongo a 0 todo el puerto
   
   while(TRUE)
   {
      for (int i = 0; i < 80; i++) {  // make a sound
      output_high(PIN_B0);
      delay_ms(1); // delay 1ms
      output_low(PIN_B0);
      delay_ms(1);
      }
      delay_ms(50);
      
      for (int j = 0; j < 100; j++) { //make another sound
         output_high(PIN_B0);
         delay_ms(2); // delay 2ms
         output_low(PIN_B0);
         delay_ms(2);
      }
      
      delay_ms(100);
   }

}
