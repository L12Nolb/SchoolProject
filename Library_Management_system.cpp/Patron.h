//
//  Patron.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#ifndef Patron_h
#define Patron_h

#include<string>
using namespace std;
 
class Patron{
public:
    Patron();
    Patron(string PatronName, int PatronID, float fineAmount, int Books_Out);
    void SetName(string PatronName);
    string GetName();
    void SetIdNumber(int PatronID);
    int GetIdNumber();
    void SetfineBalance(float fineAmount);
    float GetfineBalance();
    void SetCurr_Num_Books_Out(int Books_Out);
    int GetCurr_Num_Books_Out();
    
private:
    string Name;
    int IdNumber;
    float fineBalance;
    int Curr_Num_Books_Out;
    
};


#endif /* Patron_hpp */
