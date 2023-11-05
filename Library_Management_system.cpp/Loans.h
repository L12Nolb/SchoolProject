//
//  Loans.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#ifndef Loans_h
#define Loans_h

#include<string>
#include<vector>
#include<list>
#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "LibraryItems.h"

using namespace std;

class Loans{
public:
    
    void Check_out_book(Patrons &list, LibraryItems &collection);
    void Check_in_book(Patrons &singPatron, LibraryItems &singItem);
    void Overdue_list(Patrons &singPatron);
    void ItemPatron_list(LibraryItems &ItemPatron);
    void UpdateLoan_stat();
    void Re_check_book();
    void Edit_Loan();
    void ReportLost(Patrons &singpatron, LibraryItems &singItem);
    void storeLoan();
    void loadLoan();
    bool isInt(string gag);
    bool isFloat(string a);
    void cleanup();
private:
    vector<Loan>LoanList;
    list<int>overdue;
    list<int>bookPatronList;
};

#endif /* Loans_hpp */
