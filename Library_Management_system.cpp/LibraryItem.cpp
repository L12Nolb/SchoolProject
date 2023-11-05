//
//  LibraryItem.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#include "LibraryItem.h"
#include<string>
using namespace std;

LibraryItem::LibraryItem(long int id, float Cost, string stat, long int loanP){
    itemID = id;
    cost = Cost;
    status = stat;
    LoanPeriod = loanP;
}
void LibraryItem::setItemID(long int id){
    itemID = id;
}
long int LibraryItem::getItemID(){
    return itemID;
}
void LibraryItem::setCost(float Cost){
    cost = Cost;
}
float LibraryItem::getCost(){
    return cost;
}
void LibraryItem::setStatus(string stat){
    status = stat;
}
string LibraryItem::getStatus(){
    return status;
}
void LibraryItem::setLoanPeriod (long int loanP){
    LoanPeriod = loanP;
}
long int LibraryItem::getLoanPeriod (){
    return LoanPeriod;
}
void LibraryItem::printInfo(){
    cout<<"Item ID number: "<<itemID<<endl;
    cout<<"Item price: "<<cost<<endl;
    cout<<"Item status: "<<status<<endl;
    cout<<"Item loan period: "<<LoanPeriod<<endl;
    
}
void LibraryItem::rawprint(){
    cout<< itemID<<" "<<cost<<" "<<status<<" "<<LoanPeriod<<endl;
}
ostream& operator<<(ostream& st, LibraryItem& it){
    it.rawprint();
    return st;
}
