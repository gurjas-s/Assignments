/*
 * BSTTestDriver.cpp
 * 
 * Description: Drives the testing of the BST ADT class. 
 *
 * Author: AL
 * Last Modification Date: Oct. 2023
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair& anElement) {
  cout << anElement;
} 

// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {

  BST * testing = new BST();
      
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "dataFile2.txt";
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
        try{
         testing -> insert(aWordPair);
        }

        catch(ElementAlreadyExistsException& e){
         cout <<"caught error: " << e.what() << "\n";
        }
       
        // insert aWordPair into "testing" using a try/catch block
     }
     myfile.close();

     // If user entered "display" at the command line ...

   }
   //testing->traverseInOrder(display);
   WordPair get = WordPair("take","chen frm");
   //WordPair print = testing->retrieve(get);
   //cout << "got: " << print << "\n";
   BST * deep_copy = new BST(*testing);
   WordPair add = WordPair("gurjas","singh");
   
   deep_copy->insert(add);
   deep_copy->traverseInOrder(display);
   cout << "\n";
   testing->traverseInOrder(display);
   delete testing;
   testing = nullptr;
}