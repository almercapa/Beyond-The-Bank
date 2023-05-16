#include <math.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <array>
#include "colormod.h"


using namespace std;
// Declaring function to create account number
string getRand(void);

int main() {
  string first, last, signup, account = " ";
  int menu = 0, choice = 0, thistory = 0, reason = 1, review = 0;
  double balance, bhistory, deposit, withdraw, totald = 0;
  bool acc = false;
  //all variables
  vector<int> taction;
  vector<double> baction;
  vector<double> mnumber;
  //vectors
  account = getRand();
  //random number

  Color::Modifier yellow(Color::FG_YELLOW);//makes the text yellow
  
  cout << yellow << "In order to access our bank, we need your first and last name." << endl;
  cout << "Enter your first name: ";
  cin >> first;
  cout << "Enter your last name: ";
  cin >> last;
  cout << "Before accessing the bank, you must create an account. Sign up (Y/N)? ";
  cin >> signup;
  if (signup == "Y" || signup == "y") {
    cout << "\nWelcome to the Bank of Wakanda, " << first << " " << last << endl << endl;
    balance = 250;
    acc = true;
  }//if you sign up correctly
  else {
    cout << "You have not created an account. Until you do so, you will not be able to access the bank." << endl;
    cout << "1) Signup" << endl;
    cout << "2) Close procedure" << endl;
    while (choice < 1 || choice > 2) {
     cin >> choice;
     if (choice < 1 || choice > 2) {
       cout << "Invalid option." << endl;
     } 
    }
  }//if you sign up incorrectly
  if (choice == 1) {
    cout << "\nWelcome to the Bank of Wakanda, " << first << " " << last << endl << endl;
    balance = 250;
    acc = true;
  }//welcome message

  while (menu != 4 && acc == true) {
    //MAIN MENU
    cout << "\nWhat would you like to do?" << endl;
    cout << "1) Deposit" << endl;
    cout << "2) Withdraw" << endl;
    cout << "3) Print statement" << endl;
    cout << "4) Exit bank" << endl;
    cin >> menu;
    
    if(menu == 1){//if the user chooses to deposit
      cout << "How much would you like to deposit?" << endl;
      cin >> deposit;//user input
      totald = totald + deposit;

      if (deposit >= 5000 || totald >= 5000) {
        if (review == 0) {
          if (reason > 0 && reason < 6) {//they need to give a reason if they try to deposit more than 5k
            cout << "\nWE GET IT YOU'RE RICH, no need to flex your money like that, David Dobrik. Unfortunatly we cannot let you deposit that much but we would like a reason to why you would like to.\n";
            cout << "1) Showing off" << endl;
            cout << "2) Impressing your friends" << endl;
            cout << "3) Buying Carti merch" << endl;
            cout << "4) Birthday money" << endl;
            cout << "5) You have a sugar daddy" << endl;
            cin >> reason;
            if (reason > 0 && reason < 6) {
              cout << "Thank you. Black Panther approves... for now." << endl;
              review = 1;
            }//if the pick one of the reasons
            else {
              cout << "A little suspicious🤨" << endl;
              reason = 1;           
            } //if you refuse to answer
          }
        }
        else if (review == 1) {  
          cout << "You have already sent in a review." << endl;
        }//if you have already done a review
        totald = totald - deposit;
      }
      else if (deposit < 0) {
        cout << "\nIf you're really that broke, go get a job or something, I heard McDonald's is hiring\n";
      }//if they try to deposit a negative amount
      
      else if (deposit > 0 && deposit < 5000 && totald < 5000){
        balance = balance + deposit;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout << "You have successfully deposited $" << setprecision(2) << deposit << "! Your account balance is now $" << balance << "!" << endl;
        thistory++;
        taction.push_back(1);
        mnumber.push_back(deposit);
        baction.push_back(balance);
      }//if they deposit anything between 1 and 5000 dollars
    }

//WITHDRAW
    else if (menu == 2){
      cout << "How much would you like to withdraw?" << endl;
      cin >> withdraw; //user input
      
      if(withdraw > balance){
        cout << "You cannot withdraw more money than you have in your account you silly goose. You trying to scam us or something? You currently have $" << balance << ".";
      }//if they try to withdraw an amount greater than there total balance
      else if(withdraw <= balance){//if they withdraw a valid amount
        balance = balance - withdraw;
        cout << "You have successfully withdrew $" << setprecision(2) << withdraw << "! What are you doing with all that cash?" << endl; 
        thistory++;
        taction.push_back(2);
        mnumber.push_back(withdraw);
        baction.push_back(balance);
      } 
      else if (withdraw <= 0){
        cout << "You can't withdraw $0 or less you silly goose.";
      }
    }
    else if (menu == 3) {
      if (thistory == 0) {
        cout << "You haven't done anything in the bank yet." << endl;
      }//if they go straight to the bank statement without doing anything first
      else {
        cout << endl << "Print Statement for " << first << " " << last << endl;//their name
        cout << "Account Number: " << account << endl;//their account number
        for (int i = 0; i <= taction.size(); i++) {
          if (taction[i] == 1) {
            cout << "Deposit: $" << setprecision(2) << mnumber[i] << "\tBalance: $" << setprecision(2) << baction[i] << endl;
          }//their deposits
          else if (taction[i] == 2) {
            cout << "Withdraw: $" << setprecision(2) << mnumber[i] << "\tBalance: $" << setprecision(2) << baction[i] << endl;//their withdraws
          }
        }
        cout << "You have used the Bank of Wakanda " << thistory << " times.";//home many actions theyve done
        cout << "\nFinal balance: $" << setprecision(2) << balance << endl;//their account balance after everything theyve done
      }
    }
    else if (menu > 4 || menu < 1) {
      cout << "Invalid input dummy" << endl;
    }//if they choose anything other than 1-4
  }
  cout << "\nThank you for visiting the Bank of Wakanda" << endl << endl << endl; //message after user is finished with bank actions
}

// Function for generating account number
string getRand(void) {
  // Placing random flag
  srand((unsigned) time(0));
  // Declaring variables
  string n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, accn;
  // Placing random value between 0-9 into each variable
  int one = (rand() % 9) + 0;
  int two = (rand() % 9) + 0;
  int three = (rand() % 9) + 0;
  int four = (rand() % 9) + 0;
  int five = (rand() % 9) + 0;
  int six = (rand() % 9) + 0;
  int seven = (rand() % 9) + 0;
  int eight = (rand() % 9) + 0;
  int nine = (rand() % 9) + 0;
  int ten = (rand() % 9) + 0;
  int eleven = (rand() % 9) + 0;
  int twelve = (rand() % 9) + 0;
  // Using to_string function to change each number into a string
  n1 = to_string(one);
  n2 = to_string(two);
  n3 = to_string(three);
  n4 = to_string(four);
  n5 = to_string(five);
  n6 = to_string(six);
  n7 = to_string(seven);
  n8 = to_string(eight);
  n9 = to_string(nine);
  n10 = to_string(ten);
  n11 = to_string(eleven);
  n12 = to_string(twelve);
  // Concatenating all strings
  accn = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 + n11 + n12;
  // Returning account number
  return accn;
}
