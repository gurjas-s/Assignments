/* 
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Gurjas Singh
 * Date:   10/12/2023
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
    elements = new int[INITIAL_CAPACITY];
}

Queue::~Queue(){
    delete [] elements;
    elements = nullptr;
    
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
    
    if(elementCount==capacity){ //if elementCount == capacity then resize
        capacity = 2*capacity; //double the capacity

        int* newArray = new int[capacity]; //new array to copy old array (elements) into
        int old_index = frontindex;
        int new_index = 0;
        
        while(new_index!=elementCount){//copy old array into new bigger array
            newArray[new_index] = elements[old_index];
            old_index++;
            new_index++;
            if(old_index==elementCount){
                old_index = 0;
            }
        }
        delete [] elements;
        elements = newArray;
        backindex = elementCount;
        frontindex = 0;
    }
    
    elements[backindex] = newElement;
    elementCount++; 

    backindex = (backindex + 1) % capacity;
    
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
