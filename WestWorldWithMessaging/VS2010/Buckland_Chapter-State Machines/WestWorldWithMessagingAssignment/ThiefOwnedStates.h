#ifndef ThIEF_OWNED_STATES_H
#define ThIEF_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   ThiefOwnedStates.h
//
//  Desc:   All the states that can be assigned to the Thief class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class Thief;



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class ThiefsGlobalState : public State<Thief>
{
private:

    ThiefsGlobalState() {}

    //copy ctor and assignment should be private
    ThiefsGlobalState(const ThiefsGlobalState&);
    ThiefsGlobalState& operator=(const ThiefsGlobalState&);

public:

    //this is a singleton
    static ThiefsGlobalState* Instance();

    virtual void Enter(Thief* thief) {}

    virtual void Execute(Thief* thief);

    virtual void Exit(Thief* thief) {}

    virtual bool OnMessage(Thief* thief, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class StayHome : public State<Thief>
{
private:

    StayHome() {}

    //copy ctor and assignment should be private
    StayHome(const StayHome&);
    StayHome& operator=(const StayHome&);

public:

    //this is a singleton
    static StayHome* Instance();

    virtual void Enter(Thief* thief);

    virtual void Execute(Thief* thief);

    virtual void Exit(Thief* thief);

    virtual bool OnMessage(Thief* thief, const Telegram& msg);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class VisitMine : public State<Thief>
{
private:

    VisitMine() {}

    //copy ctor and assignment should be private
    VisitMine(const VisitMine&);
    VisitMine& operator=(const VisitMine&);

public:

    //this is a singleton
    static VisitMine* Instance();

    virtual void Enter(Thief* thief);

    virtual void Execute(Thief* thief);

    virtual void Exit(Thief* thief);

    virtual bool OnMessage(Thief* thief, const Telegram& msg);

};


class StealNuggets : public State<Thief>
{
private:

    StealNuggets() {}

    //copy ctor and assignment should be private
    StealNuggets(const StealNuggets&);
    StealNuggets& operator=(const StealNuggets&);

public:

    //this is a singleton
    static StealNuggets* Instance();

    virtual void Enter(Thief* thief);

    virtual void Execute(Thief* thief);

    virtual void Exit(Thief* thief);

    virtual bool OnMessage(Thief* thief, const Telegram& msg);
};


#endif