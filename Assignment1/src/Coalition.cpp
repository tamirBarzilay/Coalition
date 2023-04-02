#include "../include/Coalition.h"
#include "../include/Agent.h"
#include "../include/Party.h"

Coalition::Coalition(int CoalitionId,int Mandates,std::vector<int> PartiesId, SelectionPolicy * selectionPolicy) : mCoalitionId(CoalitionId),mMandates(Mandates),mPartiesId(PartiesId),mSelectionPolicy(selectionPolicy)
{
}
Coalition::~Coalition(){//destructor
    if (mSelectionPolicy) delete mSelectionPolicy;
}
//copyConst
Coalition::Coalition(const Coalition &c): mCoalitionId(c.mCoalitionId), mMandates(c.mMandates) , mPartiesId(c.mPartiesId) , mSelectionPolicy(NULL) 
{
    mSelectionPolicy = c.mSelectionPolicy->copy();
}
//move constructor
Coalition::Coalition( Coalition &&c):mCoalitionId(c.mCoalitionId), mMandates(c.mMandates) , mPartiesId(c.mPartiesId),mSelectionPolicy(c.mSelectionPolicy)
{
    c.mSelectionPolicy=nullptr;
}
//copy assignment operator
Coalition &Coalition::operator=(const Coalition& c) {
    if(this!=&c){
            delete mSelectionPolicy;
            mSelectionPolicy=nullptr;
            mSelectionPolicy=c.mSelectionPolicy->copy();
            mCoalitionId=c.mCoalitionId;
            mMandates=c.mMandates;
            mPartiesId=c.mPartiesId;
        }
        return *this; 
}
//move assignment operator
Coalition &Coalition::operator=(Coalition &&c){
     if (&c != this){
            delete mSelectionPolicy;
            mSelectionPolicy =c.mSelectionPolicy;
            c.mSelectionPolicy =nullptr;
            mCoalitionId=c.mCoalitionId;
            mMandates=c.mMandates;
            mPartiesId=c.mPartiesId;
        }
        return *this;
}
int Coalition::getCoalitionId() const
{
    return mCoalitionId;
}

int Coalition::getCoalitionMandates() const
{
    return mMandates;
} 
void Coalition::addParty(const Party *party) 
{
    mPartiesId.push_back(party->partyGetId());
    mMandates = mMandates + party->getMandates();
}
SelectionPolicy* Coalition::getSelectionPolicy() const
{
    return mSelectionPolicy;
}
vector<int> Coalition::getPartiesId() const
{
    return mPartiesId;
}