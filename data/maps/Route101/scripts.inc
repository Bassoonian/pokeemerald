Route101_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_MapScript1_1EBCC5
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_MapScript2_1EBCCB
	.byte 0

Route101_MapScript1_1EBCC5: @ 81EBCC5
	@ call Route101_EventScript_2720AD
	call Common_EventScript_SetupRivalGender
	end

Route101_MapScript2_1EBCCB: @ 81EBCCB
	@ map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_1EBCD5
	.2byte 0

Route101_EventScript_1EBCD5:: @ 81EBCD5
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route1_Prof1::
	call Route1_ProfA
	applymovement 2, R1ProfMov0A
	waitmovement 0
	call Route1_ProfB
	applymovement 2, R1ProfMov3A
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, R1PlayMovA
	applymovement 2, R1ProfMov4A
	waitmovement 0
	goto Route1_ProfC
	end

Route1_Prof2::
	call Route1_ProfA
	applymovement 2, R1ProfMov0B
	waitmovement 0
	call Route1_ProfB
	applymovement 2, R1ProfMov3A
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, R1PlayMovB
	applymovement 2, R1ProfMov4B
	waitmovement 0
	goto Route1_ProfC
	end

Route1_Prof3::
	call Route1_ProfA
	call Route1_ProfB
	applymovement 2, R1ProfMov3B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, R1PlayMovC
	applymovement 2, R1ProfMov4C
	waitmovement 0
	goto Route1_ProfC
	end

Route1_Prof4::
	call Route1_ProfA
	applymovement 2, R1ProfMov0C
	waitmovement 0
	call Route1_ProfB
	applymovement 2, R1ProfMov3B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, R1PlayMovD
	applymovement 2, R1ProfMov4D
	waitmovement 0
	goto Route1_ProfC
	end

Route1_ProfA:
	lockall
	setvar VAR_0x4050, 3
	setflag FLAG_SPECIAL_FLAG_0x4000
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 2, R1ProfMov1
	waitmovement 0
	return

Route1_ProfB:
	applymovement 2, R1ProfMov2
	waitmovement 0
	msgbox Route101_Text_1EBE8F, MSGBOX_DEFAULT
	closemessage
	return

Route1_ProfC:
	lockall
	clearflag FLAG_SPECIAL_FLAG_0x4000
	msgbox Route101_Text_1EBE9A, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 2, Common_Movement_WalkInPlaceDown, MAP_ROUTE101
	waitmovement 0, MAP_ROUTE101
	msgbox Route101_Text_New, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement 2, R1ProfMov5, MAP_ROUTE101
	waitmovement 0, MAP_ROUTE101
	addobject 6
	msgbox Route101_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	setflag FLAG_SYS_POKEMON_GET
	fadescreen 1
	special ChooseStarter
	waitstate
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74D
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8B1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E07
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end

Route1_ProfD:
	msgbox Route101_Text_1EBF12, MSGBOX_DEFAULT
	closemessage
	removeobject 2, MAP_ROUTE101
	addobject 5
	applymovement 5, Common_Movement_WalkInPlaceDown
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	releaseall
	end

R1ProfMov5:
	walk_right
	walk_in_place_left
	step_end

R1ProfMov1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

R1ProfMov2:
	walk_right
	step_end

R1ProfMov0A:
	walk_up
	walk_up
	step_end

R1ProfMov0B:
	walk_up
	step_end

R1ProfMov0C:
	walk_down
	step_end

R1ProfMov3A:
	walk_down
	walk_right
	walk_right
	walk_up
	step_end

R1ProfMov3B:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

R1ProfMov4A:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

R1PlayMovA:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

R1ProfMov4B:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

R1PlayMovB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

R1ProfMov4C:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

R1PlayMovC:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

R1ProfMov4D:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

R1PlayMovD:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

R1_Rival1::
	setvar VAR_ROUTE101_STATE, 0
	goto_if_unset FLAG_HIDE_ROUTE_101_ZIGZAGOON, R1_Rival1_reattempt
	call R1_RivalA
	applymovement 4, R1_RivalMove1_a
	waitmovement 0
	goto R1_RivalB
	end

R1_Rival2::
	setvar VAR_ROUTE101_STATE, 1
	goto_if_unset FLAG_HIDE_ROUTE_101_ZIGZAGOON, R1_Rival2_reattempt
	call R1_RivalA
	goto R1_RivalB
	end

R1_RivalA:
	lockall
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	addobject 4
	setobjectxy 4, 13, 14
	clearflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	applymovement 4, R1_RivalMove1
	waitmovement 0
	return

R1_RivalB:
	applymovement 4, R1_RivalMove2
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto Route103_EventScript_1EC3C1
	end

R1_Rival1_reattempt:
	call R1_reattempt
	applymovement 4, R1_RivalNotice2a
	waitmovement 0
	goto R1_Rival_reattempt2
	end

R1_Rival2_reattempt:
	call R1_reattempt
	applymovement 4, R1_RivalNotice2b
	waitmovement 0
	goto R1_Rival_reattempt2
	end

R1_reattempt:
	lockall
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Ev_Play_Mus_Female
	compare VAR_RESULT, FEMALE
	call_if_eq Ev_Play_Mus_Male
	applymovement 4, R1_RivalNotice
	waitmovement 0
	return

