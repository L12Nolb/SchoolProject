//
//  Patrons.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#ifndef Patrons_h
#define Patrons_h

#include<string>
#include<vector>
#include "Patron.h"
using namespace std;

class Patrons{
public:
    void Add_patron();
    void Edit_patronName();
    void Edit_NumBooksOut(int id, int newNum);
    void Delete_patron(int id);
    void PayFine();
    int Search_patron(int id);
    void PrintPatrons();
    void PrintPatron(int id);
    void loadPatron();
    void storePatron();
   void Edit_fine(int patronID, float amount);
    bool isInt(string gag);
    bool isFloat(string a);
    void cleanup();
private:
    vector<Patron>patronList;
};

#endif /* Patrons_hpp */
