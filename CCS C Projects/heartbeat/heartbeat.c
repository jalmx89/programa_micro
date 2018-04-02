#include <heartbeat.h>

void main()
{

   float alpha = 0.75;
   int period = 100;
   float change = 0.0;
   float minval = 0.0;

///////////configuración del ADC //////////////
   setup_adc(ADC_CLOCK_INTERNAL); //configura la lectura en funcion del reloj interno
   setup_adc_ports(AN0); //cofiguto para usar el PORT A
   set_adc_channel(0); //configuro el canal 0 que voy a usar
   delay_ms(100); // le doy un tiempo de configuración
//////////////////////////////////////////////////////////////////

   //AGREGAR LCD
   
   while(TRUE)
   {
    float oldValue = 0;
    float oldChange = 0;
 
    int8 rawValue = read_adc(); //leo la entrada del ADC configurado
    float value = alpha * oldValue + (1 - alpha) * rawValue;
 
    //valor en crudo (rawValue);
    //valor de los latidos del corazón (value);
    oldValue = value;
 
    delay_ms(period);
   }

}
