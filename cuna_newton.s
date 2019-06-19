
.text

.global main
main:
      LDR R3, = array // load base address of a into R3
      loop:
          MOV R1,#22
          BL output
          SUBS R1,R1,#1
          ;BNE loop
          
      BL 
done: NOP            // dummy instruction for breakpoint instruccion boba, que no hace nada
      BX LR          // return from main

.data
array:
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
