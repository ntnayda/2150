//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//StackNode.h
//9/17/2015

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class StackNode {

 public:
  StackNode(); // constructor

 private:
  int value;
  StackNode * next;
  friend class Stack;
  friend class StackItr;

};

#endif
