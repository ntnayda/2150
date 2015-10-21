//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//StackItr.h
//9/17/2015

#ifndef STACKITR_H
#define STACKITR_H

#include "StackNode.h"
#include "Stack.h"

using namespace std;

class StackItr {

 public:
  StackItr(); //constructor
  StackItr(StackNode * theNode); // one parameter constructor
  void moveForward(); //moves the iterator forward
  bool isPastEnd() const; //returns true if past end position of the stack

  private:
    StackNode * current, * next;
    friend class Stack;
  };

#endif
