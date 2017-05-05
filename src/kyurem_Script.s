.text
.thumb
.align 2

.include "defines/asm_defines.s"
.include "defines/xse_commands.s"

.global kyurem_script

kyurem_script:
lock
special 0xA2
waitstate
bufferpartypokemon 0x1 0x8004
callasm check_and_fuse_kyurem+1
release
end
