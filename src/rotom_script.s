
rotom_main:
lock
msgbox appliance_detection_string MSG_KEEPOPEN
closeonkeypress
callasm find_rotom
compare 0x800D 0x0
if 0x1 goto finish_rotom_menu
compare 0x800D 0x2
if 0x1 goto choose_candidate_rotom

investigation_prompt:
bufferpartypokemon 0x1 0x8004
msgbox rotom_investigation_string MSG_KEEPOPEN
closeonkeypress
msgbox investigation_prompt_string MSG_YESNO
compare 0x800D 0x0
if 0x1 goto finish_rotom_menu
preparemsg appliance_choice_string
waitmsg
multichoice 0xF 0x0 0xD 0x0
compare 0x800D 0x6
if 0x1 goto finish_rotom_menu
callasm rotom_change
compare 0x800D 0x0
if 0x1 goto rotom_already_in_motor
compare 0x800D 0x4
if 0x1 goto rotom_already_out_of_motor
compare 0x800D 0x3
if 0x1 goto delete_move_after_revert
copyvar 0x8007 0x800D
msgbox entered_motor_string MSG_KEEPOPEN
closeonkeypress
compare 0x8007 0x2
if 0x1 goto rotom_learn_special_move
special 0xE0
bufferattack 0x2 0x8003
msgbox forgot_special_move_string MSG_KEEPOPEN
closeonkeypress

rotom_learn_special_move:
callasm rotom_determine_special_move
compare 0x8006 0x0
if 0x1 goto finish_rotom_menu
special 0xE2
compare LASTRESULT 0x4
if 0x1 goto rotom_move_delete_prompt
goto learned_special_move

learned_special_move:
callasm rotom_learn_special_move
bufferattack 0x2 0x8006
fanfare 0x101
msgbox learn_special_move_string MSG_KEEPOPEN
waitfanfare
closeonkeypress
goto finish_rotom_menu

finish_rotom_menu:
release
end

rotom_move_delete_prompt:
bufferattack 0x2 0x8006
msgbox try_to_learn_move_string MSG_YESNO
compare LASTRESULT 0x0
if 0x1 goto revert_for_not_learning_new_move
special 0xDF
waitstate
compare 0x8005 0x3
if 0x2 goto finish_rotom_menu
msgbox pff_move_string MSG_KEEPOPEN
closeonkeypress
callasm store_move_to_var8003_from_var8005_in_slot_var8004
bufferattack 0x2 0x8003
special 0xE0
bufferpartypokemon 0x1 0x8004
msgbox forgot_special_move_string MSG_KEEPOPEN
closeonkeypress
callasm rotom_determine_special_move
goto learned_special_move

rotom_already_in_motor:
msgbox already_appliance_string MSG_KEEPOPEN
closeonkeypress
goto finish_rotom_menu

rotom_already_out_of_motor:
msgbox not_in_motor_string MSG_KEEPOPEN
closeonkeypress
goto finish_rotom_menu

delete_move_after_revert:
bufferattack 0x2 0x8003
special 0xE0
setvar 0x8006 0x0
callasm rotom_learn_special_move
msgbox left_motor_string MSG_KEEPOPEN
closeonkeypress
msgbox forgot_special_move_string MSG_KEEPOPEN
closeonkeypress
callasm rotom_determine_special_move
compare 0x8006 0x0
if 0x1 finish_rotom_menu
callasm rotom_learn_special_move
goto finish_rotom_menu

revert_for_not_learning_new_move:
setvar 0x800D 0x5
callasm rotom_change
msgbox left_motor_string MSG_KEEPOPEN
closeonkeypress
goto finish_rotom_menu

choose_candidate_rotom:
special 0xA2
waitstate
callasm check_chosen_rotom
compare 0x800D 0x1
if 0x1 _goto investigation_prompt
msgbox not_valid_rotom_msg MSG_KEEPOPEN
closeonkeypress
goto finish_rotom_menu

'---------
' Strings
'---------
#org appliance_detection_string
= It's full of cardboard boxes with\nelectrical appliances in them.

#org rotom_investigation_string
= Oh? [buffer2] would like to\ninvestigate the motors of\pthe electrical appliances....

#org investigation_prompt_string
= Is that OK?

#org appliance_choice_string
= Which appliance's motor will you allow\n[buffer2] to enter?

#org entered_motor_string
= [buffer2] entered the motor.

#org left_motor_string
= [buffer2] emerged from the motor.

#org forgot_special_move_string
= [buffer2] forgot [buffer3]!

#org learn_special_move_string
= [buffer2] learned [buffer3]!

#org try_to_learn_move_string
= [black_fr][buffer2] is trying to\nlearn [buffer3].\pBut, it can't learn\nmore than four moves.\pDelete a move to make\nroom for [buffer3]?

#org pff_move_string
= \c\h08�1, \c\h08�2, and\c\h08�[.] \c\h08�[.] \c\h08�[.] \c\h08�\c\h10\h31 Poof!

#org already_appliance_string
= This Rotom has already entered\nthat appliance motor.

#org not_in_motor_string
= [buffer2] hasn't entered a motor.

#org not_valid_rotom_msg
= Not a valid rotom.