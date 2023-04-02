#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include "../include/Coalition.h"

//Class MandatesJoinPolicy :

int MandatesJoinPolicy::join(Simulation &sim,vector<int> &offers) const {
    int id=offers.front();
    int max_mandate =sim.getCoalition(id).getCoalitionMandates();
    for (auto &&coalId : offers)
    {
        if(sim.getCoalition(coalId).getCoalitionMandates()>max_mandate){
            max_mandate=sim.getCoalition(coalId).getCoalitionMandates();
            id=coalId;
        }
    }
    return id;
}
//copy constructor
JoinPolicy* MandatesJoinPolicy::copy() const{
        return new MandatesJoinPolicy();
    }

//Class LastOfferJoinPolicy :

int LastOfferJoinPolicy::join(Simulation &sim,vector<int> &offers) const {
    
    return offers.back();
}
//copy constructor
JoinPolicy* LastOfferJoinPolicy::copy() const {
        return new LastOfferJoinPolicy();
    }