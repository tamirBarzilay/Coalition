#include "../include/Graph.h"
#include "../include/Party.h"
Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

Graph::Graph(const Graph& g): mVertices(g.mVertices),mEdges(g.mEdges)
{}
//copy assignment operator
Graph &Graph::operator=(const Graph& g){
    mVertices=g.mVertices;
    mEdges = g.mEdges;
    return *this;
}
int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
Party &Graph::getPartyForActions(int partyId) 
{
    return mVertices[partyId];
}
vector<Party>  &Graph::getPartyVec()
{
    return mVertices;
}