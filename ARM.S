section	.text
	global _start       ;must be declared for using gcc
_start: 
;r1 -->  
;r2 --> arreglo
;r3 --> para el for j
;r4 --> numero a calcular la potencia
;r5 --> temporal para calcular potenncia

;r6 --> valor i incremental
;r7 --> int k
;r8 --> temporal general
    MOV r3,#8    ; Int j = 1
    MOV r2[0],#1  ;B[0] = 1
    mov r8,#1  ;j=1
    MOV r7,#7
    MOV r1,r2[0] ; manda a r1 como parametros 
    BL output
    MOV r1,1000 ;manda r1 como parametro
    BL delay
loop: ;primer for
    MOV r5,r3
potencia:
    ADD r4,r4,r4 ;R4 lo llevo a la 2
    SUBS r5,#1  ;cuantas veces se va a elevar a la potencia
BNE potencia
    ADD r2[r8],r2[0],r4 ;guardar y mostrar el primer proceso
    mov r1,r2[r6]
    BL output ;mostrar valor de r1
    ADD r8,r8,#1
    SUBS r3,r3,#1
BNE loop
    ;cuando termina esto, el r8 y r3 se libera; r5 tenemos que reiniciarlo
loop2:
    
    
	

section	.data

msg	db	'Hello, world!',r1	;our dear string
len	equ	$ - msg			;length of our dear string
   


