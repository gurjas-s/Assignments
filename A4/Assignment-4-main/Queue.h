/******* Start of Queue Public Interface *******/
		
   // Class Invariant:  FIFO or LILO order

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)


#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue{
    class Node {
        public: 
            T data;
            Node *next;
    };
    private:
        Node* front;
        Node* back;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        bool enqueue(T newElement);
        void dequeue();
        T peek();

};

#include "Queue.cpp"
#endif




 
/******* End of Queue Public Interface *******/