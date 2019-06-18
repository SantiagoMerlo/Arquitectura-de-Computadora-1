#ifndef ARQUITECTURA_COMPUTADORA_H
#define ARQUITECTURA_COMPUTADORA_H

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
