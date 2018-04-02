#include <entradas.h>

#use fast_io(A)   //configuro el puerto A
#use fast_io(B)   //configuro el puerto B

void main()
{//abre main

   set_tris_a(255); //configuro puerto A como entrada
   set_tris_b(0); //configuro puerto B como salida
   
   while(TRUE)
   {//abre while
      int8 boton1 = input(PIN_A0);// leo la entrada en el Pin 0 del puerto A
      int8 boton2 = input(PIN_A1);// leo la entrada en el Pin 0 del puerto A
      int8 boton3 = input(PIN_A2);// leo la entrada en el Pin 0 del puerto A
      
      if(boton1 == 1){ //verifico si fue presionado el boton
         output_high(PIN_B0); //pongo a 1 la salida del pin 0 del puerto B
      }
      else{                   //de lo contrario
         output_low(PIN_B0); // pongo en 0 la salida del pin 0 del puerto B
      }
      
      if(boton2 == 1){ //verifico si fue presionado el boton
         output_high(PIN_B1); //pongo a 1 la salida del pin 0 del puerto B
      }
      else{                   //de lo contrario
         output_low(PIN_B1); // pongo en 0 la salida del pin 0 del puerto B
      }
      
      if(boton3 == 1){ //verifico si fue presionado el boton
         output_high(PIN_B2); //pongo a 1 la salida del pin 0 del puerto B
      }
      else{                   //de lo contrario
         output_low(PIN_B2); // pongo en 0 la salida del pin 0 del puerto B
      }
      
   }//cierra while

}
