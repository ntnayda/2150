//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//postfixCalculator.cpp
//9/13/2015

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
#include <stdlib.h>

using namespace std;

void postfixCalculator::push(int e){ //add a number to the top of the stack
  s.push(e);

}

int postfixCalculator::top() const{ //returns the number at the top of the stack
  if (s.empty()) {
    cout << "Error: stack is empty";
    exit(EXIT_SUCCESS);
  }
  else {
    return s.top();
  }
}

void postfixCalculator::pop() { //removes the number at the top of the stack
  if (s.empty()) {
    cout << "Error: stack is empty";
  }
  else {
    s.pop();
  }
}

bool postfixCalculator::empty() const { //returns where the stack is empty or not
  if (s.empty()) {
    return true;
  }
  else {
    return false;
  }
}

void postfixCalculator::add() { //adds the top two numbers in the stack
  int x = top();
  pop();
  int y = top();
  pop();
  push(x+y);
}

void postfixCalculator::subtract() { //subtracts the top two numbers in the stack
  int x = top();
  pop();
  int y = top();
  pop();
  push(y-x);
}

void postfixCalculator::divide() { //divide the top two numbers in the stack
  int x = top();
  pop();
  int y = top();
  pop();
  push(y/x);
}

void postfixCalculator::multiply() { //multiplies the top two numbers in the stack
  int x = top();
  pop();
  int y = top();
  pop();
  push(y*x);
}

void postfixCalculator::negate() { //makes negates the top number in the stack
  int x = top();
  pop();
  push(-x);
}

