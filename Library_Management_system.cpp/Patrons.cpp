//
//  Patrons.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<iterator>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Patron.h"
#include "Patrons.h"

bool Patrons::isInt(string gag){
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

bool Patrons::isFloat(string a){
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

void Patrons::Add_patron(){
    srand(time(NULL));
    Patron singPatron;
    string name;
    int id;
    float balance =0.0;
    int book_out =0;
    
    id = (rand()% 12000+100000);
    cout<<"New patron ID is: "<<id<<endl;
    
    cout<<"Enter new patron Name: ";
    getline(cin, name);
    
    
    singPatron = Patron(name, id, balance, book_out);
    patronList.push_back(singPatron);//Add new patron at the end of the list
    cout<<"Patron successfully added!"<<endl;
    storePatron();
}

void Patrons::Delete_patron(int id){
    for(int i = 0; i<patronList.size(); ++i){
        if(patronList.at(i).GetIdNumber()== id){//search if the id match any in the data base
            patronList.erase(patronList.begin()+i);//erase all the patron information at that position
            break;
        }
        else{
            cout<<"Patron not found in the list. Nothing removed."<<endl;
        }
    }
    storePatron();
}


void Patrons::Edit_patronName(){
    
    Patron singPatron;
    int patronID;
    string newName;
    string dummy;
    
     cout<<"Enter the ID number of the patron you want to edit: ";
    cin>>dummy;
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    patronID= stoi(dummy);
    
    singPatron.SetIdNumber(patronID);
     cin.ignore();
     cout<<"Enter the new name of the patron: ";
    getline(cin,newName);
    singPatron.SetName(newName);
     
    
    for(int i=0; i<patronList.size(); ++i){
        if(patronList.at(i).GetIdNumber()==singPatron.GetIdNumber()){
            
            patronList.at(i).SetName(singPatron.GetName());
            break;
        }
        else if(i+1==patronList.size()){
            cout<<"Patron not found in the list. Nothing modified."<<endl;
            }
    }
    
    storePatron();
    
}

void Patrons::Edit_NumBooksOut(int id, int newNum){
    vector<Patron>::iterator it;
    
    for( it= patronList.begin(); it!= patronList.end(); ++it){
        if(it->GetIdNumber()==id){
            
            it->SetCurr_Num_Books_Out(it->GetCurr_Num_Books_Out()+ newNum);//will decrement or increment the number of book out and save it in the collection.
            break;
        }
    }
    storePatron();
}

void Patrons::Edit_fine(int patronID, float amount){
    vector<Patron>::iterator it;

    for(it= patronList.begin(); it!= patronList.end(); ++it){
        if(it->GetIdNumber()==patronID){//check if patron ID match any in the collection
            
            
            it->SetfineBalance(it->GetfineBalance() + amount);// will modify the fine balance accordingly
            break;
            
    
        }
    }
}


void Patrons::PayFine(){//to pay any fine
    vector<Patron>::iterator it;
    int patronID;
    float amount;
    string dummy, dummy1;
    
    cout<<"Enter patron ID: ";
    cin>>dummy;
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    patronID= stoi(dummy);
    
    cout<<"How much would you like to pay? ";
    cin>>dummy1;
    while(isFloat(dummy1)==false){
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy1;
    }
    amount = stof(dummy1);
    for(it= patronList.begin(); it!= patronList.end(); ++it){
        if(it->GetIdNumber()== patronID){//check if the patron ID match any in the collection
            it->SetfineBalance(it->GetfineBalance() - amount);//substract the amount from the total balance fine
            break;
        }
    }
}

int Patrons::Search_patron(int id){
    
    int i = -1;
    
    for (int index =0; index <patronList.size(); ++index){
        
        if(patronList.at(index).GetIdNumber() == id){
            i = index;//assign the variable i with the position at which the patron was found
            cout<<"Patron found at index: "<<i<<endl;
            break;
            
        }else{
            i = -1;//if patron is not found, assign i with -1
        }
    }
    return i;
}
void Patrons::PrintPatrons(){//print all patrons information
    
    sort(patronList.begin(), patronList.end(), [](Patron& ls, Patron& rs)
         {
        return ls.Patron::GetName() < rs.Patron::GetName();
    });//sorting by patrons name it is case sensisitive Uppercases prioritized be cautious

    for(int i=0; i< patronList.size(); ++i){
        cout<<"Name: "<<patronList.at(i).GetName()<<endl;
        cout<<"ID number: "<<patronList.at(i).GetIdNumber()<<endl;
        cout<<"Fine Balance: "<<patronList.at(i).GetfineBalance()<<endl;
        cout<<"Number of books out: "<<patronList.at(i).GetCurr_Num_Books_Out()<<endl<<endl<<endl;
    }
}
void Patrons::PrintPatron(int id){//print one patron information
    for(auto it = patronList.begin(); it != patronList.end(); ++it){
        if (it->GetIdNumber() == id){//search if patron exist in the collection
            
            //print the patron information
    cout<<"Patron's name: "<<it->GetName()<<endl;
    cout<<"Patron's ID number: "<<it->GetIdNumber()<<endl;
    cout<<"Fine balance $: "<<it->GetfineBalance()<<endl;
    cout<<"Current number of books out: "<<it->GetCurr_Num_Books_Out()<<endl;
        }
    }
}

void Patrons::storePatron(){//seperate information by a semi colon
    
    ofstream fout;
    fout.open("patron.dat");
    
    for(auto it=patronList.begin(); it!= patronList.end(); ++it){
        fout<<it->GetName()<<";"<<it->GetIdNumber()<<";"<<it->GetfineBalance()<<";"<<it->GetCurr_Num_Books_Out()<<endl;
    }
    fout.close();
}

void Patrons::loadPatron(){//load the data in the vector
    ifstream fin;
    ofstream fout;
    string name;
    string id;//int
    string balance;//float
    string book_out;//int
    string line;
    int _id, _book_out;
    float _balance;
    
    //storePatron();
    fin.open("patron.dat");
    
    if(fin.fail()){
        storePatron();
//        fout.open("patron.dat");
//
//        fout.close();
    }
    else{
    while(getline(fin, line)){//read a line
        stringstream ss(line);//read words and stop when semi colon is read
        
        getline(ss, name, ';');
        getline(ss, id, ';');
        _id = stoi(id);
        getline(ss, balance, ';');
        _balance = stof(balance);
        getline(ss, book_out, ';');
        _book_out = stoi(book_out);
        
        
        patronList.push_back(Patron(name, _id, _balance, _book_out));
    }
    }
    fin.close();
    
}

void Patrons::cleanup(){//clear the vector
    
    patronList.clear();
}
