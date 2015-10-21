//Nathan Nayda
//ntn4jg@viriginia.edu
//ntn4jg
//Stack.cpp
//9/17/2015

#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack() {
  head = new StackNode;
}

void Stack::push(int x) {
  StackItr iter(head);
  if (iter.current->next != NULL) {
    StackNode * newNode = new StackNode;
    newNode -> value = x;
    newNode -> next = iter.current -> next;
    head -> next = newNode;
  }
 
}

int Stack::top() const {
  return head -> next -> value;
}

void Stack::pop() {
  StackItr iter(head);
  if (iter.current -> next != NULL) {
    iter.moveForward();
    head -> next = iter.current -> next;
    delete iter.current;
  }
}

void Stack::empty() {
  StackItr iter(head);
  while (!iter.isPastEnd()) {
    delete iter.current;
    iter.moveForward();
  }
  
}

  
