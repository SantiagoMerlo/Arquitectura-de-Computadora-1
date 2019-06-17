#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

#define letra_a 97 

    char password[6];
    char letra;
    
////Valor global del delay
    int tiempo = 15;


////////////////////tablas de datos //////////////////////////////////
int TablaAf [8]= {1, 2, 4, 8, 16, 32, 64, 128};
int TablaCh [8]= {129, 66, 36, 24, 24 , 36 , 66, 129};
int TablaCa [16]= {1, 1 ,2, 2, 4, 4, 8, 8, 16, 17, 34, 36, 72, 80, 192, 128};
int TablaCarga[10]={1 ,3 , 7, 15, 15, 31, 31, 63,127,255};


/////////////////Comprobar Contraseña///////////////////////////
int ingreso(){	
    for(int i=0; i<3;i++){
       
        char c;
        char temp[5];
        initscr();
        noecho();
        for(int i = 0; i < 5; i++){
            c = getch();
            temp[i] = c;
            printw("*");
        }
    echo();
    endwin();
    if(strcmp(temp, password)==0)
        return 1;
    printf("Prueba de nuevo\n");
   }
   return 0;
};

///////////////// Delay de todas las funciones ///////////////////
void delay(int a){
  for(int j=0;j<a;j++)
  {
    unsigned int i = 0x4fffff; //raspberry 0x3fffff
    while(i)i--;
  };
  //system("clear");
  
};

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

//output de choque --> uno especial
void outputCh(unsigned char a)
{
    char b[5]; 
    for(int i=0; i<4 ; i++)
    {
        if(a%2==0){
            printf("_");
            b[i] = '_';
        }
        else{
            printf("*");
            b[i] = '*';
        }
          a=a/2;  
    }; //Va marcando el camino y cuando llega a este punto lo muestra al revez
    for(int j=4; j>=0;j--)
    {
      printf ("%c", b[j]);
    };
    printf("\r");
    fflush(stdout);
 
}
//////////////////Autofantastico por Tabla /////////////////////
void AutofantasticoT() 
{
    while(1){ ///--------------------> falta la tecla que hay que precionar
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaAf[i];
            output(valor);
            delay(tiempo);
        };
        for (int i = 8; i>0; i-- )
        {
            int valor = TablaAf[i];
            output(valor);
            delay(tiempo);
            //if( press_key ) return;  
        };
    };
}

///////////////Algoritmo de Choque, tiene un Outpu especial (outputCh)////////
void Choque(){
  while(1){
        for(int i = 1; i<=8; i=i*2)
        {
            outputCh(i);
            delay(tiempo);
            //if( press_key ) return;
        };
        for(int i = 8; i>=1; i=i/2)
        {
            outputCh(i);
            delay(tiempo);
            //if( press_key ) return;
        };
    };
}
/////////////////////Autofantastico Algoritmo ///////////////////////////////////////
void Autofantastico(){
  while(1){
        for(int i = 1; i<=128; i=i*2) 
        {
            output(i);
            delay(tiempo);
            //if( press_key ) return;
        };
        for(int i = 64; i>0 ; i=i/2){ 
            output(i);
            delay(tiempo);
            //if( press_key ) return;
        };
    };
}

/////////////////Funcion Carrera hecha con tabla //////////////////
void Carrera()
{
    while(1){
        for (int i = 0; i<16; i++ )
        {
            int valor = TablaCa[i];
            output(valor);
            delay(tiempo);
            //if( press_key ) return;
        };
    };
};
//////////////// Algoritmo choque hecho por tabla (no se puede de otra forma)//////////
void ChoqueT()
{
    while(1){
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaCh[i];
            output(valor);
            delay(tiempo);
            //if( press_key ) return;
        };
    };
};
///////////////////Pantalla de Carga, es aun Algoritmo nuestro hecho con tabla/////////////
void Cargando()
{
    while(1){
        for (int i = 0; i<10; i++ )
        {
            int valor = TablaCarga[i];
            output(valor);
            delay(30);
            //if( press_key ) return;
        };
    };
};
/////////////////Algoritmo Propio que consiste en la pantalla de carga de los juegos viejos///////////
void Game(){
  while(1){
        int b[8];
        b[0]=1;
        output(b[0]);
        delay(tiempo);
        for(int i = 1; i < 8; i++){
            b[i] = b[0] + pow(2,i);
            output(b[i]);
            delay(tiempo);
        };
        int k = 7;
        for(int j= 1 ; j<8 ; j++){
            b[0]= b[1];
            output(b[1]);
            delay(tiempo);
            for(int i = 1; i<k ;i++){
                b[i]= b[i+1] + pow(2,j);
                output(b[i]);
                delay(tiempo);
            };
            k--;
        };
    };
};

int main()
{
    printf("Introduzca la Contraseña de usuario \n");
    strcpy(password, "14863");
    if(ingreso())
        printf("Constraseña Correcta\n");
    else
    {
        printf("Se te acabaron los intentos\n");
        return 0;
    }
    while(1){
        printf("///////////Menu///////////\n");
        printf("1. Autofantastico \n");
        printf("2.Choque \n");
        printf("3.Choque con Tabla\n");
        printf("4.Carrera con tabla \n");
        printf("5.Juego de carga\n");        
        printf("6.Pantalla de carga\n");
        printf("7.Salir\n");
        int opcion;
        do
        {
            scanf("%i", &opcion);
        }while (opcion<1 || opcion>7);
        system("clear");
        switch(opcion) {
            case 1 :
                Autofantastico();
                break;
            case 2:
                Choque();
                break;
            case 3:
                ChoqueT();
                break;
            case 4 :
                Carrera();
                break;
            case 5 :
                Game();
                break;
            case 6 :
                Cargando();
                break;
            case 7:
                return 1;
                break;
        }
    }