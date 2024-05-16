#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <sstream>

using std::cin;
using std::cout;
using std::ifstream;




void proccessArrival(int* currentTime, bool* tellerAvailable, Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankline){
    eventPriorityQueue->dequeue();
    if(*tellerAvailable&&bankline->isEmpty()){
        
        int departureTime = *currentTime + arrivalEvent.getLength();;
        Event newDeparture = Event('D',departureTime);
        eventPriorityQueue->enqueue(newDeparture);
        *tellerAvailable = false;
        
    }
    else{
        bankline -> enqueue(arrivalEvent);
    }
}

void processDeparture(int* currentTime, bool* tellerAvailable, Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankline,int* total_time_waiting){
    eventPriorityQueue -> dequeue();
    if(!bankline->isEmpty()){
        Event customer = bankline->peek();
        bankline -> dequeue();
        
        int departureTime = *currentTime + customer.getLength();
        *total_time_waiting += (*currentTime - customer.getTime()); //calculate total waiting time

        Event newDeparture = Event('D',departureTime);
        eventPriorityQueue -> enqueue(newDeparture);
    }
    else{
        *tellerAvailable = true;
    }
}

void simulate(){

    cout << "Simulation Begins\n";
    PriorityQueue<Event> eventPriorityQueue;
    Queue<Event> bankline;
    bool tellerAvailable = true;

    string line;
    string delimiter = " ";

    size_t pos = 0;
    string first;
    string second;
    int time = 0;
    int length = 0;
    int departure = 0;
    bool first_customer = true;

    int total_people = 0;
    int total_time_waiting = 0;
    while(getline(cin,line)){
       pos = line.find(delimiter);
       first = line.substr(0,pos);
       time = stoi(first);
       
       line.erase(0, pos + delimiter.length());
       second = line;
       length = stoi(second);
       Event a = Event('A',time,length);
       
       eventPriorityQueue.enqueue(a);
       total_people++;

    }

    int currentTime = 0;
    int wait = 0;
    while(!eventPriorityQueue.isEmpty()){
        
        

        Event newEvent = eventPriorityQueue.peek();
        currentTime = newEvent.getTime();

        
        if(newEvent.getType()=='A'){
            
            cout << "Processing an arrival event at time:     " << currentTime << "\n";
            proccessArrival(&currentTime, &tellerAvailable, newEvent, &eventPriorityQueue, &bankline);
        }
        else{
            
            cout << "Processing a departure event at time:    " << currentTime << "\n";
            
            processDeparture(&currentTime, &tellerAvailable, newEvent, &eventPriorityQueue, &bankline,&total_time_waiting);
        }

    }
    cout << "Simulation ends\n";
    cout << "\n";
    cout << "Final Statistics:\n";
    cout << "\n";
    cout << "\t" << "Total number of people processed: "<<total_people<<"\n";
    
    int average = total_time_waiting/total_people; 
    int remainder = total_time_waiting%total_people;


    cout << "\t" << "Average amount of time spent waiting: " << average<<"."<<remainder << "\n";



}



int main(){
    simulate();
}