.text
.global main
.type main, %function

main:
    push{r3,lr}
    bl Game
    pop{r3,lr}
   


