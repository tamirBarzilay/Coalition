#pragma once

#include "SelectionPolicy.h"

class SelectionPolicy;
class Simulation;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();                            //destructor
    Agent(const Agent & agent);       // copy constructor
    Agent(Agent&& agent);             // move constructor    
    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim); 
    void setCoalitionId(int coalId);
    int getCoalitionId() const; 
    SelectionPolicy *getSelectionPolicy() const;
    Agent &operator=(const Agent& agent);  // copy assingment operator
    Agent& operator=(Agent&& agent);  // move assignment operator
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;

};
