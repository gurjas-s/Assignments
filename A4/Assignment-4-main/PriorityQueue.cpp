
#include "BinaryHeap.h"

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    PQ = new BinaryHeap<ElementType>();
}

template <class ElementType>
bool PriorityQueue<ElementType>:: isEmpty() const{
    return PQ->getElementCount()==0;
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement){
    bool val = PQ -> insert(newElement);
    return val;
}

template <class ElementType>
void PriorityQueue<ElementType>::dequeue(){
    PQ->remove();
}

template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const{
    if(PQ->getElementCount()==0){
        throw EmptyDataCollectionException("Trying to peek and empty priority queue");
    }
    return PQ -> retrieve();
}


