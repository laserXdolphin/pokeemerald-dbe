static const struct TrainerMon sParty_StevenPartner[] = {
    {
        .species = SPECIES_METANG,
        .lvl = 44,
        .nature = NATURE_BRAVE,
        .heldItem = ITEM_LIGHT_CLAY,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 6, 0),
        .moves = {MOVE_LIGHT_SCREEN, MOVE_ZEN_HEADBUTT, MOVE_REFLECT, MOVE_ICE_PUNCH},
    },
    {
        .species = SPECIES_AERODACTYL,
        .lvl = 45,
        .nature = NATURE_ADAMANT,
        .heldItem = ITEM_MUSCLE_BAND,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 6, 0),
        .moves = {MOVE_ROCK_SLIDE, MOVE_AERIAL_ACE, MOVE_CRUNCH, MOVE_STEEL_WING},
    },
    {
        .species = SPECIES_AGGRON,
        .lvl = 46,
        .nature = NATURE_ADAMANT,
        .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
        .ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 0, 6),
        .moves = {MOVE_HEAD_SMASH, MOVE_PROTECT, MOVE_ROCK_SLIDE, MOVE_AQUA_TAIL},
    }
};