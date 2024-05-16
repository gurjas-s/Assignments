#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "Event.h"
#include "BinaryHeap.h"
#include "PriorityQueue.h"

using std::cin;
using std::cout;

int main(){
    Event one = Event('A',25);
    PriorityQueue<Event> pq;
    for(int i = 0; i<=20;i++){
        Event E = Event('A',i);
        one = E;
        pq.enqueue(one);
        pq.peek().print();
        cout << "\n";

    }
    for(int i =0;i<=20;i++){
        pq.peek().print();
        cout << "\n";
        pq.dequeue();
    }
    
}