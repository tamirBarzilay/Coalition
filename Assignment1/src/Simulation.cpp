#include "../include/Simulation.h"
#include "../include/Graph.h"



//constructor
Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) ,mCoalitions(), iterationCounter(0)
{
    for (size_t i = 0; i < agents.size(); i++)
    {
        Agent *currAgent = &agents[i];
        int currPartyId = currAgent->getPartyId();
        int mandates = graph.getMandates(currPartyId);
        vector<int> partiesId;
        partiesId.push_back(currPartyId);
        mCoalitions.push_back(new Coalition(i,mandates,partiesId,currAgent->getSelectionPolicy()->copy()));
    }
    
}
Simulation::~Simulation(){//destructor
    for (auto &&c : mCoalitions)
    {
        delete c;
    }
}
//copyConst
Simulation::Simulation(const Simulation &sim): mGraph(sim.mGraph), mAgents(sim.mAgents) , mCoalitions(sim.mCoalitions) , iterationCounter(sim.iterationCounter) 
{
}
//move constructor
Simulation::Simulation( Simulation &&sim): mGraph(sim.mGraph), mAgents(sim.mAgents) ,mCoalitions(sim.mCoalitions),iterationCounter(sim.iterationCounter) 
{
 sim.mCoalitions= {};
}
//copy assignment operator
Simulation &Simulation::operator=(const Simulation& sim){
    if(this!=&sim){
            for (auto &&c : mCoalitions)//delete pointers one by one.
            {
                delete c;
            }
            mCoalitions={};
            for (auto &&c : sim.mCoalitions)//copy pointers one by one.
            {
                mCoalitions.push_back(c);
            }
            iterationCounter=sim.iterationCounter;
            mGraph=sim.mGraph; 
            mAgents=sim.mAgents; 
        }
        return *this; 
}
//move assignment operator
Simulation &Simulation::operator=(Simulation &&sim){
    if (&sim != this){
            for (auto &&c : mCoalitions)
            {
                delete c;
            }
            mCoalitions =sim.mCoalitions;
            sim.mCoalitions ={};
            mAgents = sim.mAgents;
            mGraph=sim.mGraph;
            iterationCounter=sim.iterationCounter;

        }
        return *this;
}
void Simulation::step()
{
    
    // TODO implement this method
    vector<Party> &vec = mGraph.getPartyVec(); 
    for (auto &&p : vec)      //might be a problem if we dont get the original Party object
    {
        p.step(*this);
    }
    for (auto &&a : mAgents)
    {
        a.step(*this);
    }
    iterationCounter++;
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    int agentsL =mAgents.size();
    if(agentsL==mGraph.getNumVertices())//All parties are in state joined.
        return true;
    for (auto &&c : mCoalitions)
    {
        if(c->getCoalitionMandates()>=61)
            return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}
void Simulation::addAgent(Agent newAgent) 
{
    mAgents.push_back(newAgent);
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Party &Simulation::getPartyForActions(int partyId) 
{
    return mGraph.getPartyForActions(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> output;
    for (auto &&c : mCoalitions)
    {
        output.push_back(c->getPartiesId());
    }
    return output;
}
Coalition &Simulation::getCoalition(int coalitionId) 
{
    return *mCoalitions.at(coalitionId);
}
const int Simulation::getIterationNum() const
{
    return iterationCounter;
}




