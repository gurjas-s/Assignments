/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL
 * Last modified on: Sept. 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;


    
// Default constructor.
MyADT::MyADT() {
   for(int i=0;i<MAX_ALPHA;i++){ //create MAX_ELEMENT size profile arrays at every position of elements
      elements[i] = new Profile[MAX_ELEMENTS];
   }
   for(int i=0;i<MAX_ALPHA;i++){
      elementCount[i] = 0; //set the count to 0
   }
   /* Put your code here */

}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   for(int i=0;i<MAX_ALPHA;i++){ //copy elementCount from rhs
      elementCount[i] = rhs.elementCount[i];
   }

   for(int i=0;i<MAX_ALPHA;i++){ //create MAX_ELEMENT size profile arrays at every position of elements
      elements[i] = new Profile[MAX_ELEMENTS];
   }

   for(int i=0;i<MAX_ALPHA;i++){
      for(int x=0;x<rhs.elementCount[i];x++){
         elements[i][x] = rhs.elements[i][x]; //copy elements from rhs to the new MyADT
      }
   }
   /* Put your code here */

}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   for(int i=0; i<MAX_ALPHA;i++){
      delete[]elements[i]; //delete profile arrays in elements
      elements[i] = nullptr; 
   }
   
   /* Put your code here */

} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
   int sum = 0;
   for(int i =0;i<MAX_ALPHA;i++){
      sum = sum + elementCount[i];
   }
   return sum;
   /* Put your code here */

}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {
   Profile to_add = newElement; 
   char first_letter_of_username = newElement.getFirstLetter(); 
   unsigned int index = int(first_letter_of_username) - CHAR_TO_INT; //get the index (explained in myADT.h)
   unsigned int num_elements = elementCount[index]; //number of profiles in the elements[index] 
   
   if(num_elements==MAX_ELEMENTS){ //check if there is room to add profile
      return false;
   }
   
   if (num_elements==0){
      elements[index][0] =newElement;
      elementCount[index] = elementCount[index] + 1;
      return true;
   }
   
   Profile current_profile = Profile();
   unsigned int position_to_insert;
   
   for(int i=num_elements-1;i>=0;i--){
      current_profile = elements[index][i];
      
      if(current_profile==to_add){//check if profile to add is already in the list 
         return false;
      }
      
      else if(to_add<current_profile){
         elements[index][i+1] = elements[index][i]; //shift current profile to the right
         if(i==0){
            position_to_insert = 0;
         }
      }
      
      else if(to_add>current_profile){
         position_to_insert = i + 1;
         break;
      }
   }

   elements[index][position_to_insert] = newElement; //insert the new profile
   elementCount[index] = elementCount[index] + 1; //incremeent elementCount
   return true;
 
   /* Put your code here */

}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
   char first_letter_of_username = target.getFirstLetter();
   unsigned int index = int(first_letter_of_username) - CHAR_TO_INT;
   unsigned int num_elements = elementCount[index];
   Profile current = Profile();
   Profile * ptr; //ptr containing address of target profile we are finding
   Profile to_find = target;

   for(int i=0;i<num_elements;i++){
      current = elements[index][i]; //current profile in iteration
      if(current==to_find){ //check if current profile equals the profile to find
         ptr = &elements[index][i];
         return ptr;
      }      
   }
   return nullptr; //return nullptr if profile not found
   /* Put your code here */

}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {
   Profile to_find = toBeRemoved;
   char first_letter_of_username = toBeRemoved.getFirstLetter();
   unsigned int index = int(first_letter_of_username) - CHAR_TO_INT;
   unsigned int num_elements = elementCount[index];
   Profile current = Profile();
   bool check = false;

   for(int i=0;i<num_elements;i++){
      current = elements[index][i];
      if(current==to_find){
         check = true;
      }
      else if(check==true){
         elements[index][i-1] = elements[index][i]; //once profile has been found shift elements to overwrite
      }
   }

   if(check==false){ //if the profile to be removed is not found
      return false;
   }
   elementCount[index] = elementCount[index]-1; //deincrement elementCount
   return true;
   /* Put your code here */

}  // end remove


// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {
   for(int i=0;i<MAX_ALPHA;i++){
      elementCount[i] = 0;
   }
   /* Put your code here */

}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***
void MyADT::print() {
   for(int i = 0; i < MAX_ALPHA;i++){
      for(int x =0;x<elementCount[i];x++){
         cout << elements[i][x] << "\n";
      }
   }

   /* Put your code here */

} // end of print 

//  End of implementation file
