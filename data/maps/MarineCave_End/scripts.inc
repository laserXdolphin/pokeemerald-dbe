.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2

MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveKyogre
	end

MarineCave_End_EventScript_TryRemoveKyogre::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KYOGRE
	return

MarineCave_End_OnTransition:
	call_if_unset FLAG_DEFEATED_KYOGRE, MarineCave_End_EventScript_ShowKyogre
	end

MarineCave_End_EventScript_ShowKyogre::
	clearflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	setvar VAR_TEMP_1, 1
	return

MarineCave_End_EventScript_Kyogre::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_KYOGRE, MarineCave_End_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_KYOGRE
	setwildbattle SPECIES_KYOGRE, 70, ITEM_BLUE_ORB
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MarineCave_End_EventScript_RanFromKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MarineCave_End_EventScript_RanFromKyogre
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	releaseall
	end

MarineCave_End_EventScript_DefeatedKyogre::
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setflag FLAG_DEFEATED_KYOGRE
	goto Common_EventScript_RemoveStaticPokemon
	end

MarineCave_End_EventScript_RanFromKyogre::
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_EventScript_Archie::
	lockall
	playse SE_PIN
	applymovement LOCALID_ARCHIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MarineCave_End_Text_ArchieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE_MARINE_CAVE, MarineCave_End_Text_ArchieDefeat
	msgbox MarineCave_End_Text_ArchieWorthy, MSGBOX_DEFAULT
	giveitem ITEM_SHARPEDONITE
	buffernumberstring STR_VAR_1, 10
	setvar VAR_0x8004, 10
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	msgbox MarineCave_End_Text_ArchieOutro, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	waitmessage
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	closemessage
	playse SE_EXIT
	setflag FLAG_DEFEATED_ARCHIE_MC
	removeobject LOCALID_ARCHIE
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MarineCave_End_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

MarineCave_End_Text_ArchieIntro:
	.string "Grr, {PLAYER}. Behold.\n"
	.string "A few steps ahead you will find Kyogre.\p" 
	.string "After that incident I have to make sure\n"
	.string "that only a worthy person captures it.\p"
	.string "Fufufu, let's see how worthy you are!$" 

MarineCave_End_Text_ArchieDefeat:
	.string "I... I lost again?$" 

MarineCave_End_Text_ArchieWorthy:
	.string "{PLAYER} it seems you are indeed worthy.\n"
	.string "Please take these ...$" 

MarineCave_End_Text_ArchieOutro:
	.string "With the stone came the instruction\n"
	.string "to give the points to the person who\p"
	.string "would defeat me.\n"
	.string "Best of luck with Kyogre.$" 
