.set LOCALID_LUGIA, 1
.set LOCALID_EIN, 2

NavelRock_Bottom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Bottom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Bottom_OnResume
	.byte 0

NavelRock_Bottom_OnTransition:
	call_if_set FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_HideLugia
	call_if_unset FLAG_CAUGHT_LUGIA, NavelRock_Bottom_EventScript_TryShowLugia
	end

NavelRock_Bottom_EventScript_HideLugia::
	setflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_EventScript_TryShowLugia::
	goto_if_set FLAG_DEFEATED_LUGIA, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_LUGIA
	return

NavelRock_Bottom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Bottom_EventScript_TryRemoveLugia
	end

NavelRock_Bottom_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LUGIA
	return

NavelRock_Bottom_EventScript_Lugia::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Bottom_EventScript_DefeatedLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Bottom_EventScript_RanFromLugia
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Bottom_EventScript_RanFromLugia
	setflag FLAG_CAUGHT_LUGIA
	release
	end

NavelRock_Bottom_EventScript_DefeatedLugia::
	setflag FLAG_DEFEATED_LUGIA
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Bottom_EventScript_Ein::
	lockall
	playbgm MUS_B_FACTORY, TRUE
	applymovement LOCALID_EIN, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	msgbox NavelRock_Bottom_Text_EinIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_EIN_2, NavelRock_Bottom_Text_EinDeafeat
	msgbox NavelRock_Bottom_Text_EinOutro, MSGBOX_DEFAULT
	giveitem ITEM_MANECTITE
	waitmessage
	fadescreen FADE_TO_BLACK
	closemessage
	fadedefaultbgm
	setflag FLAG_DEFEATED_EIN
	removeobject LOCALID_EIN
	fadescreen FADE_FROM_BLACK
	releaseall
	end

NavelRock_Bottom_Text_EinIntro:
	.string "Well, well. So, you have come.\n"
	.string "I am working on a modification that\p"
	.string "makes Pokémon more vicious. Once we\n"
	.string "get Lugia no one will be able to stop us.\l"
	.string "The boss will be most pleased.\p"
	.string "Let me acquaint you with the power of\n"
	.string "my Paradox Pokémon!$"

NavelRock_Bottom_Text_EinDeafeat:
	.string "Gwaah! You have improved\n"
	.string "since our last meeting?!$"

NavelRock_Bottom_Text_EinOutro:
	.string "Grr… It is a shame that you oppose us,\n"
	.string "{PLAYER}. Here, use this.\p"
	.string "Our test here was a success, time to\n"
	.string "to phase Orre ...$"
