#pragma once

class Graph;
class Agent;

class SelectionPolicy {
    public:
    virtual ~SelectionPolicy() = default;
    virtual int select( const Graph g,const Agent agent,int partyId) const=0 ;
    virtual SelectionPolicy* copy() const =0;
    //add assignement operator
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
        public:
        int select( const Graph g,const Agent agent,int partyId) const override;
        SelectionPolicy* copy() const override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
        public:
        int select( const Graph g,const Agent agent,int partyId) const override;
        SelectionPolicy* copy() const override; 
};

