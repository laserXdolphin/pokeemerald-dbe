ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
	.byte 0

ArtisanCave_B1F_OnTransition:
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end


ArtisanCave_B1F_EventScript_Noland::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_NolandIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_NolandOutro
	trainerbattle_no_intro TRAINER_NOLAND, ArtisanCave_B1F_Text_NolandDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_NolandOutro
	release
	end

ArtisanCave_B1F_EventScript_NolandOutro::
	msgbox ArtisanCave_B1F_Text_NolandOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_EventScript_Greta::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_GretaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_GretaOutro
	trainerbattle_no_intro TRAINER_GRETA, ArtisanCave_B1F_Text_GretaDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_GretaOutro
	release
	end

ArtisanCave_B1F_EventScript_GretaOutro::
	msgbox ArtisanCave_B1F_Text_GretaOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_EventScript_Tucker::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_TuckerIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_TuckerOutro
	trainerbattle_no_intro TRAINER_TUCKER, ArtisanCave_B1F_Text_TuckerDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_TuckerOutro
	release
	end

ArtisanCave_B1F_EventScript_TuckerOutro::
	msgbox ArtisanCave_B1F_Text_TuckerOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_EventScript_Lucy::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_LucyIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_LucyOutro
	trainerbattle_no_intro TRAINER_LUCY, ArtisanCave_B1F_Text_LucyDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_LucyOutro
	release
	end

ArtisanCave_B1F_EventScript_LucyOutro::
	msgbox ArtisanCave_B1F_Text_LucyOutro, MSGBOX_DEFAULT
	release
	end

ArtisanCave_B1F_EventScript_Spenser::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_SpenserIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_SpenserOutro
	trainerbattle_no_intro TRAINER_SPENSER, ArtisanCave_B1F_Text_SpenserDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_SpenserOutro
	release
	end

ArtisanCave_B1F_EventScript_SpenserOutro::
	msgbox ArtisanCave_B1F_Text_SpenserOutro, MSGBOX_DEFAULT
	release
	end
	
ArtisanCave_B1F_EventScript_Brandon::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_BrandonIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_BrandonOutro
	trainerbattle_no_intro TRAINER_BRANDON, ArtisanCave_B1F_Text_BrandonDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_BrandonOutro
	release
	end

ArtisanCave_B1F_EventScript_BrandonOutro::
	msgbox ArtisanCave_B1F_Text_BrandonOutro, MSGBOX_DEFAULT
	release
	end
	
ArtisanCave_B1F_EventScript_Anabel::
	lock
	faceplayer
	msgbox ArtisanCave_B1F_Text_AnabelIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArtisanCave_B1F_EventScript_AnabelOutro
	trainerbattle_no_intro TRAINER_ANABEL, ArtisanCave_B1F_Text_AnabelDefeat
	call Common_EventScript_OutOfCenterPartyHeal
	goto ArtisanCave_B1F_EventScript_AnabelOutro
	release
	end

ArtisanCave_B1F_EventScript_AnabelOutro::
	msgbox ArtisanCave_B1F_Text_AnabelOutro, MSGBOX_DEFAULT
	release
	end
	
ArtisanCave_B1F_Text_NolandIntro:
	.string "NOLAND: Hey, hey! Get a move on!\n"
	.string "I'm on break but wanna battle?$"

ArtisanCave_B1F_Text_NolandDefeat:
	.string "What happened here?$"

ArtisanCave_B1F_Text_NolandOutro:
	.string "Pfft, man!\n"
	.string "Come back when you are ready\l"
	.string "for the next round, hey!$"
	
ArtisanCave_B1F_Text_GretaIntro:
	.string "GRETA: Are you sure you're up for me?$"

ArtisanCave_B1F_Text_GretaDefeat:
	.string "No way! Good job!$"

ArtisanCave_B1F_Text_GretaOutro:
	.string "It's going to be fun the next time!\n"
	.string "I'm looking forward to it!$"
	
ArtisanCave_B1F_Text_TuckerIntro:
	.string "TUCKER: I bet you're twitching all over\n"
	.string "from the tension of getting to battle me!$"

ArtisanCave_B1F_Text_TuckerDefeat:
	.string "Ahahaha! You're inspiring!$"

ArtisanCave_B1F_Text_TuckerOutro:
	.string "You have a unique charm!\n"
	.string "I will very much look forward\l"
	.string "to our next encounter!$"
	
ArtisanCave_B1F_Text_LucyIntro:
	.string "LUCY: I'm not one for idle chatter.\n"
	.string "Hurry. Come on... $"

ArtisanCave_B1F_Text_LucyDefeat:
	.string "Urk...$"

ArtisanCave_B1F_Text_LucyOutro:
	.string "...That's all there is...\n"
	.string "Disappear already...$"
	
ArtisanCave_B1F_Text_SpenserIntro:
	.string "SPENSER: Young one of a Trainer!\n"
	.string "Do you believe in your Pokémon?$"

ArtisanCave_B1F_Text_SpenserDefeat:
	.string "Ah... Now this is something else...$"

ArtisanCave_B1F_Text_SpenserOutro:
	.string "I will eagerly await the next\n"
	.string "opportunity to see you.$"
	
ArtisanCave_B1F_Text_BrandonIntro:
	.string "BRANDON: You coming here means you have\n"
	.string "that much confidence in yourself, right?$"

ArtisanCave_B1F_Text_BrandonDefeat:
	.string "That's it! You've done great!\n"
	.string "You've worked hard for this!$"

ArtisanCave_B1F_Text_BrandonOutro:
	.string "May our paths cross again!\n"
	.string "Farewell for now, young explorer!$"
	
ArtisanCave_B1F_Text_AnabelIntro:
	.string "ANABEL: Let me see your talent in its\n"
	.string "entirety... Let's begin, shall we?$"

ArtisanCave_B1F_Text_AnabelDefeat:
	.string "Okay, I understand...$"

ArtisanCave_B1F_Text_AnabelOutro:
	.string "I will be waiting for you. \n"
	.string "Until the next time we meet...$"
