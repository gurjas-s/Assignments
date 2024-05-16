
#include <iostream>
#include <cctype>
#include "Stack.h" 

using std::cout; //delete after testing

//Description: Constructer
Stack::Stack(){
    head = nullptr;
    top = nullptr;
    
}

Stack::Stack(const Stack& rhs){
    head = nullptr;
    top = nullptr;
    StackNode* rhsTemp = rhs.head;
    
    
    while(rhsTemp!=nullptr){
        StackNode* newNode = new StackNode; 
        newNode -> data = rhsTemp -> data;
        newNode -> next = nullptr;
        
        if(head==nullptr){
            head = newNode;
            top = newNode;
        }
        else{
            top -> next = newNode;
            top = newNode;
        }
        rhsTemp = rhsTemp -> next;
    }
    
  

}

//Description: Destructor
Stack::~Stack(){
    StackNode* temp = head;
    while(temp!=nullptr){
        StackNode* next = temp -> next;
        delete temp;
        temp = next;
    }
    head = nullptr;
    top = nullptr;
}

//Description: Pushes a new element (to_push) into the stack
bool Stack::push(const int& to_push){
    StackNode* newNode = new StackNode; //new node to push into stack
    
    newNode -> data = to_push;

    if(isEmpty()){ //if this is the first new node to add
        head = newNode;
        top = newNode;
        newNode -> next = nullptr;
        return true;
    }

    top -> next = newNode;
    top = newNode;
    newNode -> next = nullptr;

    return true;
    
}

//Description: Returns top of stack
int Stack::peek(){
    return top -> data;
    
}

//Description: Pops the top element of stack
bool Stack::pop(){
    if(isEmpty()){
        return false;
    }
    StackNode* temp = head;
    
    if(head==top){
        head = nullptr;
        top = nullptr;
        delete temp;
        return true;
    }

    while(temp->next->next!=nullptr){ //iterate to second to last node
        temp = temp -> next;
    }

    top = temp; //set top to temp (the previous second to last node)
    temp = temp -> next; //set temp to final node i.e node to pop
    delete temp;
    top -> next = nullptr;
    
    return true;
}

//Description: Returns true if stack is empty
bool Stack::isEmpty(){
    return head==nullptr;
}


//Description: Used for testing purposes to print out the linked list
void Stack::print(){
    StackNode* temp = new StackNode;
    temp = head;
    while(temp!=nullptr){
        cout  << temp -> data << "\n";
        temp = temp -> next;
    }
}