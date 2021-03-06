#include <servo_pwm.h>

/* CONFIG PWM PERIOD
PWM period = Fosc / [(PR2) + 1] • 4 • (TMR2 Prescale Value)
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
    
    //configuración de pwm
    setup_timer_2(T2_DIV_BY_1, 100, 1); //se ajusta PWM a 1.2KHz
    setup_ccp1(CCP_PWM);//se ajusta el CCP para PWM  
    
    int16 valor;
    
    while(TRUE){
        valor = read_adc();
        delay_ms(100);
        int16 resultado = ((61.0/1024.0)*valor)+ 42.0;
        set_pwm1_duty(resultado); //se asigna el valor del PWM
       
    }

}
