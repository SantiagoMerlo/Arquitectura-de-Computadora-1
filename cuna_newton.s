.text

.extern press_key
.extern output
.extern delay
.extern tiempo
.global cuna_newton

cuna_newton:
      PUSH {R4-R5, LR}
      
_newton_init:
     MOV R4, #0 //contador
     
_newton_move:
     ADD R4, R4, #1
     LDR R5, =_VALUES
     LDRB R5, [R5, R4]
     BL press_key
     CMP R0, #1 //Si es igual a 1 no sale
     BNE _newton_out // return
     MOV R0, R5 
     BL output // output(values[r5])
     LDR R0, =tiempo
     LDR R0, [R0]
     BL delayMillis
     CMP R4, #22 // table size
     BEQ _newton_init
     B _newton_move
     
_newton_out:
     POP {R4-R5, PC}
     
.data
_VALUES:
      .byte 0x88
      .byte 0x48
      .byte 0x28
      .byte 0x18
      .byte 0x14
      .byte 0x12
      .byte 0x12
      .byte 0x14
      .byte 0x18
      .byte 0x28
      .byte 0x48
      .byte 0x48
      .byte 0x28
      .byte 0x18
      .byte 0x14
      .byte 0x14
      .byte 0x18
      .byte 0x28
      .byte 0x28
      .byte 0x18
      .byte 0x18
      .byte 0x18
.end
