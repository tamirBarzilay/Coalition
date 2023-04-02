#pragma once
#include <vector>

using std::vector;

class Party;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    Graph(const Graph& g);//copy constructor for simulation' copy
    Graph & operator = (const Graph &g);// copy assignment operator
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getPartyForActions(int partyId) ;
    vector<Party> &getPartyVec();
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
