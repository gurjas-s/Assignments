
#include "EmptyDataCollectionException.h"

template <class T> 
Queue<T>::Queue() {
    front = nullptr;
}

template <class T> 
Queue<T>::~Queue() {

}

template <class T> 
bool Queue<T>::isEmpty() {
    return (front == nullptr);
}


template <class T> 
bool Queue<T>::enqueue(T newElement) {
    Node* newNode = new Node();

    if(newNode == nullptr){
        return false;
    }
    newNode->data = newElement;
    newNode -> next = nullptr;

    if(isEmpty()){
       front = newNode;
       back=newNode;
       return true;
    }
    back->next = newNode;
    back = newNode;
    
    return true;
}

template <class T>
void Queue<T>::dequeue(){
    if(isEmpty()){
        throw EmptyDataCollectionException("Queue is already empty");
    }
    Node* cur = front;
    front = front -> next;
    delete cur;
    cur = nullptr;
    

}

template <class T> 
T Queue<T>::peek() {
    if(isEmpty()){
        throw EmptyDataCollectionException("Queue is empty cannot peek");
    }
    else{
        return front->data;
    }
    
}







