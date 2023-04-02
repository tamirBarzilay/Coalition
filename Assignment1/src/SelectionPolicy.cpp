#include "../include/SelectionPolicy.h"
#include "../include/Graph.h"
#include "../include/Agent.h"
#include "../include/Party.h"

//class MandatesSelectionPolicy:

int MandatesSelectionPolicy::select( const Graph g,const Agent agent,int partyId) const
{
    int maxMandates = -1;
    int maxPartyId = -1;
    int numOfVertices = g.getNumVertices();
    for (auto i = 0; i < numOfVertices; i++)
    {
        // codition 1:
        if (g.getEdgeWeight(partyId, i) > 0 && g.getMandates(i) > maxMandates)
        {
            Party currParty = g.getParty(i);
            State PartyState = currParty.getState();
            // condition 2+3
            if (PartyState == Waiting || (PartyState == CollectingOffers && !currParty.offerFromSameCoalition(currParty,agent)))
            { 
                maxMandates = g.getMandates(i);
                maxPartyId = i;
            }
        }
    }
    return maxPartyId;
}
//copy constructor
SelectionPolicy* MandatesSelectionPolicy::copy() const{
        return new MandatesSelectionPolicy();
    }

//class EdgeWeightSelectionPolicy:
int EdgeWeightSelectionPolicy::select( const Graph g,const Agent agent,int partyId) const{
    int maxWeight =0;
    int maxPartyId = -1;
    int numOfVertices = g.getNumVertices();
    for (auto i = 0; i < numOfVertices; i++)
    {
        int currWeight = g.getEdgeWeight(partyId,i);
        // codition 1:
        if (currWeight > maxWeight)
        {
            Party currParty = g.getParty(i);
            State PartyState = currParty.getState();
            // condition 2+3
            if (PartyState == Waiting || (PartyState == CollectingOffers && !currParty.offerFromSameCoalition(currParty,agent)))
            { 
                maxWeight = currWeight;
                maxPartyId = i;
            }
        }
    }
    return maxPartyId;//what if there is no avalable party
}

//copy constructor
SelectionPolicy* EdgeWeightSelectionPolicy::copy() const{
        return new EdgeWeightSelectionPolicy();
    }



