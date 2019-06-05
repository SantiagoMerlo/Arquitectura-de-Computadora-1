#include <stdio.h>
#include <stdlib.h>

////////////////////tablas de datos //////////////////////////////////
int TablaAf [8]= {1, 2, 4, 8, 16, 32, 64, 128};
int TablaCh [8]= {129, 66, 36, 24, 24 , 36 , 66, 129};
int TablaCa [16]= {1, 1 ,2, 2, 4, 4, 8, 8, 16, 17, 34, 36, 72, 80, 192, 128};

///////////////// Delay de todas las funciones ///////////////////
void delay(int a){
  for(int j=0;j<a;j++)
  {
    unsigned int i = 0x4fffff; //raspberry 0x3fffff
    while(i)i--;
  };
};

//output estandar, convierte cualquier numero 
//decimal/Hexa a binario pero al revez (osea 1 = 1000000)

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
  printf("\n");
 
};

//output de choque --> uno especial
void outputCh(int a)
{
    char b[4]; 
    for(int i=0; i<4;i++)
    {
        if(a%2==0){
            printf("_");
            b[i] = "_";
        }
        else{
            printf("*");
            b[i] = "*";
        }
          a=a/2;  
    }; //Va marcando el camino y cuando llega a este punto lo muestra al revez
    for(int j=4; j>0;j--)
    {
      printf(b[j]);
    };
    printf("\n");
 
};

void AutofantasticoT() //Autofantastico con tabla
{
    while(1){ ///--------------------> falta la tecla que hay que precionar
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaAF[i];
            output(valor);
            delay(20);
            //if( press_key ) return;
        };
        for (int i = 8; i>0; i-- )
        {
            int valor = TablaAF[i];
            output(valor);
            delay(20);
            //if( press_key ) return;  
        };
    };
};

//algoritmo de Choque, se modifico el output para que sea mas sensillo
void Choque(){
  while(1){
        for(int i = 1; i<=24; i=i*2)
        {
            outputCh(i);
            delay(10);
            //if( press_key ) return;
        };
        for(int i = 24; i>=1; i=i/2)
        {
            outputCh(i);
            delay(10);
            //if( press_key ) return;
        };
    };
};
void Autofantastico(){
  while(1){
        for(int i = 1; i<=64; i=i*2) //si salta un error aca hay que sacar el i*2 y ponerlo abajo del if
        {
            output(i);
            delay(10);
            //if( press_key ) return;
        };
        for(int i = 64; i>0 ; i=i/2){ //si salta un error aca hay que sacar el i/2 y ponerlo abajo del if
            output(i);
            delay(10);
            //if( press_key ) return;
        };
    };
};

//HECHO CON TABLA
void Carrera()
{
    while(1){
        for (int i = 0; i<16; i++ )
        {
            int valor = TablaCa[i];
            output(valor);
            //if( press_key ) return;
        };
    };
};
//HECHO CON TABLA
void ChoqueT()
{
    while(1){
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaCh[i];
            output(valor);
            //if( press_key ) return;
        };
    };
};


int main()
{
    printf("///////////Menu///////////\n");
    printf("1. Autofantastico \n");
    printf("2.Choque \n");
    printf("3.Carrera \n");
    int opcion;
    do
    {
        scanf("%i", &opcion);
    }while (opcion<1 || opcion>3);
    
    switch(opcion) {
        case 1 :
            Autofantastico();
            break;
        case 2:
            Choque();
            break;
        case 3:
            Carrera();
            break;
    }
  return 0;

}
