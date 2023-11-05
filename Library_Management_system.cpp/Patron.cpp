//
//  Patron.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//
#include<iostream>
using namespace std;

#include "Patron.h"

Patron::Patron(){
    Name = "None";
    IdNumber = -1;
    fineBalance = 0.0;
    Curr_Num_Books_Out = 0;
}
Patron::Patron(string PatronName, int PatronID, float fineAmount, int Books_Out){
    Name = PatronName;
    IdNumber = PatronID;
    fineBalance = fineAmount;
    Curr_Num_Books_Out = Books_Out;
}
void Patron::SetName(string PatronName){
    Name = PatronName;
}
string Patron::GetName(){
    return Name;
}
void Patron::SetIdNumber(int PatronID){
    IdNumber= PatronID;
}
int Patron::GetIdNumber(){
    return IdNumber;
}
void Patron::SetfineBalance(float fineAmount){
    fineBalance = fineAmount;
}
float Patron::GetfineBalance(){
    return fineBalance;
}
void Patron::SetCurr_Num_Books_Out(int Books_Out){
    Curr_Num_Books_Out = Books_Out;
}
int Patron::GetCurr_Num_Books_Out(){
    return Curr_Num_Books_Out;
}

