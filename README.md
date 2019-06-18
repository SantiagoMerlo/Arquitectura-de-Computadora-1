# Arquitectura-de-Computadora-1
Programa en C que busca simular los drivers de 8 leds.
concignas:
Descomponer el archivo.
Main.c --> deberia generar un main.o (objeto)
Funcion_1.c --> deberia convertirse en funcion_1.o
.
.
.
comando linuk
con $ gcc se linkea --> 
1) $gcc -g -c <<archivo de.c>>
-g// informacion para debugear
-c// genera.0
-o// cambia de nombre
 
 2) hacer lo mismo para todos los .c
 
 3)$ gcc -g <<archivo1>> <<archivo2>> <<archivo3>> ... -o proyecto
  
  
  EasyPIO.h --> se puede incluir o generar un objeto y linkearlo todo junto

pioInit --> sirve para acceder a puerto de memoria para el sistema operativo --> se necesita utilizar el SUDO porque esta protegido


void delayMillis(int millis); //(1000 = 1 seg)

para llamar a la funcion se necesita B <<rotulo>>
