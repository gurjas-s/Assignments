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
  cout << anElement << "\n";
} 

int main(){
    BST* tree = new BST();
    cout << "Tree\n";
    
    for(int i = 0;i<3;i++){
        string english ="";
        string translated ="";
        cout << "enter english";
        cin >> english;
        cout << "enter translated";
        cin >> translated;
        WordPair newPair = WordPair(english,translated);
        tree->insert(newPair);
    }
    tree -> traverseInOrder(display);
    
}