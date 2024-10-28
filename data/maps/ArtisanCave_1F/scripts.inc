ArtisanCave_1F_MapScripts::
	.byte 0

ArtisanCave_1F_EventScript_Hunter::
	lock
	faceplayer
	call_if_unset FLAG_DEFEATED_DAKIM ArtisanCave_1F_EventScript_HunterOutro
	call_if_unset FLAG_DEFEATED_EIN ArtisanCave_1F_EventScript_HunterOutro
	msgbox ArtisanCave_1F_Text_HunterIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_1F_EventScript_HunterOutro
	trainerbattle_no_intro TRAINER_HUNTER, ArtisanCave_1F_Text_HunterDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	buffernumberstring STR_VAR_1, 25
	setvar VAR_0x8004, 25
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	goto ArtisanCave_1F_EventScript_HunterOutro
	release
	end

ArtisanCave_1F_EventScript_HunterOutro::
	msgbox ArtisanCave_1F_Text_HunterOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_1F_EventScript_Xander::
	lock
	faceplayer
	msgbox ArtisanCave_1F_Text_MoxanIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_1F_EventScript_XanderOutro
	trainerbattle_no_intro TRAINER_XANDER, ArtisanCave_1F_Text_MoxanDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	buffernumberstring STR_VAR_1, 20
	setvar VAR_0x8004, 20
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_ScottsHouse_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	goto ArtisanCave_1F_EventScript_XanderOutro
	release
	end

ArtisanCave_1F_EventScript_XanderOutro::
	msgbox ArtisanCave_1F_Text_MoxanOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_1F_Text_HunterIntro:
	.string "HUNTER: You are finally here!\n"
	.string "I hope you enjoyed the game.\l"
	.string "Wanna battle?$"

ArtisanCave_1F_Text_HunterDefeat:
	.string "Not bad at all ...$"

ArtisanCave_1F_Text_HunterOutro:
	.string "See you later.$"
	
ArtisanCave_1F_Text_MoxanIntro:
	.string "XANDER: Bet you can't beat me!$"

ArtisanCave_1F_Text_MoxanDefeat:
	.string "Doofolistic!$"

ArtisanCave_1F_Text_MoxanOutro:
	.string "Hmph! Until next time.$"
	