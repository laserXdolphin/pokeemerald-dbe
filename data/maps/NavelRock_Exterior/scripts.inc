.set LOCALID_MIROR_B, 1

NavelRock_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Exterior_OnTransition
	.byte 0

NavelRock_Exterior_OnTransition:
	setflag FLAG_ARRIVED_AT_NAVEL_ROCK
	end

NavelRock_Exterior_EventScript_MirorB::
	lockall
	playbgm MUS_B_PIKE, TRUE
	playse SE_PIN
	applymovement LOCALID_MIROR_B, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	msgbox NavelRock_Exterior_Text_MirorBIntro, MSGBOX_DEFAULT
	applymovement LOCALID_MIROR_B, NavelRock_Exterior_Movement_MirorB
	setweather WEATHER_DOWNPOUR
	doweather
	waitmovement 0
	trainerbattle_no_intro TRAINER_MIROR_B_2, NavelRock_Exterior_Text_MirorBDefeat
	msgbox NavelRock_Exterior_Text_MirorBOutro, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	closemessage
	fadedefaultbgm
	setflag FLAG_DEFEATED_MIROR_B_2
	removeobject LOCALID_MIROR_B
	fadescreen FADE_FROM_BLACK
	releaseall
	end

NavelRock_Exterior_Text_MirorBIntro:
	.string "Fuhohohoh. You've kept me hanging\n"
	.string "around, {PLAYER}. You ruined things\l"
	.string "with the giants for us.\p"
	.string "But, you know, we're not about to lose\n"
	.string "over and over to you. Using my Rain\p"
	.string "Dance. This time, I'll win.$"

NavelRock_Exterior_Text_MirorBDefeat:
	.string "I'm an awesome dancer…\n"
	.string "But I can't win in battles!$"

NavelRock_Exterior_Text_MirorBOutro:
	.string "This just won't do! But I'll admit you've\n"
	.string "beaten me thoroughly. Okay, since I'm\p"
	.string "done, there's only one thing to do now.\n"
	.string "Let's go! Escape!$"

NavelRock_Exterior_Movement_MirorB:
	face_left
	delay_8
	delay_4
	face_up
	delay_8
	delay_4
	face_right
	delay_8
	delay_4
	face_down
	delay_8
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_left
	delay_2
	face_up
	delay_2
	face_right
	delay_2
	face_down
	step_end
