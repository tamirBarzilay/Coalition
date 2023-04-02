#pragma once

#include <vector>
#include "SelectionPolicy.h"

using std::vector;
class Party; 

class Coalition
{
public:
    Coalition(int CoalitionId,int Mandates,vector<int> PartiesId,SelectionPolicy * selectionPolicy);
    virtual ~Coalition();                            //destructor
    Coalition(const Coalition & c);       // copy constructor
    Coalition(Coalition&& c);             // move constructor
    Coalition &operator=(const Coalition& c); // copy assingment operator
    Coalition& operator=(Coalition&& c); // move assignment operator
    int getCoalitionId()const;
    int getCoalitionMandates() const;
    void addParty(const Party *party); 
    SelectionPolicy *getSelectionPolicy() const; 
    vector<int> getPartiesId() const;
   
private:
    int mCoalitionId;
    int mMandates;
    vector<int> mPartiesId;
    SelectionPolicy * mSelectionPolicy;
};
