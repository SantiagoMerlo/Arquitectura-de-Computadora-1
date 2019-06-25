.text

.extern press_key
.extern output
.extern delay
.extern tiempo
.global video_game

video_game:
	PUSH {R4-R7, LR}
_game_init:
	MOV R4,#0 	//para bucle a
	LDR R6,=arreglo	//arreglo principal
_game_move:
	BL press_key
	CMP R0, #1	//1 no exit, 0 exit
	BNE _game_out
	MOV R0,#1
	STRB R0,[R6]	//cargamos en R6(+R4) el dato de R0 --> STRB R0,[R6,#0]
	BL output	
	LDR R0,=tiempo	//Velocidad del delay, modificado en press_key
	BL delay
loop:			//En este loop se definen los valores de el arreglo
	MOV R1,#1	//instanciamos el valor a elevar
	ADD R4,R4,#1	//aumenta el contador
	MOV R5,R4	//aux
potencia:
    	ADD R1,R1,R1 	//obtengo 2 elevado a R4 --> si R4 vale 3 se repite 3 veces= 1+1 = 2, 2+2= 4, 4+4= 8==2´3
    	SUBS R5,R5,#1 	//cuantas veces se va a elevar a la potencia
BNE potencia		//condicion de salida, R5 = 0
	BL press_key
	CMP R0, #1
	BNE _game_out	
	STRB R1,[R6,R4]	//cargo los valores en mi arreglo
	MOV R0,R1
	BL output
	LDR R0,=tiempo
	BL delay
	CMP R4,#7 	//contador, empieza en el loop con 1
BNE loop
	MOV R7,#1	//repetidor de procesos --> int k=1;
general:		//Segunda parte del proceso while(k<8)
	MOV R4,R7	//int j = 0 ; j < 8; j++
loop2:
	LDRB R1,[R6,R7]	//cargamos en R1 el valor que se encuentra en el arreglo/ R7 CONSTANTE EN EL PROCESO
	SUB R1,R1,#1	//resta para obtener la segunda fila
	LDRB R0,[R6,R4]	//cargamos el valor a calcular
	ADD R0,R0,R1	// si teniamos un R0 = 00000010 + R1= 11100000 = 11100010
	BL output
	LDR R0,=tiempo
	BL delay
	BL press_key
	CMP R0, #1
	BNE _game_out
	ADD R4,R4,#1	//contador j++
	CMP R4,#8
BNE loop2
	ADD R7,R7,#1	//contador k++
	CMP R7,#8
BNE general
B _game_init

_game_out:
	POP {R4-R7, PC}

.data
arreglo:	// 	filtro		valor anterior menos uno
      .byte 0	//1 --> 10000000 -->	00000000
      .byte 1	//2 -->	01000000 -->	10000000			
      .byte 2	//4 --> 00100000 -->	11000000
      .byte 3	//8 --> 00010000 -->	11100000
      .byte 4	//16--> 00001000 -->	11110000
      .byte 5	//32--> 00000100 -->	11111000
      .byte 6	//64--> 00000010 -->	11111100
      .byte 7	//128-> 00000001 -->	11111110
.end

//*

.text

.extern press_key
.extern output
.extern delay
.extern tiempo
.global video_game

video_game:
	PUSH {R4-R7, LR}
_game_init:
	MOV R4,#0 
_game_move:
	BL press_key
	CMP R0, #1
	BNE _game_out
	MOV R0,#1
	BL output	
	LDR R0,=tiempo
	BL delay
loop:
	ADD R4,R4,#1
        MOV R1,#1
	MOV R5,R4	
        MOV R2,#0            
        B potencia
cond_a:	
	MOV R0,R1
        BL output
        BL press_key
	CMP R0,#1
	BNE _game_out
	LDR R0,=tiempo
	BL delay
	CMP R4,#7 	 
        BNE loop
	MOV R7,#1
general:	
	MOV R3,R7
loop2:
        MOV R1,#1
        MOV R2,#1
        MOV R5,R7
        B potencia
cond_b:
        MOV R6,R1
        SUB R6,R6,#1
        MOV R5,R3
        MOV R2,#2
        MOV R1,#1
	B potencia
cond_c:
	ADD R0,R6,R1
	BL output
	LDR R0,=tiempo
	BL delay
	BL press_key
	CMP R0,#1
	BNE _game_out
	ADD R3,R3,#1
	CMP R3,#8
        BNE loop2
	ADD R7,R7,#1	//contador k++
	CMP R7,#8
        BNE general
        B _game_init

potencia:                //r5 la cantidad de veces que se eleva
    	ADD R1,R1,R1
    	SUBS R5,R5,#1
        BNE potencia
        CMP R2,#0
        BEQ cond_a
        CMP R2,#1
        BEQ cond_b
        B cond_c
_game_out:
	POP {R4-R7, PC}
.data

.end


*//

   
