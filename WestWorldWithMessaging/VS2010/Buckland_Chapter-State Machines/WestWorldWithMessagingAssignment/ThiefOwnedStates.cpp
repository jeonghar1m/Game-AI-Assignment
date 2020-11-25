#include "ThiefOwnedStates.h"
#include "MinerOwnedStates.h"
#include "Thief.h"
#include "Locations.h"
#include "Time/CrudeTimer.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;

#ifdef TEXTOUTPUT
#include <fstream>
extern std::ofstream os;
#define cout os
#endif

//-----------------------------------------------------------------------Global state

ThiefsGlobalState* ThiefsGlobalState::Instance()
{
    static ThiefsGlobalState instance;

    return &instance;
}


void ThiefsGlobalState::Execute(Thief* thief)
{
    //1 in 10 chance of needing the bathroom (provided she is not already
    //in the bathroom)
    if ((RandFloat() < 0.1) &&
        !thief->GetFSM()->isInState(*StealNuggets::Instance()))
    {
        thief->GetFSM()->ChangeState(StealNuggets::Instance());
    }
}

bool ThiefsGlobalState::OnMessage(Thief* thief, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case Msg_HiHoneyImHome:
    {
        cout << "\nMessage handled by " << GetNameOfEntity(thief->ID()) << " at time: "
            << Clock->GetCurrentTime();

        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        cout << "\n" << GetNameOfEntity(thief->ID()) <<
            ": I will take your Nuggets! lol";

        thief->GetFSM()->ChangeState(StealNuggets::Instance());
    }

    return true;

    }//end switch

    return false;
}

//-------------------------------------------------------------------------DoHouseWork

StayHome* StayHome::Instance()
{
    static StayHome instance;

    return &instance;
}


void StayHome::Enter(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": My sweet home!";
}


void StayHome::Execute(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Rest";
}

void StayHome::Exit(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Let's take Miner's Nuggets!";
}

bool StayHome::OnMessage(Thief* thief, const Telegram& msg)
{
    return false;
}

//------------------------------------------------------------------------VisitMine

VisitMine* VisitMine::Instance()
{
    static VisitMine instance;

    return &instance;
}


void VisitMine::Enter(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Visit the Mine";
}


void VisitMine::Execute(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Where is the Miner?";

    thief->GetFSM()->RevertToPreviousState();
}

void VisitMine::Exit(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Let's go back my sweet home!";
}


bool VisitMine::OnMessage(Thief* thief, const Telegram& msg)
{
    return false;
}


//------------------------------------------------------------------------CookStew

StealNuggets* StealNuggets::Instance()
{
    static StealNuggets instance;

    return &instance;
}


void StealNuggets::Enter(Thief* thief)
{
    //if not already steal Bob's Nuggets
    if (!thief->Steal())
    {
        cout << "\n" << GetNameOfEntity(thief->ID()) << ": Steal Bob's Nuggets";

        //send a delayed message myself so that I know when to take the stew
        //out of the oven
        Dispatch->DispatchMessage(1.5,                  //time delay
            thief->ID(),           //sender ID
            thief->ID(),           //receiver ID
            Msg_StewReady,        //msg
            NO_ADDITIONAL_INFO);

        thief->StealNuggets(true);
    }
}


void StealNuggets::Execute(Thief* thief)
{
    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Try steal the Nuggets";
}

void StealNuggets::Exit(Thief* thief)
{
    SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    cout << "\n" << GetNameOfEntity(thief->ID()) << ": Run away!";
}


bool StealNuggets::OnMessage(Thief* thief, const Telegram& msg)
{
    SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    switch (msg.Msg)
    {
    case Msg_StealNuggets:
    {
        cout << "\nMessage received by " << GetNameOfEntity(thief->ID()) <<
            " at time: " << Clock->GetCurrentTime();

        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n" << GetNameOfEntity(thief->ID()) << ": I will take yout Nuggets dude!";

        //let hubby know the stew is ready
        Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
            thief->ID(),
            ent_Miner_Bob,
            Msg_StealNuggets,
            NO_ADDITIONAL_INFO);

        thief->StealNuggets(false);

        thief->GetFSM()->ChangeState(StayHome::Instance());
    }

    return true;

    }//end switch

    return false;
}