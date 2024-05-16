/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Gurjas Singh
 * Date: 10/10/2023
 */
 
class Stack {


    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        
        private:
            StackNode* head;
            StackNode* top;           
        


/* Put your code here! */       
        

    public:
    
        Stack();

        Stack(const Stack& rhs);

        ~Stack();

        bool push(const int& to_push);

        int peek();

        bool pop();

        bool isEmpty();

        void print();


/* Put your code here! */   


};
