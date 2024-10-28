PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	goto_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_ReceivedFlashCannon
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	giveitem ITEM_TM51
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	release
	end

PacifidlogTown_House2_EventScript_ReceivedFlashCannon::
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Er-hem!\p"
	.string "I am the POKéMON FAN CLUB's most\n"
	.string "important person, the CHAIRMAN's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "POKéMON, yes, indeed.\p"
	.string "Ah!\n"
	.string "Your POKéMON…\p"
	.string "It is very flashy.\p"
	.string "A POKéMON that flashy\n"
	.string "deserves a TM like this, no?$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Flash Cannon is a STEEL type move that\n"
	.string "may lower the targets Sp. Def stat.$"

PacifidlogTown_House2_Text_Rurii:
	.string "POLIWAG: Wagg.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "It appears to be very friendly with the\n"
	.string "TRAINER.$"

PacifidlogTown_House2_Text_Rururi:
	.string "POLIWAG: Wagwag!$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "It doesn't appear to like the TRAINER\n"
	.string "very much.$"

