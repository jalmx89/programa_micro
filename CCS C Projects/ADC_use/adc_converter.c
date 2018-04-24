#include <adc_converter.h>

#use fast_io(D)

void main(){
   unsigned int16 valor = 0;
      
   set_tris_d(0); //configuro el puerto D como salida
   output_d(0);   //pongo a 0 todas las salidas del puerto D
   
   setup_adc(ADC_CLOCK_INTERNAL); //configuramos el reloj para el ADC, le decimos que ser� el relojo interno
   setup_adc_ports(AN0); //elegimos el puerto del cual vamos a usar el ADC, en este caso el PORTA => AN0, por que solo se usar� uno
   set_adc_channel(0); //decimos que vamos a leer el canal 0,
   delay_ms(10);        //el tiempo que viene marcado en el datasshet para esperar la configuraci�n interna
   
   while(TRUE){
      valor = read_adc(); //leemos el canal que acabamos de configurar
      output_d(valor);
      delay_ms(10);
   }//termina while
}
