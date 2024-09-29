.set LOCALID_MIROR_B, 1

SealedChamber_InnerRoom_MapScripts::
	.byte 0

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	setvar VAR_ROUTE105_STATE, 1
	setvar VAR_ROUTE111_STATE, 1
	setvar VAR_ROUTE120_STATE, 1
	releaseall
	end

SealedChamber_InnerRoom_EventScript_MirorBTrigger::
	lockall
	playbgm MUS_B_PIKE, FALSE
	msgbox SealedChamber_InnerRoom_Text_MirorBMumble, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MIROR_B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MIROR_B, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SealedChamber_InnerRoom_Text_MirorBIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MIROR_B, SealedChamber_InnerRoom_Text_MirorBDefeat
	msgbox SealedChamber_InnerRoom_Text_MirorBOutro, MSGBOX_DEFAULT
	waitmessage
	fadescreen FADE_TO_BLACK
	closemessage
	waitse
	playmoncry SPECIES_POLITOED, CRY_MODE_NORMAL
	waitmoncry
	setflag FLAG_DEFEATED_MIROR_B
	setvar VAR_SEALED_CHAMBER_STATE, 1
	removeobject LOCALID_MIROR_B
	fadescreen FADE_FROM_BLACK
	msgbox SealedChamber_InnerRoom_Text_MirorBDropped, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, 10
	setvar VAR_0x8004, 10
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	giveitem ITEM_LEFTOVERS
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect::
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	releaseall
	end

SealedChamber_InnerRoom_Text_MirorBMumble:
	.string "Oh, no, no, what a no-no!\n"
	.string "He will have my head for this!\p"
	.string "Digging was easy but ... Hm?$"

SealedChamber_InnerRoom_Text_MirorBIntro:
	.string "Fuhohoho! Darling who are you?\p"
	.string "Some naughty kiddo trying to\n" 
	.string "mess with our plans?\p"
	.string "We can't have that ...\n"
	.string "Let the music play!$" 

SealedChamber_InnerRoom_Text_MirorBDefeat:
	.string "You messed up my rhythm!\n"
	.string "I just can't, no, I just can't do it!$"

SealedChamber_InnerRoom_Text_MirorBOutro:
	.string "How, how, how dare you!\p"
	.string "Don't you dare think you'll get away\n"
	.string "with your latest outrage! One of these\p"
	.string "days, I will take great pleasure in\n"
	.string "kicking you about with my elegant\p"
	.string "dance steps!\p"
	.string "Let's go! Escape!$"

SealedChamber_InnerRoom_Text_MirorBDropped:
	.string "Seems like they dropped something$"
