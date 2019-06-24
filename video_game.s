.text

.extern press_key
.extern output
.extern delay
.extern tiempo
.global video_game


video_game:
	PUSH {R4-R7, LR}
_game_init:
	MOV R4,#0 	;para bucle a
	LDR R6, arreglo	;arreglo principal
_game_move:
	BL press_key
	CMP R0, #1
	BNE _game_out
	MOV R0,#1
	STRB R0,[R6]	;cargamos el primer valor
	BL output
	LDR R0,=tiempo
	BL delay
loop:
	MOV R0,#1	;instanciamos el valor a elevar
	ADD R4,R4,#1	;aumenta el contador
	MOV R5,R4
potencia:
    	ADD R0,R0,R0 	;obtengo 2 elevado a R4
    	SUBS R5,#1 	;cuantas veces se va a elevar a la potencia
BNE potencia
	STRB R0,[R6,R4]	;cargo los valores en mi arreglo
	BL output
	BL delay
	BL press_key
	CMP R0, #1
	BNE _game_out
	LDR R0,=tiempo
	CMP R4,#7 ;contador, empieza en el loop con 1
BNE loop
	MOV R7,#0	;repetidor de procesos
general:
	MOV R4,#0	; int j = 0 ; j < 8; j++
loop2:
	LDRB R1,[R6,R7]	;cargamos en r1 el valor que se encuentra en el arreglo/ R7 CONSTANTE EN EL PROCESO
	LDRB R0,[R6,R4]	;cargamos el valor a calcular
	ADD R0,R0,R1
	BL output
	BL delay
	BL press_key
	CMP R0, #1
	BNE _game_out
	LDR R0,=tiempo
	ADD R4,R4,#1
	CMP R4,#7
BNE general
	ADD R7,R7,#1
	CMP R7,#6
BNE loop2
B _game_init

_game_out:
	POP {R4-R7, PC}

.data
arreglo:
      .byte 0,1,2,3,4,5,6,7
.end

   
