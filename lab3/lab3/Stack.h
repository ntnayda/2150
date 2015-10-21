//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//Stack.h
//9/17/2015

#ifndef STACK_H
#define STACK_H

#include "StackNode.h"
#include "StackItr.h"

using namespace std;
class StackItr;

class Stack {

 public:
  Stack(); //constructor
 void  push(int x); //adds a number to the top of the stack
 void  pop(); //removes the number at the top of the stack
 int  top() const; //returns the number at the top of the stack
 void  empty(); //clears the stack
  

 private:
  StackNode * head;
friend class StackItr;
};

#endif
