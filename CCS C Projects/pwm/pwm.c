#include <pwm.h>
//recordar hacer el cambio en el archivo .h del ADC, ajustar a 10

/* CONFIG PWM PERIOD
PWM period = Fosc / [(PR2) + 1] * 4 * (TMR2 Prescale Value)
Where PWM frequency is defined as 1/[PWM period].
PR2 is Timer2 preload value, 8 bits -> value max 255
Fosc = MCU_frequency -> XT
TMR2 Prescale Value can be 1, 4 or 16.
*/
void main()
{
    setup_adc(ADC_CLOCK_INTERNAL);            
    setup_adc_ports(AN0);          
    set_adc_channel(0);
    delay_ms(10);
    
    //configuracion 
    setup_timer_2(T2_DIV_BY_16, 255, 1); //se ajusta PWM
    setup_ccp1(CCP_PWM);//se ajusta el CCP para PWM  
    
    int16 valor;
    
    while(TRUE){
        valor = read_adc();
        delay_ms(100);
        set_pwm1_duty(valor); //se asigna el valor del PWM
       
    }
}
