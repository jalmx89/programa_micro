#include <practica_8.h>

#use fast_io(B)


void main()
{

   set_tris_b(0); //configuro como salida el puerto B
   output_b(0); //limpio el puerto B
   
   while(TRUE)
   {
      int8 contador;
      
      for(contador = 0; contador <= 255; contador++){//comienzo for
         output_b(~contador);
         delay_ms(250);
         
      }//termino mi for
      
      output_b(0);
      delay_ms(500);
      output_b(255);
      output_b(0);
      delay_ms(500);
      output_b(255);
      delay_ms(500);
   }

}
