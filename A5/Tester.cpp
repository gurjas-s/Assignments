
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"
#include "Dictionary.h"
#include "Profile.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::setprecision;
using std::string;

//406
int main(int argc, char *argv[]){
 Dictionary * testing = new Dictionary();
  if (testing != nullptr ) {
    unsigned int htCapacity = testing->getCapacity();
    unsigned int initialProbes[htCapacity];      // Records the number of times distint indexing keys 
                                                 // have hashed (probed) into to a cell of the hash table.
												 // We are only recording the initial (first) probe.
												 // We are not recording the probes produced by the 
												 // collision resolution strategy.
												 // The content of this array will show whether the 
												 // hash function evenly distribute the indexing keys across 
												 // the range of hash table (array) indices.
    for ( unsigned int i = 0; i < htCapacity; i++ ) initialProbes[i] = 0;
		  
    string anIndexingKey = "";
    Profile * tempP = nullptr;

    // Each line (element) of dataFile_100_16.txt is read as 
    // an indexing key (a string), i.e., a userName and 
    // is used to instantiate an object of Profile class. 
    // This object is then inserted into "testing",
    // which is an object of the Dictionary class.

    // To execute: ./hftd dataFile_100_16.txt 
    if ( argc == 2 ) {
      ifstream myfile( argv[1] );
      if ( myfile.is_open() ) {
	    while ( getline( myfile, anIndexingKey ) ) {    
		  
      	  tempP = new Profile(anIndexingKey);
		  
      	  try { testing->insert(tempP); }
		  catch ( ElementAlreadyExistsException & anException ) {
			cout << "in hashFunctionTestDriver: Profile userName = " << *tempP << " already exists!" << endl;  
		  }
					
      	  unsigned int hashIndex = testing->hashFunction(anIndexingKey);  	  
          initialProbes[hashIndex]++;
	    } 
	    myfile.close();
      	
	    // Print the content of the Dictionary. 
	    // Print an histogram showing how well (or poorly) the hash indices
	    // are distributed over the whole hashTable.
		// Print the stats.
	    try {
			testing->printDictionary();
            Profile target = Profile("1234567891234567");
            testing->get(target);
		}
		catch( EmptyDataCollectionException & anException) {
			// Do nothing!
			// cout << "***Hash Table is empty!***" << endl;
		}
     
      }
      else 
	    cout << "Unable to open file"; 
    }
    else 
      cout << "Forgot the file name? Try again!" << endl;

    delete testing;
    testing = nullptr;
  }
  
  return 0;
}
