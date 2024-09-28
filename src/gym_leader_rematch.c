#include "global.h"
#include "random.h"
#include "event_data.h"
#include "battle_setup.h"
#include "gym_leader_rematch.h"

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch);
#if FREE_MATCH_CALL == FALSE
static s32 GetRematchIndex(u32 trainerIdx);
#endif //FREE_MATCH_CALL

static const u16 GymLeaderRematches_AfterNewMauville[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_WATTSON,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN
};

static const u16 GymLeaderRematches_BeforeNewMauville[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    // Wattson isn't available at this time
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN
};

static const u16 GymLeaderRematches_Before6Gym[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY
};

static const u16 GymLeaderRematches_Before8Gym[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_WATTSON,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
}; 
static const u16 GymLeaderRematches_Before8Gym_BNM[] = {
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
};
void UpdateGymLeaderRematch(void)
{
    if (FlagGet(FLAG_BADGE05_GET)) // enable after 5. Badge
    {
        // before 6. Gym Roxanne and Brawly
        if (!FlagGet(FLAG_BADGE06_GET)) 
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before6Gym, ARRAY_COUNT(GymLeaderRematches_Before6Gym), 1);
        // before finishing of Aqua Hideout: 1. rounds up to Norman
        else if (!FlagGet(FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE) && FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym, ARRAY_COUNT(GymLeaderRematches_Before8Gym), 1);
        else if (!FlagGet(FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym_BNM, ARRAY_COUNT(GymLeaderRematches_Before8Gym_BNM), 1);
        // before defeating Juan: 2. rounds up to Norman
        else if (!FlagGet(FLAG_BADGE08_GET) && FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym, ARRAY_COUNT(GymLeaderRematches_Before8Gym), 2);
        else if (!FlagGet(FLAG_BADGE08_GET))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym_BNM, ARRAY_COUNT(GymLeaderRematches_Before8Gym_BNM), 2);
        // before defeating Wally in Victory Road: 2. rounds
        else if (!FlagGet(FLAG_DEFEATED_WALLY_VICTORY_ROAD) && FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym, ARRAY_COUNT(GymLeaderRematches_AfterNewMauville), 2);
        else if (!FlagGet(FLAG_DEFEATED_WALLY_VICTORY_ROAD))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_Before8Gym_BNM, ARRAY_COUNT(GymLeaderRematches_BeforeNewMauville), 2);
        // before clearing the game: 3. rounds 
        else if (!FlagGet(FLAG_SYS_GAME_CLEAR) && FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_AfterNewMauville, ARRAY_COUNT(GymLeaderRematches_AfterNewMauville), 3);
        else if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_BeforeNewMauville, ARRAY_COUNT(GymLeaderRematches_BeforeNewMauville), 3);
        // after clearing the game: 4. rounds
        else if (FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_AfterNewMauville, ARRAY_COUNT(GymLeaderRematches_AfterNewMauville), 5);
        else
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_BeforeNewMauville, ARRAY_COUNT(GymLeaderRematches_BeforeNewMauville), 5);
    }
}

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch)
{
#if FREE_MATCH_CALL == FALSE
    s32 whichLeader = 0;
    s32 lowestRematchIndex = 5;
    u32 i;
    s32 rematchIndex;

    for (i = 0; i < size; i++)
    {
        if (!gSaveBlock1Ptr->trainerRematches[data[i]])
        {
            rematchIndex = GetRematchIndex(data[i]);
            if (lowestRematchIndex > rematchIndex)
                lowestRematchIndex = rematchIndex;
            whichLeader++;
        }
    }
    if (whichLeader != 0 && lowestRematchIndex <= maxRematch)
    {
        whichLeader = 0;
        for (i = 0; i < size; i++)
        {
            if (!gSaveBlock1Ptr->trainerRematches[data[i]])
            {
                rematchIndex = GetRematchIndex(data[i]);
                if (rematchIndex == lowestRematchIndex)
                    whichLeader++;
            }
        }
        if (whichLeader != 0)
        {
            whichLeader = Random() % whichLeader;
            for (i = 0; i < size; i++)
            {
                if (!gSaveBlock1Ptr->trainerRematches[data[i]])
                {
                    rematchIndex = GetRematchIndex(data[i]);
                    if (rematchIndex == lowestRematchIndex)
                    {
                        if (whichLeader == 0)
                        {
                            gSaveBlock1Ptr->trainerRematches[data[i]] = lowestRematchIndex;
                            break;
                        }
                        whichLeader--;
                    }
                }
            }
        }
    }
#endif //FREE_MATCH_CALL
}

#if FREE_MATCH_CALL == FALSE
static s32 GetRematchIndex(u32 trainerIdx)
{
    s32 i;
    for (i = 0; i < 5; i++)
    {
        if (!HasTrainerBeenFought(gRematchTable[trainerIdx].trainerIds[i]))
        {
            return i;
        }
    }
    return 5;
}
#endif //FREE_MATCH_CALL
