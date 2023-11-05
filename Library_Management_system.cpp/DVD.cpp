//
//  DVD.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.

#include "LibraryItem.h"
#include "DVD.h"
#include<iostream>
#include<string>
using namespace std;


DVD::DVD(long int item_ID, float Cost, string stat, long int LoanP, string title, string cate, long int runtime, string stud, string dateOfRelease):LibraryItem(item_ID, Cost, stat, LoanP){
    
    Title = title;
    Category = cate;
    RunTime = runtime;
    Studio = stud;
    ReleaseDate = dateOfRelease;
}

void DVD::setTitle(string title){
    Title = title;
}
string DVD::getTitle(){
    return Title;
}
void DVD::setCategory(string cate){
    Category = cate;
}
string DVD::getCategory(){
    return Category;
}
void DVD::setRunTime(long int runtime){
    RunTime = runtime;
}
long int DVD::getRunTime(){
    return RunTime;
}
void DVD::setStudio(string stud){
    Studio = stud;
}
string DVD::getStudio(){
    return Studio;
}
void DVD::setReleaseDate(string dateOfRelease){
    ReleaseDate = dateOfRelease;
}
string DVD::getReleaseDate(){
    return ReleaseDate;
}
void DVD::printInfo(){
    LibraryItem::printInfo();
    cout<<"Title: "<<Title<<endl;
    cout<<"Category: "<<Category<<endl;
    cout<<"Run time: "<<RunTime<<endl;
    cout<<"Studio: "<<Studio<<endl;
    cout<<"Date of release: "<<ReleaseDate<<endl;
}

//friend ostream& operator<<(ostream& st, DVD& it);
