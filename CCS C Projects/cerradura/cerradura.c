#include <cerradura.h>
#include "keypad4x4.c"

#define LCD_DATA_PORT getenv("SFR:PORTD")
#include <lcd.c>
#define LCD_ENABLE_PIN  PIN_D0                                    ////
#define LCD_RS_PIN      PIN_D1                                    ////
#define LCD_RW_PIN      PIN_D2                                    ////
#define LCD_DATA4       PIN_D4                                    ////
#define LCD_DATA5       PIN_D5                                    ////
#define LCD_DATA6       PIN_D6                                    ////
#define LCD_DATA7       PIN_D7  

#use fast_io(C)

const char clave[] = {'5','6', '7', '8'};
char claveRecibida[4];//array vacio con 4 espacios

void main()
{
   lcd_init(); //inicio la LCD
   delay_ms(100); //espero el tiempo de configuración
   
   kbd_init(); //inicializo el teclado
   port_b_pullups(TRUE); //activo las resistencias pull_up del puerto B
   
   set_tris_c(0); //defino como salida el port C
   output_c(0); //mando a cero el port C  
   
   printf(lcd_putc,"\fBienvenido\nDigite la clave");
   
   char tecla;
   unsigned int8 position = 0;
   
   while(TRUE){
      tecla = kbd_getc();
      
      if(tecla != 0){
         
         if(position == 0){//se ejecuta la primera vez que se presiona una tecla
            printf(lcd_putc, "\f");//borra lo que hay en pantalla
            lcd_gotoxy(5,1);//se coloca al centro de la pantalla
            printf(lcd_putc, "Clave");//escribe la palabra "Clave"
         }
         
         claveRecibida[position] = tecla; //guardo el caracter que presionaron en el teclado
         
         position++; //incremento la posicion para saber en cual voy
         lcd_gotoxy(position+5,2);//se va la posicion
         printf(lcd_putc, "*");//pone un * en la siguiente 
         
         if(position == 4){     
            unsigned int8 claveOk = 1;//con esta variable defino que es correcta la contraseña
            delay_ms(150); //para que se vea por un instante todos los **** de la lcd
            for(int x = 0; x <4; x++){//recorro los array, revisando su contenido
               if(clave[x] != claveRecibida[x]){//en caso que un digito sea diferente, entra y
                  claveOk = 0;// si la clave no es correcta, se asigna un 0
               }
            }
            
            if(claveOk == 1){ //si la clave fue correcta, entra a esta seccion
               claveOk = 1;// reinicio la variable que dice si la clave es correcta o no
               printf(lcd_putc, "\fAbriendo\nescotilla");
               output_high(PIN_C0);//activando motor
               delay_ms(1000);
               output_low(PIN_C0);//apago el motor
               printf(lcd_putc, "\fEl tesoro\nes tuyo");
               delay_ms(1000);
               printf(lcd_putc,"\fBienvenido\nDigite la clave");
            }else{//entra al else si la contraseña fue incorrecta
               printf(lcd_putc, "\fClave Incorrecta");
               delay_ms(300);
               printf(lcd_putc,"\fBienvenido\nDigite la clave");
            }
            position = 0;
         }
      }
   }

}
