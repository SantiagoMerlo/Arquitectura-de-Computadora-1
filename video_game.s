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
	LDR R0,[R0]
	BL delay
	B loop
loop:				//mostrar "autofantastico"
	ADD R4,R4,#1
        MOV R1,#1		//valor de funcion imput/output
	MOV R5,R4		// 2 elevado a r4
        MOV R2,#0            	// tipo de salida
        B potencia
cond_a:				//condicion de tipo 0
	MOV R0,R1
        BL output
        BL press_key
	CMP R0,#1
	BNE _game_out
	LDR R0,=tiempo
	LDR R0,[R0]
	BL delay
	CMP R4,#7 	 
        BNE loop		//--> Return loop
	MOV R7,#1		//int k=1
	B general
general:	
	MOV R3,R7		//contador j
	B loop2
loop2:
        MOV R1,#1
        MOV R2,#1
        MOV R5,R7
        B potencia
cond_b:				//condicion de tipo 1
        MOV R6,R1
        SUB R6,R6,#1		//arreglo - 1 = todas las luces prendidas desde un punto
        MOV R5,R3
        MOV R2,#2
        MOV R1,#1
	B potencia
cond_c:				//condicion de tipo obligatoria (tipo 2)
	ADD R0,R6,R1
	BL output
	LDR R0,=tiempo
	LDR R0,[R0]
	BL delay
	BL press_key
	CMP R0,#1
	BNE _game_out
	ADD R3,R3,#1		//j++
	CMP R3,#8
        BNE loop2
	ADD R7,R7,#1		//contador k++
	CMP R7,#8
        BNE general
        B _game_init
	
	
potencia:			//funcion calcular potencia de 2
    	ADD R1,R1,R1
    	SUBS R5,R5,#1
        BNE potencia
        CMP R2,#0
        BEQ cond_a		//--> salida a primer loop
        CMP R2,#1
        BEQ cond_b		//salida para valor de arreglo menos uno
        B cond_c		//salida para valor arreglo
	
	
_game_out:
	POP {R4-R7, PC}
.data
.end


/* intento 1 con arreglo
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
*/

   
