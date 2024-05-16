/* 
 * BinaryHeap.cpp
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 * Author: Gurjas Singh
 * Last Modification: Nov. 2023
 *
 */  

#include <iostream>
#include "EmptyDataCollectionException.h"

using std::cout;
using std::endl;

template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(){
   elements = new ElementType[capacity];
}

template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const{
   return elementCount;
}

template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement){
   //if out of capacity resize
   if(elementCount==capacity){
      capacity = capacity*2;
      ElementType* resized = new ElementType[capacity];
      if(resized==nullptr){
         return false; //heap memory allocation failed returnr false
      }
      for(int i =0;i<elementCount;i++){
         resized[i] = elements[i];
      }
      delete[] elements;
      elements = resized;
      resized = nullptr;
   }
   
   if(elementCount==0){
      elements[0] = newElement;
      elementCount++;
      return true;
   }
   elements[elementCount] = newElement;
   elementCount++;
   reHeapUp(elementCount-1);
   return true;

}

template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfLastElement){
   unsigned int indexOfMinChild = indexOfLastElement;
   unsigned int indexOfParent;
   
   if(indexOfMinChild==0){//if we reach the root return
      return;
   }
   
   // Find indices of parent depending if left or right child
   if(indexOfMinChild%2==0){
      indexOfParent = (indexOfMinChild-2)/2;
   }

   if(indexOfMinChild%2!=0){
      indexOfParent = (indexOfMinChild-1)/2;
   }
   

   // Base case: if parent > element being inserted
   if (elements[indexOfParent] <= elements[indexOfMinChild]){
      return;
   } 

   //If element to insert is < parent swap them
   if(!(elements[indexOfParent]<=elements[indexOfMinChild])){
      ElementType temp = elements[indexOfParent];
      elements[indexOfParent] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      indexOfMinChild = indexOfParent;
      reHeapUp(indexOfMinChild);
   }

   
}


// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   

   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const{
   if(elementCount==0){
      throw EmptyDataCollectionException("Retrieve() called with empty BinaryHeap");
   }
   return elements[0];
}
