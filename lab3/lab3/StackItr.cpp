//Nathan Nayda
//ntn4jg@virgina.edu
//ntn4jg
//StackItr.cpp
//9/17/2015

#include <iostream>
#include "StackItr.h"
#include "StackNode.h"

using namespace std;

StackItr::StackItr() { //constructor
  current = NULL;
  next = NULL;
}

StackItr::StackItr(StackNode * theNode) { //one parameter constructor
  current = theNode;
  next = theNode -> next;
}

bool StackItr::isPastEnd() const { //returns true if pas end position in the stack
  if (next == NULL) {
    return true;
  }
  else {
return false;
}
}

void StackItr::moveForward() { //moves the iterator to the next value in the stack
  current = next;
  next = next -> next;
}
