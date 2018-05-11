#include <servo_adc.h>
#use fast_io(D)

void main(){
    set_tris_d(0);
    output_d(0);
    int16 time = 20000;//tiempo que necesita el servo

    setup_adc(ADC_CLOCK_INTERNAL); 
    setup_adc_ports(AN0); 
    set_adc_channel(0);
    delay_us(10);
 
    while(TRUE)
    {
        int16 value=read_adc();
        int16 resultado = ((400.0/341.0)*value)+800;
        int16 complemento = time - resultado; 
        
        for(int i=0; i<50; i++){
            output_high(PIN_D0);
            delay_us(resultado);
            output_low(PIN_D0);
            delay_us(complemento);
        }
    }
}
