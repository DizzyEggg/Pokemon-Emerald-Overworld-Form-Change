.text
.thumb

.include "defines/asm_defines.s"
.include "defines/xse_commands.s"


shaymin_script:
lock
msgbox 0 MSG_KEEPOPEN
closeonkeypress
special 0xA2
waitstate
callasm check_shaymin+1
compare 0x800D 0x0
if 0x1 _goto @not_affecting_dud
msgbox 0 MSG_KEEPOPEN
closeonkeypress
callasm shaymin_change_species+1
release
end

not_affecting_dud:
msgbox 0 MSG_KEEPOPEN
closeonkeypress
release
end

