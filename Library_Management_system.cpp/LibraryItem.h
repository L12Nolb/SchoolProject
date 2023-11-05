//
//  LibraryItem.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#ifndef LibraryItem_h
#define LibraryItem_h

#include <iostream>
#include<string>

using namespace std;

class LibraryItem{
    public:
    
    virtual ~LibraryItem(){ };//destructor
    LibraryItem(long int id, float Cost, string stat, long int loanP);
    void setItemID(long int id);
    long int getItemID();
    void setCost(float Cost);
    float getCost();
    void setStatus(string stat);
    string getStatus();
    void setLoanPeriod (long int loanP);
    long int getLoanPeriod ();
    virtual void printInfo();
    virtual void rawprint();
    friend ostream& operator<<(ostream  &st, LibraryItem &it);
protected:
    long int itemID;
    float cost;
    string status;
    long int LoanPeriod;
};

#endif /* LibraryItem_hpp */
