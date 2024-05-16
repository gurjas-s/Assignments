
#include "Dictionary.h"
#include <iostream>



using std::cout;
using std::endl;

    Dictionary::Dictionary(){
        keyValuePairs = new BST();
    }

    Dictionary::~Dictionary(){
    }

    void Dictionary::put(WordPair & newElement){
        keyValuePairs -> insert(newElement);
        
    }

    WordPair& Dictionary::get(WordPair & targetElement) const{
        return keyValuePairs->retrieve(targetElement);
    }

    void Dictionary::displayContent(void visit(WordPair &)) const{
        keyValuePairs->traverseInOrder(visit);
    }

