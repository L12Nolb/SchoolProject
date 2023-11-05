//
//  LibraryItems.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/10/21.
//
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<typeinfo>
#include<cstdlib>
#include<ctime>
#include "LibraryItems.h"
#include "LibraryItem.h"
#include "AudioCD.h"
#include "Book.h"
#include "DVD.h"

using namespace std;

bool LibraryItems::isInt(string gag){
  bool num = false;
  
  for(int i = 0; i < gag.length(); ++i){
    if(isdigit(gag.at(i))){//check if every entry of the string is a digit
      num = true;
    }else{
      num = false;
      break;
    }
  }
  
  return num;
}

bool LibraryItems::isFloat(string a){
  bool num = false;
    bool point_encounter = false;
  
  for(int i = 0; i < a.length(); ++i){
    if(isdigit(a.at(i))){//check if every entry of the string is a digit
      num = true;
    }else if (a.at(i) == '.' && point_encounter == false ){
        point_encounter = true;
        num = true;
    }else if (i+1){
        num = false;
        break;    }
  }
  
  return num;
}

LibraryItems::LibraryItems (){
    itemcount = 0;
    loadItem();
}
LibraryItems::~LibraryItems(){
    storeItem();
    cleanup();
}

int LibraryItems::getcount(){
    return itemcount;
}
void LibraryItems::inccount(){
    itemcount++;
}
void LibraryItems::deccount(){
    itemcount--;
}

