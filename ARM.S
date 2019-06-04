. global main
main:
    
    MOV R1,#1 ; VALOR DE R1 a graficar
    BL output ;llamado de la funcion
    


output:

        SUB SP,SP,#8 ;Salvando
        STR R4,[SP,#4]
        STR R5,[SP]
        ADD R4,R4,#8    ;comienzo del for
        MOV R5,R1     ; valor para trabajar
    loop:
    div:
        SUB R5,R5,#2
        CMP R5,#2
        BGT div ;si es mayor a 2 sigue restandose
        CMP R5,#0
        EQ "*"
        NE "_"
    ROR ; ERA PARA RESTAR 
    
    
    
    
    
    
        SUBS R4,R4,#1
    BNE loop
        LDR R5,[SP]
        LDR R4,[SP,#4]
        ADD SP, SP,#8
        MOV PC,LR
