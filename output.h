#ifndef ARQUITECTURA_COMPUTADORA_H
#define ARQUITECTURA_COMPUTADORA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

//output estandar, convierte cualquier numero 
//decimal/Hexa a binario pero al revez (osea 1 = 1000000)
////////////////////Mostrar de la funcion //////////////////////

void output(unsigned char a) 
{
    const char led[] = {7, 8, 25, 24, 23, 18, 15, 14};
    const char sw[] = {12,16,20,21};
    for(int i=0; i<8; i++)
    {
        if(a%2==0){
            printf("_");
            //digitalWrite(led[i], 1);
        }
            
        else{
            printf("*");
            //digitalWrite(led[i], 0);
        }
    a=a/2;
  }
  printf("\r");
  fflush(stdout);

 
};

#endif
