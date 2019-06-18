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
  for(int i=0; i<8; i++)
  {
    if(a%2==0)
      printf("_");
    else
      printf("*");
    a=a/2;
  }
    printf("\r");
    fflush(stdout);
};

#endif
