/******* Start of Binary Heap  Public Interface *******/	

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

template <class ElementType>
class BinaryHeap{
   private:
      static unsigned int const INITIAL_CAPACITY = 20;
      
      int elementCount = 0;
      int capacity = INITIAL_CAPACITY;
      ElementType* elements;
      // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   public:

      BinaryHeap();

      unsigned int getElementCount() const;

      // Description: Inserts newElement into the Binary Heap. 
      //              It returns true if successful, otherwise false.      
      // Time Efficiency: O(log2 n)
      bool insert(ElementType & newElement);

      void reHeapUp(unsigned int indexOfMinChild);
         
      // Description: Removes (but does not return) the necessary element.
      // Precondition: This Binary Heap is not empty.
      // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
      // Time Efficiency: O(log2 n)
      void remove();

      void reHeapDown(unsigned int indexOfMinChild);

      // Description: Retrieves (but does not remove) the necessary element.
      // Precondition: This Binary Heap is not empty.
      // Postcondition: This Binary Heap is unchanged.
      // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
      // Time Efficiency: O(1) 
      ElementType & retrieve() const;

};

#include "BinaryHeap.cpp"

#endif

 
/******* End of Binary Heap Public Interface *******/