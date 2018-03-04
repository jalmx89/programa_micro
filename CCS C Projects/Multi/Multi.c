#include <Multi.h>

#use fast_io(A)
#use fast_io(B)

void on(int pin){

}
void main()
{
   set_tris_a(255);
   set_tris_b(0);
   
   output_a(0);
   output_b(0);
   
   while(TRUE)
   {
      //TODO: User Code
      if(input(PIN_A0) == 1){
         output_low(PIN_B0);
      }else{
         output_high(PIN_B0);
      }
      
       //TODO: User Code
      if(input(PIN_A1) == 1){
         output_low(PIN_B1);
      }else{
         output_high(PIN_B1);
      }
      
       //TODO: User Code
      if(input(PIN_A2) == 1){
         output_low(PIN_B2);
      }else{
         output_high(PIN_B2);
      }
    
   }

}
