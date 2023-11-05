//
//  Book.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//
#include "LibraryItem.h"
#include "Book.h"
#include<iostream>
#include <string>

using namespace std;

Book::Book(long int item_ID, float Cost, string stat, long int LoanP, string title, string author, string isbn, string cate):LibraryItem(item_ID, Cost, stat, LoanP){
    
    Title = title;
    Author = author;
    ISBN_number = isbn;
    Category = cate;
}

void Book::setTitle(string title){
    Title = title;
}
string Book::getTitle (){
    return Title;
}
void Book::setAuthor(string author){
    Author = author;
}
string Book::getAuthor(){
    return Author;
}
void Book::setISBN_number(string isbn){
    ISBN_number = isbn;
}
string Book::getISBN_number(){
    return ISBN_number;
}
void Book::setCategory(string cate){
    Category = cate;
    
}
string Book::getCategory(){
    return Category;
}

void Book::printInfo(){
    LibraryItem::printInfo();
    cout<<"Title: "<<Title<<endl;
    cout<<"Author: "<<Author<<endl;
    cout<<"ISBN number: "<<ISBN_number<<endl;
    cout<<"Category: "<<Category<<endl;
}
void Book::rawprint(){
    LibraryItem::rawprint();
    cout<<Title<<endl;
    cout<<Author<<endl;
    cout<<ISBN_number<<endl;
    cout<<Category<<endl;
}
