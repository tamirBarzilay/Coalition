#include "../include/Agent.h"
#include "../include/Simulation.h"
#include <vector>
#include "../include/Graph.h"
#include "../include/Party.h"
#include "../include/Coalition.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) , mCoalitionId(agentId)
{
    
}
Agent::~Agent(){//destructor
   if (mSelectionPolicy) delete mSelectionPolicy;
}
//copyConst
Agent::Agent(const Agent &agent):mAgentId (agent.mAgentId),mPartyId(agent.mPartyId),mSelectionPolicy(NULL),mCoalitionId(agent.mCoalitionId)
{
    mSelectionPolicy = agent.mSelectionPolicy->copy();
}
//move constructor
Agent::Agent( Agent &&agent):mAgentId (agent.mAgentId),mPartyId(agent.mPartyId),mSelectionPolicy(agent.mSelectionPolicy) , mCoalitionId(agent.mCoalitionId)
{
 agent.mSelectionPolicy= nullptr;
}
//copy assignment operator
Agent &Agent::operator=(const Agent& agent){
    if(this!=&agent){
            delete mSelectionPolicy;
            mSelectionPolicy=nullptr;
            mSelectionPolicy=agent.mSelectionPolicy->copy();
            mAgentId=agent.mAgentId;
            mPartyId=agent.mPartyId;
            mCoalitionId=agent.mCoalitionId;
        
        }
        return *this;
}
//move assignment operator
Agent &Agent::operator=(Agent &&agent){
    if (&agent != this){
            delete mSelectionPolicy;
            mSelectionPolicy =agent.mSelectionPolicy;
            agent.mSelectionPolicy =nullptr;
            mAgentId=agent.mAgentId;
            mPartyId=agent.mPartyId;
            mCoalitionId=agent.mCoalitionId;
        }
        return *this;
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    
    int selectedParty = mSelectionPolicy->select(sim.getGraph(),*this,mPartyId);
    if (selectedParty>-1)
    {
        sim.getPartyForActions(selectedParty).addOffer(sim,mCoalitionId);
    }
   
    
}
void Agent::setCoalitionId(int coalId){
    mCoalitionId=coalId;
}
int Agent::getCoalitionId() const
{
    return mCoalitionId;
}
SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}
 