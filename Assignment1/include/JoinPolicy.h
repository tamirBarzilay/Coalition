#pragma once
#include <vector>
using std::vector;
class Simulation;

class JoinPolicy {
    public:
    virtual ~JoinPolicy(){};
    virtual int join(Simulation &sim,vector<int> &offers) const=0;
    virtual JoinPolicy * copy() const = 0;//copy constructor
};

class MandatesJoinPolicy : public JoinPolicy {
    JoinPolicy * copy() const override; // copy constructor

    int join(Simulation &sim,vector<int> &offers) const override ;
};

class LastOfferJoinPolicy : public JoinPolicy {
    int join(Simulation &sim,vector<int> &offers) const override ;
    JoinPolicy * copy() const override;//copy constructor
};