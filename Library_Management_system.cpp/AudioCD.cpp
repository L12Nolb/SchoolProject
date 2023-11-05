//
//  AudioCD.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/9/21.
//

#include "AudioCD.h"
#include "LibraryItem.h"



AudioCD::AudioCD( long int item_ID, float Cost, string stat, long int LoanP, string artist, string title, int numTracks, string dateOfRelease, string genre):LibraryItem(item_ID, Cost, stat, LoanP)
{
    Artist = artist;
    Title = title;
    numberTracks = numTracks;
    releaseDate = dateOfRelease;
    Genre = genre;
}
void AudioCD::setArtist(string artist){
    Artist = artist;
}
string AudioCD::getArtist(){
    return Artist;
}
void AudioCD::setTitle(string title){
    Title = title;
}
string AudioCD::getTitle(){
    return Title;
}
void AudioCD::setNumberTracks(int numTracks){
    numberTracks = numTracks;
}
int AudioCD::getNumberTracks(){
    return numberTracks;
}
void AudioCD::setReleaseDate(string dateOfRelease){
    releaseDate= dateOfRelease;
}
string AudioCD::getReleaseDate(){
    return releaseDate;
}
void AudioCD::setGenre(string genre){
    Genre = genre;
}
string AudioCD::getGenre(){
    return Genre;
}

void AudioCD::printInfo(){
    LibraryItem::printInfo();
    cout<<"Artist: "<<Artist<<endl;
    cout<<"Title: "<<Title<<endl;
    cout<<"Number of tracks: "<<numberTracks<<endl;
    cout<<"Date of release: "<<releaseDate<<endl;
    cout<<"Genre: "<<Genre<<endl;
}

