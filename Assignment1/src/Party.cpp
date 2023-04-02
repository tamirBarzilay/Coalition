#include "../include/Party.h"
#include <algorithm>
#include "../include/Coalition.h"
#include "../include/Simulation.h"
#include "../include/Agent.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mPartyIteration(-100), mOffers() 
{     
}
Party::~Party(){
    if (mJoinPolicy) delete mJoinPolicy;
}       
//copy const                                                                                            
Party::Party(const Party& party): mId(party.mId), mName(party.mName), mMandates(party.mMandates),mJoinPolicy(NULL),mState(party.mState),  mPartyIteration(party.mPartyIteration), mOffers(party.mOffers)
{
        mJoinPolicy = party.mJoinPolicy->copy() ;

}
//move const
Party::Party(Party&& party): mId(party.mId), mName(party.mName), mMandates(party.mMandates),mJoinPolicy(NULL), mState(party.mState), mPartyIteration(party.mPartyIteration), mOffers(party.mOffers)
{
    mJoinPolicy = party.mJoinPolicy ;
    party.mJoinPolicy = nullptr;
}
//copy assignment operator
Party &Party::operator=(const Party& party){
    if(this!=&party){
            if (mJoinPolicy)
                delete mJoinPolicy;
            mJoinPolicy=nullptr; 
            mJoinPolicy = party.mJoinPolicy->copy();
            mId=party.mId;
            mName=party.mName;
            mMandates=party.mMandates;
            mState=party.mState;
            mPartyIteration=party.mPartyIteration;
            mOffers =party.mOffers;
        }
        return *this;
}
//move assignment operator
Party &Party::operator=(Party &&party){
    if(this!=&party){
            mJoinPolicy = party.mJoinPolicy;
            if(party.mJoinPolicy)
                party.mJoinPolicy=nullptr;
            mId=party.mId;
            mName=party.mName;
            mMandates=party.mMandates;
            mState=party.mState;
            mPartyIteration=party.mPartyIteration;
            mOffers =party.mOffers;
        }
        return *this;
}
State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(mPartyIteration + 3 == s.getIterationNum()){
        int coalitionNum = mJoinPolicy->join(s,mOffers);
        Coalition *chosenCoalition = &s.getCoalition(coalitionNum);
        //clone agent
        int agentId = s.getAgents().back().getId() + 1; //getting the next index for the agents list
        SelectionPolicy *sel = chosenCoalition->getSelectionPolicy()->copy();//copying selection policy field
        Agent newAgent(agentId,mId,sel);
        newAgent.setCoalitionId(coalitionNum);
        s.addAgent(newAgent);
        //change party state to joined and empty mOffers
        setState(Joined);
        mOffers = {};
        //add party to coalition
        chosenCoalition->addParty(this);
        
    }
}

bool Party::offerFromSameCoalition(Party &currParty, const Agent agent) const{
    int coalitionNum= agent.getCoalitionId();
    for (auto &&i : mOffers)
    {
        if(i==coalitionNum) return  true;
    }
    return false;
} 

int Party::partyGetId() const
{
    return mId;
}
int Party::getPartyIteration() const
{
    return mPartyIteration;
}
void Party::setPartyIteration(int iterr) 
{
    mPartyIteration = iterr;
}
void Party::addOffer(Simulation &sim,int coalitionId) 
{
    if(mState == Waiting){
        mState = CollectingOffers;
        mPartyIteration = sim.getIterationNum(); 
    }
    mOffers.push_back(coalitionId);
}

