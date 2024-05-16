/*
 * Dictionary.cpp
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: AL
 * Date: Last modified: Nov. 2023
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <string>
#include <cstring>
#include "Dictionary.h"  
#include "Profile.h"
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"

using std::cout;
using std::endl;
using std::__cxx11::stoul;
using std::__cxx11::to_string;





// Constructor
Dictionary::Dictionary() {
  hashTable = new Profile*[CAPACITY];
  
}

// Destructor
// Description: Destruct a Dictionary object, releasing heap-allocated memory.
Dictionary::~Dictionary() {
  // Release all heap memory
  if ( hashTable != nullptr ) { 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      if ( hashTable[i] != nullptr ) {      
        delete hashTable[i]; // Delete object of Profile class on heap
        hashTable[i] = nullptr;
      }
    delete [] hashTable;
    hashTable = nullptr;	
  }
}

// Description: Returns the total element count currently stored in Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getElementCount() const {
   return elementCount;
}

// Description: Returns the CAPACITY (size) of the Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getCapacity() const{
   return CAPACITY;
}

// Hash Function
// Description: Hashes the given indexingKey producing a "hash table index".
// Time Efficiency: Six statements done in sequence the max of each statement is O(1)
//                  therefore O(1) run time.

// Space Efficiency: Hash Function does not require another 
//                 data structure (of size n) to operate therefore O(1)

unsigned int Dictionary::hashFunction( string indexingKey ) {

  // Implement your own hash function here!
  // Used a type of folding to create hash code
  // The length of each piece is baseed on trial and error
  uint64_t indexingKeyInt = stoul(indexingKey);  // O(1)
  uint64_t a = stoul(indexingKey.substr(0,5)); 
  
  uint64_t b = stoul(indexingKey.substr(5,6));

  uint64_t c = stoul(indexingKey.substr(11,4));
  
 
  int sum = (a) + (b) + (c);

  return (sum)%CAPACITY;
}

// Description: Inserts an element into the Dictionary and increments "elementCount".
//              For this Assignment 5, you do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the Dictionary.  
// Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
//            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary. 
void Dictionary::insert( Profile * newElement )  {

  if(elementCount==CAPACITY){//if full throw unable to insert
    throw UnableToInsertException("Hash table is full cannot insert");
  }
  string indexingKey = newElement->getUserName();
  unsigned int index = hashFunction(indexingKey); //convert username to index

  while(hashTable[index]!=nullptr){//linear probe if collision
    if(hashTable[index]->getUserName()==newElement->getUserName()){
      throw ElementAlreadyExistsException("Profile already exists");
    }
    index++;
    if(index==(CAPACITY)){ //loop back to beginning of hashtable
      index = 0;
    }
  }
  hashTable[index] = newElement; //insert element at first empty spot
  elementCount++;
  

  return;
}


// Description: Returns a pointer to the target element if found.
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
Profile * Dictionary::get( Profile & target )  {
  string target_username = target.getUserName();
   // Put your code here!
   if(elementCount==0){
    throw EmptyDataCollectionException("Dictionary is empty");
   }
  unsigned int index = hashFunction(target_username);
  unsigned int orignal_index = index;
  
  while(hashTable[index]!=nullptr){
    if(hashTable[index]->getUserName()==target_username){
      return hashTable[index];
    }
    index++;
    if(index==CAPACITY){
      index = 0;
    }
    if(index==orignal_index){
      throw ElementDoesNotExistException("Profile does not exist");
    }
  }
  throw ElementDoesNotExistException("Profile does not exist"); 
  
}
   
// Description: Prints all elements stored in the Dictionary (unsorted).
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
void Dictionary::printDictionary()  const {
  if ( elementCount == 0 ) 
     throw EmptyDataCollectionException("In printDictionary(): hashTable is empty.");

  cout << endl << "Printing the Dictionary with " << this->elementCount << " elements: " << endl;
  for (unsigned int index = 0; index < CAPACITY; index++) {
    if ( hashTable[index] != nullptr ) 
		cout << "HashTable[" << index << "] = " << *(hashTable[index]) << endl; 
  }   
  return;
}
