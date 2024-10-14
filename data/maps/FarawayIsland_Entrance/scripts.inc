.set LOCALID_SAILOR, 1
.set LOCALID_SS_TIDAL, 2
.set LOCALID_GREEN, 3

FarawayIsland_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Entrance_OnTransition
	.byte 0

FarawayIsland_Entrance_OnTransition:
	setflag FLAG_ARRIVED_ON_FARAWAY_ISLAND
	end

FarawayIsland_Entrance_EventScript_SetCloudsWeather::
	setweather WEATHER_SUNNY_CLOUDS
	doweather
	end

FarawayIsland_Entrance_EventScript_ClearWeather::
	setweather WEATHER_NONE
	doweather
	end

FarawayIsland_Entrance_EventScript_Sailor::
	lock
	faceplayer
	msgbox FarawayIsland_Entrance_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FarawayIsland_Entrance_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_SAILOR, MAP_FARAWAY_ISLAND_ENTRANCE
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

FarawayIsland_Entrance_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

FarawayIsland_Entrance_EventScript_Sign::
	msgbox FarawayIsland_Entrance_Text_Sign, MSGBOX_SIGN
	end

FarawayIsland_Entrance_EventScript_Leaf::
	lockall
	playse SE_PIN
	applymovement LOCALID_GREEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREEN, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox FarawayIsland_Entrance_Text_GreenIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GREEN_1, FarawayIsland_Entrance_Text_GreenDefeat
	msgbox FarawayIsland_Entrance_Text_GreenItem, MSGBOX_DEFAULT
	giveitem ITEM_BLASTOISINITE
	msgbox FarawayIsland_Entrance_Text_GreenOutro, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	closemessage
	playse SE_EXIT
	setflag FLAG_DEFEATED_GREEN
	clearflag FLAG_HIDE_KANTO_PPL
	removeobject LOCALID_GREEN
	fadescreen FADE_FROM_BLACK
	releaseall
	end

FarawayIsland_Entrance_Text_GreenIntro:
	.string "GREEN: Who are you?\p"
	.string "Nice to meet you. I'm Green!\n" 
	.string "So, hey, I'm just curious…\p"
	.string "Are you here because you're also\n"
	.string "looking for… y'know, something special?\l" 
	.string "Yes? Than let's see who deserves it!$"

FarawayIsland_Entrance_Text_GreenDefeat:
	.string "Come on! What's with that…?$" 

FarawayIsland_Entrance_Text_GreenItem:
	.string "Wow, you're strong!\n"
	.string "Well, I guess that's that.\p" 
	.string "Hee hee hee…\n"
	.string "Here, you can have this.$"
	
FarawayIsland_Entrance_Text_GreenOutro:
	.string "I wonder where the other two are ...$" 
