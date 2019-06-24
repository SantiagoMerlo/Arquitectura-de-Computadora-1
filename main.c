#include "output.h"

    char password[6];
    char letra;
    
////Valor global del delay
    int tiempo = 12;


////////////////////tablas de datos //////////////////////////////////
unsigned char TablaAf []= {0x01, 0x02, 0x04,0x08,0x10, 0x20, 0x40, 0x80};
unsigned char TablaCh []= {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};
unsigned char TablaCa []= {0x01, 0x01 ,0x03, 0x03, 0x05, 0x05, 0x09, 0x09, 0x11,0x12,0x24,0x28,0x50,0x60,0x40,0x80};
unsigned char TP[] = {0x88, 0x48, 0x28, 0x18, 0x14, 0x12, 0x12, 0x14, 0x18,0x28,0x48,0x48, 0x28,0x18,0x14,0x14,0x18,0x28,0x28,0x18,0x18,0x18};


/////////////////Comprobar Contraseña///////////////////////////
int ingreso(){	
    initscr();
    noecho();
    printw("Ingrese clave: ");
    for(int i=0; i<3;i++){
        char c;
        char temp[5];
        for(int i = 0; i < 5; i++){
            c = getch();
            temp[i] = c;
            printw("*");
        }
        printw("\r                      ");
        fflush(stdout);
    if(strcmp(temp, password)==0){
        printw("\r");
        echo();
        endwin();
        return 1; 
    }
    printw("\rPrueba de nuevo: ");
   }
    printw("\r                         ");
    printw("\r");
    fflush(stdout);
    echo();
    endwin();
    return 0;
}

int press_key() {
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    switch (getch()) {
        case 'a':
            return 0;
        case KEY_UP:
            if(tiempo > 0) tiempo--;
            break;
        case KEY_DOWN:
            if(tiempo < 30) tiempo++;
            break;
    }
    return 1;
    nocbreak();
}


///////////////// Delay de todas las funciones ///////////////////
void delay(int a){
  for(int j=0;j<a;j++)
  {
    unsigned int i = 0x2fffff; //raspberry 0x3fffff
    while(i)i--;
  };
};

//////////////////Autofantastico por Tabla /////////////////////
void AutofantasticoT() 
{
    initscr();
    noecho();
    while(1){ 
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaAf[i];
            output(valor);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
        for (int i = 7; i>0; i-- )
        {
            int valor = TablaAf[i];
            output(valor);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
    };
};

/////////////////////Autofantastico Algoritmo ///////////////////////////////////////
void Autofantastico(){
  while(1){
        initscr();
        noecho();
        for(int i = 1; i<=128; i=i*2) 
        {
            output(i);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
        for(int i = 64; i>0 ; i=i/2){ 
            output(i);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
            
        };
    };
};

/////////////////Funcion Carrera hecha con tabla //////////////////
void Carrera()
{
    initscr();
    noecho();
    while(1){
        for (int i = 0; i<16; i++ )
        {
            int valor = TablaCa[i];
            output(valor);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
    };
};
//////////////// Algoritmo choque hecho por tabla (no se puede de otra forma)//////////
void ChoqueT()
{
    initscr();
    noecho();
    while(1){
        for (int i = 0; i<8; i++ )
        {
            int valor = TablaCh[i];
            output(valor);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
    };
};
///////////////////Pantalla de Carga, es aun Algoritmo nuestro hecho con tabla/////////////

extern void cuna_newton();

/*
void cuna_newton()
{
    initscr();
    noecho();
    while(1){
        for (int i = 0; i<22; i++ )
        {
            int valor = TP[i];
            output(valor);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
        
    };
};
*/
/////////////////Algoritmo Propio que consiste en la pantalla de carga de los juegos viejos///////////

extern void video_game();
/*
void video_game(){
    initscr();
    noecho();
    while(1){
        int b[8];
        b[0]=1;
        output(b[0]);
        delay(tiempo);
        for(int i = 1; i < 8; i++){
            b[i] = b[0] + pow(2,i);
            output(b[i]);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
        };
        int k = 7;
        for(int j= 1 ; j<8 ; j++){
            b[0]= b[1];
            output(b[1]);
            delay(tiempo);
            if(press_key() == 0){
                echo();
                endwin();
                return;
            } 
            for(int i = 1; i<k ;i++){
                b[i]= b[i+1] + pow(2,j);
                output(b[i]);
                delay(tiempo);
                if(press_key() == 0){
                    echo();
                    endwin();
                    return;
                } 
            };
            k--;
        };
    };
};
*/
int main()
{
    pioInit();
    strcpy(password, "14863");
    if(!ingreso()){
        printf("Se acabaron los intentos\n");
        return 0;
    }
    while(1){
        system("clear");
        printf("///////////Menu///////////\n");
        printf("1. Autofantastico \n");
        printf("2.Choque\n");
        printf("3.Carrera\n");
        printf("4.Carga de videojuegos \n");
        printf("5.Cuna de Newton\n");        
        printf("6.Salir\n");
        int opcion;
        do
        {
            scanf("%i", &opcion);
        }while (opcion<1 || opcion>6);
        system("clear");
        switch(opcion) {
            case 1 :
                AutofantasticoT();
                break;
            case 2:
                ChoqueT();
                break;
            case 3:
                Carrera();
                break;
            case 4 :
                video_game();
                break;
            case 5 :
                cuna_newton();
                break;
            case 6 :
                return 1;
                break;
            
        }
    }
}
