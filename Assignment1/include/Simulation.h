#pragma once
#include <vector>
#include "Coalition.h"
#include "Graph.h"
#include "Agent.h"
#include "Party.h"
class Agent;
class Party;

using std::vector;


class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);//constructor
    virtual  ~Simulation();                            //destructor
    Simulation(const Simulation & sim);       // copy constructor
    Simulation(Simulation&& sim);             // move constructor
    Simulation &operator=(const Simulation& sim);  // copy assingment operator
    Simulation& operator=(Simulation&& sim); // move assignment operator
    void step(); 
    bool shouldTerminate() const; 
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    void  addAgent(Agent newAgent);
    const Party &getParty(int partyId) const;
    Party &getPartyForActions(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const; 
    Coalition &getCoalition(int coalitionId); 
    const int getIterationNum() const;

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition*> mCoalitions; 
    int iterationCounter;
};
