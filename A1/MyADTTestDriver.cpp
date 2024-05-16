#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"
using std::cout;
using std::cin;


int main(){
    MyADT members = MyADT();
    Profile list[10];
    Profile* location;
    string username;
    string name;
    string email;
    string birthday;
    bool finished = false;
    Profile one = Profile("marieLower");
    Profile two = Profile("mrvropdgsn");
    Profile four = Profile("mrvrsn");
    Profile five = Profile("mmm");
    Profile six = Profile("mdfas");
    Profile seven = Profile("mfda");
    Profile three = Profile("zebra");
    

    members.insert(one);
    members.insert(two);
    members.insert(four);
    members.insert(five);
    members.insert(six);
    MyADT copy(members);
    copy.insert(three);
    members.print();
    //copy.print();
    location = members.search(one);
    location -> setName("singh");
    //out << *location << "\n";
    
    return 0;
}