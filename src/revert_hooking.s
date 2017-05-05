.text
.align 2
.thumb

revert_hook:

add r1, r1, r2
bl hoopa_revert_logic
ldr r3, =0x80CE0D8|1
bx r3