void LibraryItems::Add_item (){
    srand(time(NULL));
    long int itemID, loanP, runtime;
    float cost;
    string stat = "In", artist, title, releaseDate, genre, author, isbn, category,studio, dummy,dummy1;
    int numTracks;
    char choice;
    LibraryItem * temp;
    
    itemID = (rand()% 40000+ 100000);//generate a unique 6 digits ID number
    cout<<"The new library item ID number you are creating is: "<<itemID<<endl;
    
    cout<<"Enter the item cost ($): ";
    cin>>dummy;
    while(isFloat(dummy)==false){//catch errors if input is different from digit
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    cost= stof(dummy);
    
    cout<<"Do you want to create : "<<endl;
    cout<<"a. Audio CD item "<<endl;
    cout<<"b. Book item "<<endl;
    cout<<"c. DVD item "<<endl;
    cin>>choice;
    
    while(choice !='a' && choice!= 'b'&& choice !='c'){//execute if user enter wrong option
        cout<<"Invalid choice. Try again"<<endl;
        cin>>choice;
    }
    cin.ignore();
    
    if(choice=='a'){//to create Audio CD new item in the catalog
        loanP = 172800;//set loan period for audio CD to 2 days
        cout<<"The loan period for an Audio CD is 2 days"<<endl<<endl;
        
        cout<<"Enter the Artist name: ";
        getline(cin, artist);
        
        cout<<"Enter the title of this audio CD: ";
        getline(cin, title);
        
        cout<<"Enter the audio CD genre (Pop, Classic Rock, Classical, Christian, Jazz, New age,...): ";
        getline(cin, genre);
        
        cout<<"Enter the date of release of this audio CD: ";
        getline(cin, releaseDate);
        
        cout<<"Enter the number of tracks on this CD: ";
        cin>>dummy1;
        while(isInt(dummy1)==false){//catch error if input is not didgit
            cout<<"Invalid input. Try again"<<endl;
            cin>>dummy1;
        }
        
        numTracks = stoi(dummy1);//assign numTracks with integer value
    
        temp= new AudioCD(itemID, cost, stat, loanP, artist, title, numTracks, releaseDate, genre);//assign temp with audio CD item
    }
    
    else if(choice =='b'){//to create book new item in the catalog
        loanP = 864000;//set loan period of a book to 10 days
        cout<<"The loan period for a book item is 10 days"<<endl;
        
        cout<<"Enter the Author name: ";
        getline(cin, author);
        
        cout<<"Enter the title of this book: ";
        getline(cin, title);
        
        cout<<"Enter the ISBN number of this book: ";
        getline(cin, isbn);
        
        cout<<"Enter the category of this book: ";
        getline(cin, category);
        
        temp = new Book(itemID, cost, stat, loanP, title, author, isbn, category);//assign temp with book item
    }
    else if(choice == 'c'){//to create a DVD new item in the catalog
        loanP = 259200;//set loan period for audio CD to 3 days
        cout<<"The loan period for a DVD is 3 days"<<endl;
        
        cout<<"Enter the title of this DVD: ";
        getline(cin, title);
        
        cout<<"Enter the category of this DVD (Action, SciFi, Drama,..): ";
        getline(cin, category);
        
        cout<<"Enter the studio of this DVD: ";
        getline(cin, studio);
        
        cout<<"Enter the date of release of this DVD: ";
        getline(cin, releaseDate);
        
        cout<<"Enter the number run time of this DVD (in minutes): ";
        cin>>dummy1;
        
        while(isInt(dummy1)==false){//catch error if input is not didgit
            cout<<"Invalid input. Enter time in minutes: "<<endl;
            cin>>dummy1;
        }
        
        runtime = stoi(dummy1);//assign numTracks with integer value
        
        temp = new DVD(itemID, cost, stat, loanP, title, category, runtime, studio, releaseDate);//assig temp with DVD item
    }
    LibraryItemList.push_back(temp);// add the new create item to the catalog
    inccount();//increase the new of element in the catalog
    cout<<"Item successfully added"<<endl;
}

void LibraryItems::Edit_item(){
    long int itemID;
    float newCost;
    char choice;
    string dummy;
    
    cout<<"Enter the library ID number of the item you would like to edit: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch error if input is not didgit
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    itemID = stoi(dummy);//assign numTracks with integer value
    cout<<"Item ID: "<<itemID<<endl;
    for(auto it = LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        if((*it)->getItemID()== itemID){//check if item Id match any in the collection
            
            cout<<"What information are you trying to edit: "<<endl;
            cout<<"a - Cost "<<endl;
            cout<<"b - Item current status"<<endl;
            cin>>choice;
            
            while (choice!='a' && choice!='b' &&choice!='B' && choice!='A'){
                cout<<"Invalid option. Try again: ";
                cin>>choice;
            }
            cin.ignore();
            
            if (choice == 'a'||choice =='A'){//execute if user wants  to chance the price of an item
                
                cout<<"Enter the new cost of this item: ";
                cin>>newCost;
                (*it)->setCost(newCost);//edit the old price of the item and save the new price in the catalog
                    break;
            }
            else if(choice == 'B'|| choice =='b'){//execute if user wants to change the item  collection
                Edit_itemstat(itemID);
                break;
                }
            
        }
        
        else if(Search_item(itemID)==NULL){
            cout<<"Item not found in the collecetion. Nothing modify."<<endl;
        }
    }
}

void LibraryItems::Edit_itemstat(long int itemID){
    string newStat;
    char choice;
    do{
        cout<<"What is the item new status? "<<endl;
        cout<<"I - In\t R - Repair\t O - Out\t L - Lost"<<endl;
        cin>>choice;
        
        if(choice == 'I' || choice =='i'){//execute if the user wants to set the book status to In
            newStat = "In";
        }
        else if(choice == 'R' || choice =='r'){//Execute if the user desires to set the book status to repair
            newStat = "Repair";
        }
        else if(choice == 'O' || choice =='o'){//Execute if the user wants to set the book status to Out
            newStat = "Out";
        }
        else if(choice == 'L' || choice =='l'){//execute if the user wants to set the book status to lost
            newStat = "Lost";
        }
        else{
            cout<<"invalid choice. Please enter a valid one";//will execute if user enter wrong choice
        }
    }while(choice != 'i' && choice != 'I' && choice != 'o' &&choice != 'R' &&choice != 'r' &&choice != 'O');
    
    for(auto it = LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        
        if((*it)->getItemID() == itemID){//check if the passed ID match any in the collection
            
            (*it)->setStatus(newStat);//save the modification in the library item collection
        }
    }
    storeItem();
}

void LibraryItems::Delete_item(long int itemID){
    for(auto it = LibraryItemList.begin(); it!=LibraryItemList.end(); ++it){
        if((*it)->getItemID()== itemID){//search if id match any in the collection
            LibraryItemList.erase(it);//delete item at that specific position
            break;
        }
    }
}
long int LibraryItems::accessLoanPeriod(long int itemID){
    long int loanP =0;
    for(auto it = LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        if((*it)->getItemID()== itemID){//check if itemID match any in the catalog
            loanP = (*it)->getLoanPeriod();//assign loanP with loan Period of that specific item
            break;//stop the search when the patron is found
        }
    }
    return loanP;//return the loan period of the item
}

LibraryItem*  LibraryItems::Search_item(long int itemID){//fixme
    LibraryItem *temp = NULL;
    for(long int i =0; i<itemcount; i++){
        if(LibraryItemList.at(i)->getItemID()==itemID){
            temp = LibraryItemList.at(i);//assign temp with the library item found at the position i
            break;
        }
    }
    return temp;
}

void LibraryItems::PrintItems(){//Fixme
    
    for(auto it = LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        
        if(typeid (**it)== typeid(AudioCD)){
            AudioCD *temp = dynamic_cast <AudioCD*>(*it);
            (*it)->printInfo();
        }
        else if(typeid(**it)== typeid(Book)){
            Book *temp = dynamic_cast <Book*>(*it);
            (*it)->printInfo();
        }
        else if(typeid(**it)== typeid(DVD)){
            DVD *temp = dynamic_cast <DVD*>(*it);
            (*it)->printInfo();
        }
        cout<<endl<<endl;
    }
    cout<<endl;
}
void LibraryItems::PrintItem(long int itemID){//fixme
    for(auto it= LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        if((*it)->getItemID()==itemID){
            if(typeid (**it)== typeid(AudioCD)){
                AudioCD *temp = dynamic_cast <AudioCD*>(*it);
                (*it)->printInfo();
                break;
            }
            else if(typeid(**it)== typeid(Book)){
                Book *temp = dynamic_cast <Book*>(*it);
                (*it)->printInfo();
                break;
            }
            else if(typeid(**it)== typeid(DVD)){
                DVD *temp = dynamic_cast <DVD*>(*it);
                (*it)->printInfo();
                break;
            }
        }
        cout<<endl<<endl;
    }
}
bool LibraryItems::search_item_availability(long int itemID){
    bool stat= true;
    for(auto it= LibraryItemList.begin(); it!=LibraryItemList.end(); ++it){
        if((*it)->getItemID()==itemID){
            if((*it)->getStatus()=="Out"||(*it)->getStatus()=="Lost"||(*it)->getStatus()=="Repair"){
                
                stat = false;//will return false if the item current status is different from "In"
                
                break;
            }
        }
    }
    return stat;
}

float LibraryItems::item_Cost(long int itemID){
    float cost= 0.0;
    
    for(auto it = LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        if((*it)->getItemID()== itemID){
            cost = (*it)->getCost();
        }
    }
    return cost;
}
//bool LibraryItems::isInt(string gag){
//
//}

void LibraryItems::cleanup(){
    for(auto it = LibraryItemList.begin(); it!=LibraryItemList.end(); ++it){
        delete *it;//clean up the pointer allocated mememory
    }
    LibraryItemList.clear();//clean up the vector
}

void LibraryItems::storeItem(){
    
    ofstream fout;
    fout.open("libraryItem.dat");//open library catalog file
    fout<<itemcount<<endl;
    LibraryItem *temp;
    
    for(auto it =LibraryItemList.begin(); it!= LibraryItemList.end(); ++it){
        temp =*it;
        
        fout<<temp->getItemID()<<" "<<temp->getCost()<<" "<<temp->getStatus()<<" "<<temp->getLoanPeriod()<<" "<<endl;
        
        if(typeid(**it) == typeid(AudioCD)){
            AudioCD *temp = dynamic_cast<AudioCD*>(*it);
            
            fout<<"1"<<endl;
            fout<<temp->getArtist()<<endl;
            fout<<temp->getTitle()<<endl;
            fout<<temp->getGenre()<<endl;
            fout<<temp->getReleaseDate()<<endl;
            fout<<temp->getNumberTracks()<<endl;
        }
        else if(typeid(**it) == typeid(Book)){
            Book *temp = dynamic_cast<Book*>(*it);
            
            fout<<"2"<<endl;
            fout<<temp->getTitle()<<endl;
            fout<<temp->getAuthor()<<endl;
            fout<<temp->getISBN_number()<<endl;
            fout<<temp->getCategory()<<endl;
        }
        else  if(typeid(**it) == typeid(DVD)){
            DVD *temp = dynamic_cast<DVD*>(*it);
            
            fout<<"3"<<endl;
            fout<<temp->getTitle()<<endl;
            fout<<temp->getCategory()<<endl;
            fout<<temp->getStudio()<<endl;
            fout<<temp->getReleaseDate()<<endl;
            fout<<temp->getRunTime()<<endl;
        }
    }
    fout.close();
}
//
void LibraryItems::loadItem(){
    ifstream fin;
    long int itemID, loanP, runtime;
    float cost;
    string stat, artist, title, releaseDate, genre, author, isbn, category,studio;
    int numTracks,type;
    string line;
    
    fin.open("libraryItem.dat");
    
    if(fin.fail()){
        storeItem();
    }
    else{
        
    fin>>itemcount;
    fin.ignore();
    
    for(long int i=0; i<itemcount; ++i){//fixme
        
        fin>>itemID>>cost>>stat>>loanP>>type;
        fin.ignore();
        if(type ==1){
            getline(fin, artist);
            getline(fin, title);
            getline(fin, genre);
            getline(fin,releaseDate);
            fin>>numTracks;
            LibraryItemList.push_back(new AudioCD(itemID, cost, stat, loanP, artist, title, numTracks, releaseDate, genre));
        }
        else if (type ==2){
            getline(fin, title);
            getline(fin,author);
            getline(fin, isbn);
            getline(fin, category);
           LibraryItemList.push_back(new Book(itemID, cost, stat, loanP, title, author, isbn, category));
        }
        else if (type == 3){
            getline(fin, title);
            getline(fin, category);
            getline(fin, studio);
            getline(fin, releaseDate);
            fin>>runtime;
            LibraryItemList.push_back(new DVD(itemID, cost, stat, loanP, title, category, runtime, studio, releaseDate));
        }
    }
  }
    fin.close();
}

