FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, FortreeCity_House2_EventScript_AlreadyMetRightTutor
	msgbox FortreeCity_House2_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto FortreeCity_House2_EventScript_ChooseRightTutorMove
	end

FortreeCity_House2_EventScript_AlreadyMetRightTutor::
	msgbox FortreeCity_House2_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto FortreeCity_House2_EventScript_ChooseRightTutorMove
	end

FortreeCity_House2_EventScript_ChooseRightTutorMove::
	message FortreeCity_House2_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_DefenseCurl
	case 1, FortreeCity_House2_EventScript_Snore
	case 2, FortreeCity_House2_EventScript_MudSlap
	case 3, FortreeCity_House2_EventScript_Swift
	case 4, FortreeCity_House2_EventScript_IcyWind
	case 5, FortreeCity_House2_EventScript_Endure
	case 6, FortreeCity_House2_EventScript_PsychUp
	case 7, FortreeCity_House2_EventScript_IcePunch
	case 8, FortreeCity_House2_EventScript_ThunderPunch
	case 9, FortreeCity_House2_EventScript_FirePunch
	case 10, FortreeCity_House2_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, FortreeCity_House2_EventScript_ExitTutorMoveSelect
	end

FortreeCity_House2_EventScript_ChooseNewRightTutorMove::
	message FortreeCity_House2_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_DefenseCurl
	case 1, FortreeCity_House2_EventScript_Snore
	case 2, FortreeCity_House2_EventScript_MudSlap
	case 3, FortreeCity_House2_EventScript_Swift
	case 4, FortreeCity_House2_EventScript_IcyWind
	case 5, FortreeCity_House2_EventScript_Endure
	case 6, FortreeCity_House2_EventScript_PsychUp
	case 7, FortreeCity_House2_EventScript_IcePunch
	case 8, FortreeCity_House2_EventScript_ThunderPunch
	case 9, FortreeCity_House2_EventScript_FirePunch
	case 10, FortreeCity_House2_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, FortreeCity_House2_EventScript_ExitTutorMoveSelect
	end

FortreeCity_House2_EventScript_DefenseCurl::
	setvar VAR_0x8008, 0
	setvar VAR_0x8005, MOVE_ICE_FANG
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_THUNDER_FANG
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_FIRE_FANG
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_PSYCHIC_FANGS
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_IRON_HEAD
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_POISON_JAB
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto FortreeCity_House2_EventScript_ConfirmMoveSelection
	end

FortreeCity_House2_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox FortreeCity_House2_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_CancelChooseMon::
	msgbox FortreeCity_House2_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
FortreeCity_House2_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox FortreeCity_House2_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House2_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, FortreeCity_House2_EventScript_TeachTutorMove
	msgbox FortreeCity_House2_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto FortreeCity_House2_EventScript_ChooseNewMove
	end

FortreeCity_House2_EventScript_TeachTutorMove::
	msgbox FortreeCity_House2_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, FortreeCity_House2_EventScript_CancelChooseMon
	msgbox FortreeCity_House2_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

FortreeCity_House2_EventScript_ChooseNewMove::
	goto FortreeCity_House2_EventScript_ChooseNewRightTutorMove
	end

FortreeCity_House2_Text_TeachWhichMove:
	.string "Fine, fine, look here!\n"
	.string "Which move should I teach?$"

FortreeCity_House2_Text_MoveWillBeXBattlePoints:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

FortreeCity_House2_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

FortreeCity_House2_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

FortreeCity_House2_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

FortreeCity_House2_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

FortreeCity_House2_Text_RightTutorIntro:
	.string "People… POKéMON…\p"
	.string "Their hidden powers are aroused by\n"
	.string "living in natural environments…\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I can prove it to you.\n"
	.string "I can unlock the power within your\l"
	.string "POKéMON by teaching them moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

FortreeCity_House2_Text_RightTutorWelcomeBack:
	.string "Have you come to awaken the hidden\n"
	.string "power of your POKéMON.$"

