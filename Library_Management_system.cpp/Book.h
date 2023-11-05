//
//  Book.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#ifndef Book_h
#define Book_h

#include<string>
#include "LibraryItem.h"
using namespace std;

class Book: public LibraryItem{
private:
    string Title;
    string Author;
    string ISBN_number;
    string Category;
public:
    Book(long int item_ID, float Cost, string stat, long int LoanP, string title, string author, string isbn, string cate);
    
    void setTitle(string title);
    string getTitle ();
    void setAuthor(string author);
    string getAuthor();
    void setISBN_number(string isbn);
    string getISBN_number();
    void setCategory(string cate);
    string getCategory();
    
    void printInfo();
    void rawprint();
    friend ostream& operator<<(ostream& st, Book& it);
};


#endif /* Book_h */
