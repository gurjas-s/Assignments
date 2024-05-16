/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: AL
 * Modified on: Sept. 14, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers) {
   string username;
   string first_name;
   string last_name;
   string name;
   string email;
   string birthday;
   string month;
   string day;
   string year;
   
   cout << "enter your username (must start with a letter)\n";
   cin >> username;
   cout << "enter your first and last name\n";
   cin >> first_name >> last_name;
   cout << "enter your email\n";
   cin >> email;
   cout << "enter your birthday in the order month, day, and year. (do not abbreviate i.e Febuary 21 2003)\n";
   cin >> month >> day >> year;
   month[0] = toupper(month[0]);;
   name = first_name + " " + last_name; //combine first and last name
   birthday = month + " " + day + " " + year; //combine month,day,year to get full birthday
   Profile to_add = Profile(username,name,email,birthday); //create their profile
   //cout << to_add;
   theMembers.insert(to_add); //insert profile
   /* Put your code here */

}

void leave(MyADT & theMembers) {
   string username;
   cout << "Please enter username of profile to modify\n";
   cin >> username;
   Profile to_remove = Profile(username);
   theMembers.remove(to_remove);
   /* Put your code here */

}

void search(MyADT & theMembers) {
   string username;
   Profile* location;
   cout << "Please enter username of profile to search for\n";
   cin >> username;
   
   Profile to_search  = Profile(username);
   location = theMembers.search(to_search);
   
   if(location==nullptr){ //if the profile was not found
      cout << "Profile not found\n";
   }
   else{
      cout << "Found profile: " << *location;
   }
   /* Put your code here */

}

void modify(MyADT & theMembers) {
   string username;
   string name;
   string first_name;
   string last_name;
   string email;
   string month;
   string day;
   string year;
   string birthday;
   Profile* location;
   
   cout << "Please enter username of profile to modify\n";
   cin >> username;
   
   Profile to_search = Profile(username);
   location = theMembers.search(to_search);
   
   if(location==nullptr){//if profile to modify was not found
      cout << "This profile does not exist sorry\n";;
      return;
   }
   
   char check;
   
   cout << "Type 1 to change profile name, 0 to skip\n";
   cin >> check;
   
   if(check=='1'){
      cout << "Enter new name\n";
      cin >> first_name >> last_name;
      name = first_name + " " + last_name;
      location -> setName(name); //modify name
   }

   cout << "Type 1 to change email, 0 to skip\n";
   cin >> check;
   if(check=='1'){
      cout << "Enter new email\n";
      cin >> email;
      location -> setEmail(email); //modify email
   }

   cout << "Type 1 to change birthday, 0 to skip\n";
   cin >> check;
   if(check=='1'){
      cout << "Enter new birthday\n";
      cin >> month >> day >> year;
      month[0] = toupper(month[0]);
      birthday = month +" " + day + " " + year;
      location -> setBirthday(birthday); //modify birthday
   }
   
   cout << "The profile has been modified";


   
   /* Put your code here */

}

void print(MyADT & theMembers) {

   theMembers.print();
}

   /* Put your code here */



int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}