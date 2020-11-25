#ifndef Thief_H
#define Thief_H
//------------------------------------------------------------------------
//
//  Name: Thief.h
//
//  Desc: class to implement Miner Bob's wife.
//
//  Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

#include <string>

#include "fsm/State.h"
#include "BaseGameEntity.h"
#include "Locations.h"
#include "ThiefOwnedStates.h"
#include "misc/ConsoleUtils.h"
#include "Miner.h"
#include "fsm/StateMachine.h"
#include "misc/Utils.h"



class Thief : public BaseGameEntity
{
private:

    //an instance of the state machine class
    StateMachine<Thief>* m_pStateMachine;

    location_type   m_Location;

    bool            m_btheft;


public:

    Thief(int id) :m_Location(shack),
        m_btheft(false),
        BaseGameEntity(id)

    {
        //set up the state machine
        m_pStateMachine = new StateMachine<Thief>(this);

        m_pStateMachine->SetCurrentState(StayHome::Instance());

        m_pStateMachine->SetGlobalState(ThiefsGlobalState::Instance());
    }

    ~Thief() { delete m_pStateMachine; }


    //this must be implemented
    void          Update();

    //so must this
    virtual bool  HandleMessage(const Telegram& msg);

    StateMachine<Thief>* GetFSM()const { return m_pStateMachine; }

    //----------------------------------------------------accessors
    location_type Location()const { return m_Location; }
    void          ChangeLocation(location_type loc) { m_Location = loc; }

    bool          Steal()const { return m_btheft; }
    void          StealNuggets(bool val) { m_btheft = val; }

};

#endif
#pragma once
