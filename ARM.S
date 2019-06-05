. global main
main:

                                    ;;;;; Funcion Main
    MOV R2, #0                      ; seteo caso base
    SUB R1, R1, #1                  ; empezar con posición 0
    LSL R1, #2                      ; multiplica por 4 - lsl multiplica por 2 y #2 determina 
    LDR PC, [R2,R1, LSL #2]         ;Posicion a buscar


    
    MOV R0,#1 ; VALOR DE R1 a graficar
    BL output ;llamado de la funcion
    


output:                             ;;;;;;Funcion Output

       
        MOV PC,LR
        
        
        
                                    ;;;;;Funcion Delay(R1)
Delay:
    MOV RO,0x4fffff                 ;Instancia R0
LOOP:                               ;Inicio WHILE
    SUBS R0,R0,#1
    BNE LOOP                        ;Fin While
    SUBS R1,R1,#1                   
    BNE Delay                       ;Funciona como for/fin for
    MOV PC,LR
