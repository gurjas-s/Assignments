/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;


int calculate(Token first, Token second, Token op){/*Given three tokens (two numbers and an operator),
                                                    calculates the results*/
    if(op.tt==pltok){
        return first.val + second.val;
    }
    else if(op.tt==mitok){
        return second.val - first.val;
    }
    else if(op.tt==asttok){
        return first.val * second.val;    
    }
    else if(op.tt==slashtok){
        return second.val/first.val;
    }
}

void operation(Stack<Token>* numstack, Stack<Token>* opstack){ /*Function that pops first two numbers in numstack and 
                                                                first operator in opstack and calucaltes the result*/
    Token first;
    Token second;
    Token op;
    Token result;
    int value; //integer that stores the number to add into numstack
    
    first = numstack -> pop();
    second = numstack -> pop();
    op = opstack -> pop();
    
    value = calculate(first,second,op);
    result.val = value; 
    
    numstack -> push(result); //push result into numstack    
   
}

int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    
    t = S.getnext();
    Token x;
    bool empty; //keep track if opstack is empty

    
    while(t.tt!=eof || !opstack.isEmpty()){
        empty = opstack.isEmpty();
        if(t.tt == integer){ //if integer
            numstack.push(t);
            t = S.getnext();
        }
        else if(t.tt == lptok){ //if left bracket
            opstack.push(t);
            t = S.getnext();
        }
        else if(t.tt==rptok){
            x = opstack.peek();
            
            if(x.tt==lptok){
                opstack.pop();
                t = S.getnext();
            }
            else{
                operation(&numstack, &opstack);
            }
        }
        else if(t.tt==mitok||t.tt==pltok||t.tt==eof){

            if(empty==0){
                x = opstack.peek();
            }
            if(empty==0 && (x.tt==pltok||x.tt==mitok||x.tt==asttok||x.tt==slashtok)){ //if empty and either +,-,*,/
                operation(&numstack,&opstack);
            }
            else{
                opstack.push(t);
                t = S.getnext();
                
            }
                    
        }
        else if(t.tt==asttok||t.tt==slashtok){
            if(empty==0){
                x = opstack.peek();
            }
            if(empty==0 && (x.tt==asttok||x.tt==slashtok)){// if empty and either *,/
                operation(&numstack,&opstack);
            }
            else{
                opstack.push(t);
                t = S.getnext();
            }
            
        }

    }

    cout << numstack.peek().val; // print final answer




    



    // Pretty printer coding demo.  Please remove before coding

    cout << endl;
    // End pretty printer coding demo.

    return 0;
}

