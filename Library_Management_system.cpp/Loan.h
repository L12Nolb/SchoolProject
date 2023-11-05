//
//  Loan.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#ifndef Loan_hpp
#define Loan_hpp
#include<string>
using namespace std;

class Loan{
public:
    Loan();
    Loan(long int idLoan, long int idItem, long int idPatron,time_t dueDate, string LoanStatus, bool recheck);
    void SetLoan_ID(long int idLoan);
    long int GetLoan_ID();
    void SetItem_ID(long int idItem);
    long int GetItem_ID();
    void SetPatron_ID(long int idPatron);
    long int GetPatron_ID();
    void SetDue_Date_time(time_t dueDate);
    time_t GetDue_Date_time();
    void SetLoan_curr_stat(string LoanStatus);
    string GetLoan_curr_stat();
    bool Get_recheck_stat();
    void Set_recheck_stat(bool status);
    
private:
    long int Loan_ID;
    long  int Item_ID;
    long int Patron_ID;
    time_t Due_Date_Time;
    string Loan_curr_stat;
    bool Loan_recheck_stat;
};

#endif /* Loan_hpp */
