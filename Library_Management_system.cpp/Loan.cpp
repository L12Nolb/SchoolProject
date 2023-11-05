//
//  Loan.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#include "Loan.h"
#include<iostream>
using namespace std;

#include "Loan.h"

Loan::Loan(){
    Loan_ID = -9999;
    Item_ID=  -111;
    Patron_ID= -888;
    Due_Date_Time = 0;
    Loan_curr_stat = "Normal";
    Loan_recheck_stat = false;
}

Loan::Loan (long int idLoan, long int idItem, long int idPatron,time_t dueDate, string LoanStatus, bool recheck){
    
    Loan_ID = idLoan;
    Item_ID = idItem;
    Patron_ID = idPatron;
    Due_Date_Time = dueDate;
    Loan_curr_stat = LoanStatus;
    Loan_recheck_stat = recheck;
}

void Loan::SetLoan_ID(long int idLoan){
    Loan_ID = idLoan;
}
long int Loan::GetLoan_ID(){
    return Loan_ID;
}

void Loan::SetItem_ID(long int idItem){
    Item_ID = idItem;
}
long int Loan::GetItem_ID(){
    return Item_ID;
}

void Loan::SetPatron_ID(long int idPatron){
    Patron_ID = idPatron;
}
long int Loan::GetPatron_ID(){
    return Patron_ID;
}

void Loan::SetDue_Date_time(time_t dueDate){

    Due_Date_Time = dueDate;
}
time_t Loan::GetDue_Date_time(){
    return Due_Date_Time;
}

void Loan::SetLoan_curr_stat(string LoanStatus){
    Loan_curr_stat = LoanStatus;
}
string Loan::GetLoan_curr_stat(){
    return Loan_curr_stat;
}

bool Loan::Get_recheck_stat(){
    return Loan_recheck_stat;
}
void Loan::Set_recheck_stat(bool status){
    Loan_recheck_stat = status;
}

