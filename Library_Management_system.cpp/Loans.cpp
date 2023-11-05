//
//  Loans.cpp
//  csce1040project4.cpp
//
//  Created by LOIS on 4/14/21.
//
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<cstdlib>
#include<ctime>

using namespace std;

#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "LibraryItem.h"
#include "AudioCD.h"
#include "Book.h"
#include "DVD.h"

bool sortAscending(int i, int j){
   return (i < j);
}

bool Loans::isInt(string gag){
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

bool Loans::isFloat(string a){
    
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

void Loans::Check_out_book(Patrons &singPatron, LibraryItems &singItem){
    Patron pat;
    long int patronID;
    string dummy, dummy1;
    
    long int itemID;
    Loan singLoan;
    srand(time(NULL));
    long int loanID;
    time_t today_date = time(0);//getting time at time = 0
    time_t loanP;
    time_t due_date;// getting due day
    string loanStat = "Normal";
    
    
    cout<<"Enter patron ID: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    patronID = stoi(dummy);
    
    
    if(singPatron.Search_patron(patronID) != -1){
        
        cout<<"Enter library item ID: ";
        cin>>dummy1;
        
        while(isInt(dummy1)==false){//catch errors if input is different from digits
            cout<<"Invalid input. Try again"<<endl;
            cin>>dummy1;
        }
        
        itemID = stoi(dummy1);
        
        if(singItem.Search_item(itemID) != NULL && singItem.search_item_availability(itemID) == true){// check if item exist and is available
            
            int found = 0;
            bool overdue = false;
            
            loanP = singItem.accessLoanPeriod(itemID);
            due_date = today_date + loanP;//assign due date with item loan period plus today's date in second
            
            for(auto it = LoanList.begin(); it!=LoanList.end(); ++it){//count the number of books out for the patron
                if(it->GetPatron_ID()==patronID){
                    ++found;//add 1 every time patron ID is found in loan list
                }
            }

            
            for(auto it = LoanList.begin(); it!=LoanList.end(); ++it){//Search through the Loanlist vector
                if(it->GetLoan_curr_stat()=="Overdue"&& it->GetPatron_ID()==patronID){//check if patron has an overdue
                    cout<<"This patron has an overdue"<<endl;
                    overdue = true;
                    break;
                }
            }
            
            if (found >= 6){//execite if patron has 6 books out
                cout << "The Patron has reached the loan limit.";
                
            }
            else if( overdue == true) {//execute if patron has an overdue
                cout << "The Patron has an overdue.";
            }
            else{
                
                loanID = (rand()%12000+100000);
                cout<<"The new loan ID is: "<<loanID<<endl;
        
        
                singLoan = Loan(loanID, itemID, patronID, due_date, loanStat,false);//add the loan in the vector:loan collection
                
                LoanList.push_back(singLoan);
                cout<<"The loan was successfully made. the due date for this loan is: "<<endl;
        
                singPatron.Edit_NumBooksOut(patronID, 1);//Update the number of book out
                
                //output the due date
                tm *due = localtime(&due_date);
                cout<< 1900 + due->tm_year<<"/"<<1+ due->tm_mon<<"/"<<due->tm_mday<<" "<<due->tm_hour<<" : "<<due->tm_min<<" : "<<due->tm_sec<<endl;
                
                singItem.Edit_itemstat(itemID); //update bookstatus
                
        }
    }
        else {
            singItem.search_item_availability(itemID);
            cout<<"Item does not exist or is not available for the moment!";//execute if wrong book ID entered
        }
        
    }
    else {
        cout<<"Patron does not exist!";//execute if wrong patron ID entered
        
        }
    storeLoan();// store the change
    
}

void Loans::Check_in_book(Patrons &singPatron, LibraryItems &singItem){
   
    long int ID;
    char choice;
    float fine =0;
    string dummy,dummy1;
    
    cout<<"Enter the ID of the item you want to return: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    
    ID = stoi(dummy);
    
    for(auto it= LoanList.begin(); it !=LoanList.end(); ++it){
        if (it->GetItem_ID()==ID){
            
            singPatron.Edit_NumBooksOut(it->GetPatron_ID(), -1);//Update the number of book out

            
            singItem.Edit_itemstat(ID);//update bookstatus
            
            cout<<"Is there any fine (Y/N)?"<<endl;
            cin>>choice;
            
            if(choice== 'y' ||choice =='Y'){
                cout<<"How much does the patron owe? "<<endl;
                cin>>dummy1;
                
                while(isFloat(dummy)==false){//catch errors if input is different from digits
                    cout<<"Invalid input. Try again"<<endl;
                    cin>>dummy1;
                }
                fine = stof(dummy1);
            }
            
            
            singPatron.Edit_fine(it->GetPatron_ID(), fine);//update patron fine balance
        
            
            LoanList.erase(it);//remove the loan from the collection
            storeLoan();
           
            break;
        }
    }
    
}
void Loans::Overdue_list(Patrons &singPatron){
    
    time_t today = time(0);
    
    sort(LoanList.begin(), LoanList.end(), [](Loan& ls, Loan& rs)
         {
        return ls.Loan::GetPatron_ID() < rs.Loan::GetPatron_ID();
    });//sorting by patrons ID
    
    cout<<"Overdue List: "<<endl<<endl;
    
        for(auto it = LoanList.begin(); it != LoanList.end(); ++it){
           
                if(it->GetLoan_curr_stat()=="Overdue"){//check the status of the loan
                    
                    long int n = (today - it->GetDue_Date_time())/24;//convert time from second to day
                    
                    float fine = n*0.25;//get fine amount based on number of days
                    
                    singPatron.Edit_fine(it->GetPatron_ID(), fine);// add the fine to the patron current fine balance
                    
                   
                    cout<<"Item ID: "<<it->GetItem_ID()<<endl;
                    singPatron.PrintPatron(it->GetPatron_ID());//assign the variable with the patron id at the position where the loan was found overdue
                    cout<<endl;
                }
            
        }
    
}

void Loans::ItemPatron_list(LibraryItems &ItemPatron){
    
    long int patronID;
    string dummy;
    
    cout<<"Enter patron ID: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    
    patronID = stoi(dummy);
    
    cout<<"List of item by a patron:"<<endl<<endl;
    
    sort(LoanList.begin(), LoanList.end(), [](Loan& ls, Loan& rs)
         {
        return ls.Loan::GetPatron_ID() < rs.Loan::GetPatron_ID();
    });//sorting by patrons ID
    
    for(auto it=LoanList.begin(); it!=LoanList.end(); ++it){
        
        if(it->GetPatron_ID()==patronID){
            ItemPatron.PrintItem(it->GetItem_ID());
            cout<<endl<<endl;
            
        }
    }
    

}

void Loans::UpdateLoan_stat(){
    
    time_t today_date = time(0);
    
    for(auto it= LoanList.begin(); it!= LoanList.end(); ++it){
        if(it->GetDue_Date_time() <today_date){//check if the due time in second is smaller than today's time
            
            it->SetLoan_curr_stat("Overdue");//set the loan current status to overdue
        }
        
    }
  
}
void Loans::Re_check_book(){//Assuming only a book can be recheck in this library
    Loan singLoan;

   long int loanID;
    string dummy;
    char choice;
    
    do{
        cout<<"What type of item do you want to recheck?"<<endl;
        cout<<"a - Audio CD"<<endl;
        cout<<"b - Book"<<endl;
        cout<<"d - DVD"<<endl;
        cin>>choice;
        
    }while(choice !='a'&& choice !='b'&& choice!='d' && choice !='A'&& choice !='B'&& choice!='D' );
    
    if(choice == 'a'||choice == 'A'){//execute if patron wants to recheck an audio CD
        cout<<"Sorry we do not offer any recheck for Audio CD"<<endl;
        
    }
    
    else if (choice == 'd'||choice == 'D'){//execute if patron wants to recheck DVD item
        cout<<"Sorry we do not offer any recheck for DVD"<<endl;
    }
    else if (choice == 'b'|| choice =='B'){//execute if patron wants to recheck a book item
            
        cout<<"Enter the ID of the loan you would like to re-check: ";
        cin>>dummy;
        
        while(isInt(dummy)==false){//catch errors if input is different from digits
            cout<<"Invalid input. Try again"<<endl;
            cin>>dummy;
        }
        loanID = stoi(dummy);
        
        for(auto it= LoanList.begin(); it!= LoanList.end(); ++it){
            if(it->GetLoan_ID()== loanID){
                
                if(it->Get_recheck_stat() == false){//fixme only one recheck;
                    
                    long int newDue = it->GetDue_Date_time()+864000;
                    
                    it->SetDue_Date_time(newDue);
                    it->Set_recheck_stat(true);//will update the recheck status to true
                    
                    tm *due = localtime(&newDue);
                    cout<< 1900 + due->tm_year<<"/"<<1+ due->tm_mon<<"/"<<due->tm_mday<<" "<<due->tm_hour<<" : "<<due->tm_min<<" : "<<due->tm_sec<<endl;
                    
                    storeLoan();
                    break;
                }
            }
        }
    }
    
}
void Loans::Edit_Loan(){
    
    long int loanID;
    string updateStat;
    string dummy;
    
    cout<<"Enter the ID of the loan yopu would like to edit: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    loanID = stoi(dummy);
    
    do {
        cout<<"enter the updated status of the loan (Normal/ Overdue): ";
        cin>>updateStat;
        
    } while (updateStat != "Normal" && updateStat == "Overdue");
    
    
    for(auto it= LoanList.begin(); it!= LoanList.end(); ++it){
        if(it->GetLoan_ID()== loanID){
            
            it->SetLoan_curr_stat(updateStat);// Updte the loan status to the one the user choice
            break;
        }
    }
   
    storeLoan();
}

void Loans::ReportLost(Patrons &singpatron, LibraryItems &singItem){
    
    long int loanID;
    string dummy;
    
    cout<<"Enter the loan ID: ";
    cin>>dummy;
    
    while(isInt(dummy)==false){//catch errors if input is different from digits
        cout<<"Invalid input. Try again"<<endl;
        cin>>dummy;
    }
    loanID = stoi(dummy);
    
    
    for(auto it = LoanList.begin(); it!= LoanList.end(); ++it){
        if(it->GetLoan_ID() == loanID){
            
            singItem.Edit_itemstat(it->GetItem_ID());//update book current status
            
            singpatron.Edit_fine(it->GetPatron_ID(), singItem.item_Cost(it->GetItem_ID()));//update the patron fine balance
            
            LoanList.erase(it);//Delete loan from the loan collection
            
            singpatron.Edit_NumBooksOut(it->GetPatron_ID(), -1);//update numberout book out of the patron
            
            break;
        }
        else{
            cout<<"This loan ID does not exist"<<endl;
        }
    }
    
    storeLoan();
}

void Loans::storeLoan(){//write the collection data in an output file
    ofstream fout;
    
    fout.open("loan.dat");
    
    for(auto it = LoanList.begin(); it!= LoanList.end(); ++it){
        
        fout<<it->GetLoan_ID()<<" "<<it->GetItem_ID()<<" "<<it->GetPatron_ID()<<" "<<it->GetDue_Date_time()<<" " <<it->GetLoan_curr_stat()<<" "<<it->Get_recheck_stat()<<endl;
    }
    fout.close();
}

void Loans::loadLoan(){//load the loans collection vector
    ifstream fin;
    ofstream fout;
    long int loanID;
    long int bookID;
    long int patronID;
    time_t due_date;
    string loan_stat;
    bool recheck;
    
    //storeLoan();
    fin.open("loan.dat");
    
    if (fin.fail()){
        storeLoan();
    }
    else{
    while(!fin.eof()){
      
        
        fin>>loanID>>bookID>>patronID>>due_date>>loan_stat>>recheck;
        LoanList.push_back(Loan(loanID, bookID, patronID, due_date, loan_stat,recheck));
     }
    }
    fin.close();
}

void Loans::cleanup(){
    
    LoanList.clear();
}


 
