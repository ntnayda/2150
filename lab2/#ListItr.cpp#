//Nathan Nayda
//ntn4jg
//ntn4jg@virginia.edu
//ListItr.cpp
//9/6/2015


#include <iostream>
#include "ListItr.h"
//#include "List.h"
//#include "ListNode.h"
using namespace std;

ListItr::ListItr() {        //Constructor
  current= NULL;
}

ListItr::ListItr(ListNode* theNode) {     //One parameter constructor
  current = theNode;
}

bool ListItr::isPastEnd() const {     //Returns true if past end position in list, else false
  if(current->next == NULL) {
    return true;
  }
  else {
return false;
}
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}


void ListItr::moveForward() {
  current = current->next;
}

void ListItr::moveBackward() {
  current = current->previous;
}

int ListItr::retrieve() const {
  return current->value;
}


