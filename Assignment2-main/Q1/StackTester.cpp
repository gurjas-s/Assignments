#include <iostream> 
#include "Stack.h"

using std::cout;
using std::endl;

int main(){
    Stack* stk = new Stack();
    cout << "initalized\n";
    int i = 1;
    stk -> push(i);
    stk -> push(2);
    stk -> push(43);
    stk -> print();
    int x = stk -> peek();
    cout << x << "\n";
    stk->pop();
    stk->pop();
    bool test = stk->isEmpty();
    stk->pop();
    x = stk -> peek();
    
    cout << test << "\n";
}