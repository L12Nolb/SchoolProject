//
//  LibraryItems.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/10/21.
//

#ifndef LibraryItems_h
#define LibraryItems_h

#include <iostream>
#include <string>
#include <vector>
#include "LibraryItem.h"
#include "AudioCD.h"
#include "Book.h"
#include "DVD.h"

using namespace std;

class LibraryItems{
private:
    int itemcount;
    vector<LibraryItem*> LibraryItemList;
public:
    LibraryItems ();
    ~LibraryItems();
    
    int getcount();
    void inccount();
    void deccount();
    
    void Add_item ();
    void Edit_item();
    void Edit_itemstat(long int itemID);
    void Delete_item(long int itemID);
    LibraryItem*  Search_item(long int itemID);
    void PrintItems();
    void PrintItem(long int itemID);
    void loadItem();
    void storeItem();
    void cleanup();
    bool search_item_availability(long int itemID);
    float item_Cost(long int itemID);
    long int accessLoanPeriod(long int itemID);
    bool isInt(string gag);
    bool isFloat(string a);
};
#endif /* LibraryItems_h */
