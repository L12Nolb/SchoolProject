//
//  AudioCD.hpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#ifndef AudioCD_h
#define AudioCD_h

#include <iostream>
#include<string>
#include "LibraryItem.h"
using namespace std;

class AudioCD: public LibraryItem{
private:
    string Artist;
    string Title;
    int numberTracks;
    string releaseDate;
    string Genre;
    
public:
    AudioCD( long int itemID, float cost, string status, long int LoanPeriod, string artist, string title, int numTracks, string dateOfRelease, string genre);
    void setArtist(string artist);
    string getArtist();
    void setTitle(string title);
    string getTitle();
    void setNumberTracks(int numTracks);
    int getNumberTracks();
    void setReleaseDate(string dateOfRelease);
    string getReleaseDate();
    void setGenre(string genre);
    string getGenre();
    
    void printInfo();
    //friend ostream& operator<<(ostream& st, AudioCD& it);
    
};

#endif /* AudioCD_hpp */
