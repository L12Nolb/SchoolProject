//
//  main.cpp
//  Suzanne Nolba
//Sources:
//Class codes and materials
//cplusplus.com
//
//  Created by LOIS on 4/9/21.
//

#include <iostream>
#include<string>
#include "LibraryItem.h"
#include "LibraryItems.h"
#include "Book.h"
#include "AudioCD.h"
#include "DVD.h"
#include "Patron.h"
#include "Loan.h"
#include "Patrons.h"
#include "Loans.h"
using namespace std;



LibraryItems lib;
Patrons Pats;
Loans loans;
bool isInt(string gag);
bool isFloat(string a);

bool isInt(string gag){
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
bool isFloat(string a){
  bool num = false;
    bool point_encounter = false;
  
  for(int i = 0; i < a.length(); ++i){
    if(isdigit(a.at(i))){//check if every entry of the string is a digit
      num = true;
    }else if (a.at(i) == '.' && point_encounter == false ){
        point_encounter = true;
        num = true;
    }else{
        num = false;
        break;    }
  }
  
  return num;
}

void PrintLoanMenu(){
    int choice =-1;
    string dummy;

    cout<<"********************************************************************"<<endl;
    cout<<"* You have entered the loan menu                                  *"<<endl;
    cout<<"**********************************************************************"<<endl;
    while(choice !=0){//will excecute until 0 is entered

        cout<<"LOAN MENU"<<endl<<endl;
        cout<<"0 - Quit"<<endl;
        cout<<"1 - Check Out a book"<<endl;
        cout<<"2 - Check In a book"<<endl;
        cout<<"3 - List all overdue"<<endl;
        cout<<"4 - List all books for a particular patron"<<endl;
        cout<<"5 - Update loan status based on system clock"<<endl;
        cout<<"6 - Re-check a book"<<endl;
        cout<<"7 - Edit a loan"<<endl;
        cout<<"8 - Report lost"<<endl;
        cout<<endl<<endl;

        
        do{// will execute if a value different from the menu option is entered
            try {
                cout<<"Choose an option: ";
                cin>>dummy;
                choice = stoi(dummy);
            } catch (invalid_argument &e) {
                //nothing done just caught it to go throught the loop
            }
            
        }
        while(choice !=0 &&choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5 &&choice!=6 && choice !=7 && isInt(dummy) == false);

        cin.ignore();

        if(choice ==0){
            break;
        }
        else if(choice ==1){
            cout<<"CHECK OUT A LIBRARY ITEM"<<endl<<endl;
            
            loans.Check_out_book(Pats, lib);

        }
        else if (choice == 2 ){
           
            cout<<"CHECK IN A LIBRARY ITEM"<<endl<<endl;

            loans.Check_in_book(Pats, lib);
        }
        
        else if (choice == 3){
            cout<<"LIST OF ALL OVERDUE"<<endl<<endl;
            loans.Overdue_list(Pats);
        }
        else if (choice == 4){
          

            cout<<"LIST OF ALL BOOKS FOR A PARTICULAR PATRON"<<endl<<endl;
            loans.ItemPatron_list(lib);

        }
        else if (choice == 5){
            cout<<"UPDATE LOAN BASED ON SYSTEM CLOCK"<<endl<<endl;

            loans.UpdateLoan_stat();
        }
        else if (choice ==6){
            cout<<"RE-CHECK AN ITEM"<<endl<<endl;

            loans.Re_check_book();
        }
        else if (choice == 7){
            cout<<"EDIT LOAN STATUS"<<endl<<endl;
            loans.Edit_Loan();
        }
        else if(choice == 8 ){
            cout<<"REPORT LOST"<<endl<<endl;
            loans.ReportLost(Pats, lib);
        }
        else {
            cout<<"Invalid choice. Please select an option from 0 to 8."<<endl;

        }
        cout<<endl;
    }
}
void PrintPatronMenu(){
    int choice =-1;
    string dummy;
    
    cout<<"********************************************************************"<<endl;
    cout<<"* You have entered the patron menu                                  *"<<endl;
    cout<<"**********************************************************************"<<endl;
    while(choice !=0){

        cout<<"PATRON MENU"<<endl<<endl;
        cout<<"0 - Quit"<<endl;
        cout<<"1 - Add a new Patron"<<endl;
        cout<<"2 - Delete a patron"<<endl;
        cout<<"3 - Edit patron's name"<<endl;
        cout<<"4 - Print a patron information"<<endl;
        cout<<"5 - Print patrons' information"<<endl;
        cout<<"6 - Search a patron"<<endl;
        cout<<"7 - Pay fine"<<endl;
        cout<<endl<<endl;

        do{
            try {
                cout<<"Choose an option: ";
                cin>>dummy;
                choice = stoi(dummy);
            } catch (invalid_argument &e) {
                //nothing done just caught it to go throught the loop
            }
            
        }
        while(choice !=0 &&choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5 &&choice!=6 && choice !=7 && isInt(dummy) == false);

        cin.ignore();

        if(choice ==0){
            break;
        }
        else if(choice ==1){
            cout<<"ADD A NEW PATRON"<<endl<<endl;
            Pats.Add_patron();

        }
        else if (choice == 2 ){
            long int id;
            string dummy;
            
            cout<<"DELETE A PATRON"<<endl<<endl;
            cout<<"Enter the ID number of the patron you want to delete: ";
            cin>>dummy;
            while(isInt(dummy)==false){//catch errors if input is different from digits
                cout<<"Invalid input. Try again"<<endl;
                cin>>dummy;
            }
            id = stoi(dummy);
            cin>>id;

            Pats.Delete_patron(id);
        }
        else if (choice == 3){
            cout<<"EDIT PATRON'S NAME"<<endl<<endl;
            Pats.Edit_patronName();
        }
        else if (choice == 4){
            long int id;

            cout<<"PRINT A PATRON INFORMATION"<<endl<<endl;
            cout<<"Enter the iD number of the patron: ";
            cin>>id;

            Pats.PrintPatron(id);

        }
        else if (choice == 5){
            cout<<"PRINT ALL PATRONS INFORMATION"<<endl<<endl;

            Pats.PrintPatrons();
        }
        else if (choice ==6){
            long int id;

            cout<<"SEARCH A PATRON"<<endl<<endl;
            cout<<"Enter the iD number of the patron: ";
            cin>>id;

            cout << "index: "<<Pats.Search_patron(id)<<endl;
        }
        else if (choice == 7){
            cout<<"PAY FINE"<<endl<<endl;
            Pats.PayFine();
        }
        else {
            cout<<"Invalid choice. Please select an option from 0 to 7."<<endl;

        }
        cout<<endl;
    }
}

void PrintItemMenu(){
    int choice =-1;
    string dummy;

    cout<<"**********************************************************************"<<endl;
    cout<<"* You have entered the library catalog menu                                *"<<endl;
    cout<<"*******************************************************************"<<endl<<endl;

    while(choice !=0){

        cout<<endl<<endl<<"LIBRARY CATALOG MENU"<<endl<<endl;
        cout<<"0 - Quit"<<endl;
        cout<<"1 - Add a new item"<<endl;
        cout<<"2 - Delete an item"<<endl;
        cout<<"3 - Edit an item cost"<<endl;
        cout<<"4 - Print an item"<<endl;
        cout<<"5 - Print all item"<<endl;
        cout<<"6 - Search a item"<<endl;
        cout<<endl<<endl;

        do{// will execute if a value different from the menu option is entered
            try {
                cout<<"Choose an option: ";
                cin>>dummy;
                choice = stoi(dummy);
            } catch (invalid_argument &e) {
                //nothing done just caught it to go throught the loop
            }
            
        }
        while(choice !=0 &&choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5 &&choice!=6 && choice !=7 && isInt(dummy) == false);

        cin.ignore();

        if(choice==0){
            break;
        }
        else if(choice == 1){
            cout<<"ADD AN ITEM"<<endl<<endl;
            lib.Add_item();
        }
        else if(choice ==2){
           long int itemID;
            cout<<"DELETE AN ITEM"<<endl<<endl;
            cout<<"Enter the library ID of the item you want to delete: ";
            cin>>itemID;

            lib.Delete_item(itemID);
            
        }
        else if(choice ==3){
            cout<<"EDIT AN ITEM COST"<<endl<<endl;
            lib.Edit_item();
        }
        else if (choice == 4){
            long int bookID;

            cout<<"PRINT AN ITEM"<<endl<<endl;
            cout<<"Enter the library ID of the item you want to print: ";
            cin>>bookID;
            lib.PrintItem(bookID);

        }
        else if (choice ==5){
            cout<<"PRINT ALL ITEMS"<<endl<<endl;
            lib.PrintItems();
        }
        
        else if(choice ==6){
           long  int bookID;

            cout<<"SEARCH AN ITEM"<<endl<<endl;
            cout<<"Enter the library ID of the item you want to search: ";
            cin>>bookID;

            cout << "id: " <<lib.Search_item(bookID);
        
        }
        else{
            cout<<"Invalid choice. Please select option from 0 to 6"<<endl<<endl;
        }

    }
}
int main(int argc, const char * argv[]) {

   Pats.loadPatron();//load the patron collection data
    loans.loadLoan();//load the loans collection data

    int choice=-1;
    
    cout<<"WELCOME TO THE LIBRARY MANAGEMENT SYSTEM"<<endl<<endl<<endl;
    
    while(choice !=0){
        cout<<"You have entered the library main menu"<<endl<<endl;
        
        cout<<"MAIN MENU"<<endl<<endl;
        cout<<"1 - Patron Menu"<<endl;
        cout<<"2 - Library Item Menu"<<endl;
        cout<<"3 - Loan Menu"<<endl;
        cout<<"0 - Exit"<<endl;
        cout<<endl;
        
        do{
            cout<<"Enter an option: ";
            cin>>choice;
        }while(choice !=0 && choice != 1 && choice !=2 && choice !=3);
         
        if (choice == 0){
            cout<<"You have exit the library management system"<<endl;
            break;
        }
        else if (choice ==1){
            PrintPatronMenu();
            
        }
        else if (choice == 2){
            PrintItemMenu();        }
    
        else if (choice ==3) {
            PrintLoanMenu();
            
        }
        else{
            cout<<"Invalid option. Choose an option from 0 to 3"<<endl;
        }
    
    }
    
    Pats.storePatron();
    loans.storeLoan();
    
    return 0;
}

