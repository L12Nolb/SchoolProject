//
//  DVD.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#ifndef DVD_h
#define DVD_h

#include <iostream>
#include<string>
#include"LibraryItem.h"

using namespace std;

class DVD: public LibraryItem{
private:
    string Title;
    string Category;
    long int RunTime;
    string Studio;
    string ReleaseDate;
    
public:
    DVD(long int item_ID, float Cost, string stat, long int LoanP, string title, string cate, long int runtime, string stud, string dateOfRelease);
    
    void setTitle(string title);
    string getTitle();
    void setCategory(string cate);
    string getCategory();
    void setRunTime(long int runtime);
    long int getRunTime();
    void setStudio(string stud);
    string getStudio();
    void setReleaseDate(string dateOfRelease);
    string getReleaseDate();
    void printInfo();
    //friend ostream& operator<<(ostream& st, DVD& it);
};

#endif /* DVD_hpp */