Ev_Play_Mus_Male::
	playbgm MUS_BOY_SUP, 1
	return

Ev_Play_Mus_Female::
	playbgm MUS_GIRL_SUP, 1
	return

R1_Rival_reattempt2:
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq R1_rematch_male
	compare VAR_RESULT, FEMALE
	goto_if_eq R1_rematch_female
	end

R1_rematch_male:
	msgbox R1_rematch_may, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_1EC48E
	case 1, Route103_EventScript_1EC49E
	case 2, Route103_EventScript_1EC4AE
	end

R1_rematch_female:
	msgbox R1_rematch_brendan, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_1EC4BE
	case 1, Route103_EventScript_1EC4CE
	case 2, Route103_EventScript_1EC4DE
	end

R1_RivalNotice:
	walk_in_place_up
	emote_exclamation_mark
	step_end

R1_RivalNotice2a:
	walk_up
	step_end

R1_RivalNotice2b:
	walk_right
	walk_up
	step_end

R1_RivalMove1:
	player_run_left
	player_run_left
	player_run_up
	player_run_up
	player_run_up
	player_run_up
	player_run_up
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	player_run_left
	step_end

R1_RivalMove1_a:
	player_run_left
	step_end

R1_RivalMove2:
	player_run_down
	player_run_down
	walk_in_place_fastest_down
	step_end

R1_RivalLeaves:
	setvar VAR_0x4050, 4
	@Movements here
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	end

Route101_EventScript_1EBCDE:: @ 81EBCDE
	lockall
	playbgm MUS_EVENT0, 1
	msgbox Route101_Text_1EBE8F, MSGBOX_DEFAULT
	closemessage
	setobjectxy 2, 0, 15
	setobjectxy 4, 0, 16
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_1EBDC2
	applymovement 2, Route101_Movement_1EBDE7
	applymovement 4, Route101_Movement_1EBDB5
	waitmovement 0
	applymovement 4, Route101_Movement_1EBD96
	applymovement 2, Route101_Movement_1EBDC8
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 4, Route101_Movement_1EBDBD
	applymovement 2, Route101_Movement_1EBDEF
	waitmovement 0
	msgbox Route101_Text_1EBE9A, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_1EBD4E:: @ 81EBD4E
	lockall
	msgbox Route101_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_1EBD90
	waitmovement 0
	releaseall
	end

Route101_EventScript_1EBD64:: @ 81EBD64
	lockall
	msgbox Route101_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_1EBD92
	waitmovement 0
	releaseall
	end

Route101_EventScript_1EBD7A:: @ 81EBD7A
	lockall
	msgbox Route101_Text_1EBEDF, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Route101_Movement_1EBD94
	waitmovement 0
	releaseall
	end

Route101_Movement_1EBD90: @ 81EBD90
	walk_up
	step_end

Route101_Movement_1EBD92: @ 81EBD92
	walk_right
	step_end

Route101_Movement_1EBD94: @ 81EBD94
	walk_down
	step_end

Route101_Movement_1EBD96: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_1EBDB5: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route101_Movement_1EBDBC: @ 81EBDBC
	step_end

Route101_Movement_1EBDBD: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_1EBDC2: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route101_Movement_1EBDC8: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_1EBDE7: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

Route101_Movement_1EBDEE: @ 81EBDEE
	step_end

Route101_Movement_1EBDEF: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_1EBDF4: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route101_Movement_1EBDF7: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_1EBDFB:: @ 81EBDFB
	msgbox Route101_Text_1EBFDD, MSGBOX_NPC
	end

Route101_EventScript_1EBE04:: @ 81EBE04
	msgbox Route101_Text_1EC04A, MSGBOX_NPC
	end

Route101_EventScript_1EBE0D:: @ 81EBE0D
	msgbox Route101_Text_1EC0C8, MSGBOX_SIGN
	end

Route101_EventScript_1EBE16:: @ 81EBE16
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen 1
	removeobject 4
	setobjectxy EVENT_OBJ_ID_PLAYER, 6, 13
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement 2, Route101_Movement_1EBE8D
	waitmovement 0
	msgbox Route101_Text_1EBF12, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route101_EventScript_1EBE85
	compare VAR_RESULT, FEMALE
	call_if_eq Route101_EventScript_1EBE89
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	release
	end

Route101_EventScript_1EBE85:: @ 81EBE85
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_1EBE89:: @ 81EBE89
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_1EBE8D: @ 81EBE8D
	walk_right
	step_end

Route101_Text_1EBE8F: @ 81EBE8F
	.string "H-help me!$"

Route101_Text_1EBE9A: @ 81EBE9A
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_1EBEDF: @ 81EBEDF
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_1EBF12: @ 81EBF12
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_1EBFDD: @ 81EBFDD
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_1EC04A: @ 81EC04A
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_1EC0C8: @ 81EC0C8
	.string "Route 601\n"
	.string "{LEFT_ARROW} Borago City$"

Route101_Text_New:
	.string "Omg lake$"

R1_rematch_may:
	.string "You are now fighting May$"

R1_rematch_brendan:
	.string "You are now fighting Brendan$"
