.set LOCALID_VENUS, 9

Route105_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
	.byte 0

Route105_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute105North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute105South
	end

Route105_CloseRegiEntrance::
	setmetatile 9, 19, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 9, 20, METATILE_General_RockWall_SandBase, TRUE
	return

Route105_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH, AbnormalWeather_StartKyogreWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH, AbnormalWeather_StartKyogreWeather
	end

Route105_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route105_EventScript_Foster::
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Luis::
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Dominik::
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Imani::
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Josue::
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Andres::
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route105_EventScript_AndresRematch
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_AndresRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end

Route105_EventScript_AndresRematch::
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_VenusTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	addobject LOCALID_VENUS
	playbgm MUS_B_ARENA, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Route105_Movement_PushPlayerDown
	applymovement LOCALID_VENUS, Route105_Movement_VenusApproachPlayer
	waitmovement 0
	msgbox Route105_Text_VenusMumble, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_VENUS, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route105_Text_VenusIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VENUS, Route105_Text_VenusDeafeat
	msgbox Route105_Text_VenusOutro, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	closemessage
	setflag FLAG_DEFEATED_VENUS
	setvar VAR_ROUTE105_STATE, 2
	removeobject LOCALID_VENUS
	fadescreen FADE_FROM_BLACK
	msgbox Route105_Text_VenusDropped, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, 10
	setvar VAR_0x8004, 10
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	giveitem ITEM_CHOICE_SCARF
	releaseall
	end

Route105_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	face_up
	unlock_facing_direction
	step_end

Route105_Movement_VenusApproachPlayer:
	delay_8
	walk_down
	step_end

Route105_Text_VenusMumble:
	.string "Running a lap! Me, Venus? No way!\n"
	.string "Let that oaf Miror B. do it!$"

Route105_Text_VenusIntro:
	.string "Aak! I recognize your face!\n"
	.string "How did you find us?! But that's not\l"
	.string "important now! I'll squash you myself!$"

Route105_Text_VenusDeafeat:
	.string "Aiyeeh! How dare you! How dare you!$"

Route105_Text_VenusOutro:
	.string "Aiyeeeeh! How dare you!\p"
	.string "How could I be defeated? Remember\n"
	.string "this! I'll get you back for this!$"

Route105_Text_VenusDropped:
	.string "Seems like they dropped something ...$"

Route104_Text_DadPokenavCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "DAD: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from DEVON's MR. STONE\n"
	.string "about your POKéNAV, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you're doing fine,\n"
	.string "so that's fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route104_Text_RegisteredDadInPokenav:
	.string "Registered DAD NORMAN\n"
	.string "in the POKéNAV.$"
