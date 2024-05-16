#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Dictionary.h"


using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair& anElement) {
  cout << anElement;
} 

int main(int argc, char*argv[]){


Dictionary * dict = new Dictionary();
      
string aLine = "";
string aWord = "";
string englishW = "";
string translationW = "";
string filename = "myDataFile.txt";
string delimiter = ":";
size_t pos = 0;
WordPair translated;


ifstream myfile (filename);
if (myfile.is_open()) {
    cout << "Reading from a file:" << endl; 
    while ( getline (myfile,aLine) )
    {
    pos = aLine.find(delimiter);
    englishW = aLine.substr(0, pos);
    aLine.erase(0, pos + delimiter.length());
    translationW = aLine;
    WordPair aWordPair(englishW, translationW);
    dict -> put(aWordPair);
    
    // insert aWordPair into "testing" using a try/catch block
    }
    myfile.close();
    if(argc>1){
        if(strcmp(argv[1],"display")==0){
            dict->displayContent(display);
        }
    }// If user entered "display" at the command line ...
    }
    
    
    cout << "Enter an english word: ";
    while(getline(cin, englishW)){
        try{
            WordPair to_get = WordPair(englishW);
            WordPair output = dict->get(to_get);
            string translation = output.getTranslation();
            cout << translation << "\n";
            cout << "Enter an english word: ";
        }
        catch(ElementDoesNotExistException& e){
            cout << "***Not Found!***\n";
            cout << "Enter an english word: ";
        }
    }

    delete dict;
    dict=nullptr;
}