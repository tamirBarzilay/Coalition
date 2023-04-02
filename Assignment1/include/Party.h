#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"

using std::vector;
using std::string;

class Agent;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};


class Party
{
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mPartyIteration;
public:
    vector<int> mOffers; 
 
    Party(int id, string name, int mandates, JoinPolicy *); 
    virtual ~Party();
    Party(const Party & party);//copy const
    Party(Party && party);//move const
    Party & operator=(const Party & party); //copy assignment operator
    Party& operator=(Party&& party); //move assignement operator
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    bool offerFromSameCoalition(Party &currParty, const Agent agent) const;  //to complete
    int partyGetId() const;
    int getPartyIteration() const;
    void setPartyIteration(int iterr);
    void addOffer(Simulation &sim, int coalitionId);

};

