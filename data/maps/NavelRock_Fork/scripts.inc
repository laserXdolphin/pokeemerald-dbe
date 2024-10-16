.set LOCALID_VENUS, 1

NavelRock_Fork_MapScripts::
	.byte 0

NavelRock_Fork_EventScript_Venus::
	lockall
	playbgm MUS_B_ARENA, TRUE
	msgbox NavelRock_Fork_Text_VenusIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_VENUS_2, NavelRock_Fork_Text_VenusDeafeat
	msgbox NavelRock_Fork_Text_VenusOutro, MSGBOX_DEFAULT
	giveitem ITEM_BANETTITE
	waitmessage
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	closemessage
	setflag FLAG_DEFEATED_VENUS
	removeobject LOCALID_VENUS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

NavelRock_Fork_Text_VenusIntro:
	.string "Oh, well if it isn't that darling child.\n"
	.string "What kept you so long? I'm rather tired\p"
	.string "of waiting. Now, say your good-byes.\n"
	.string "This time, I really am going to be as\l"
	.string "serious as serious can be!$"

NavelRock_Fork_Text_VenusDeafeat:
	.string "Waaaaah!\n"
	.string "I don't want to do this anymore!$"

NavelRock_Fork_Text_VenusOutro:
	.string "Me, lose again? My pride will not stand\n"
	.string "for it! Here, take this thing away!\p"
	.string "For that, I want your silence that this\n"
	.string "battle never happened!$"
