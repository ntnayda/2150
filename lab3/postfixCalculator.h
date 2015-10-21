//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//postfixCalculator.h
//9/13/2015


#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator {

 public:

  void push(int e); //adds number to top of stack
  int top() const; //returns the top of the stack
  void pop(); //removes the number at the top of the stack
  bool empty() const; //returns if the stack is empty or not
  void add(); //adds the top two numbers
  void subtract(); //subtracts the top two numbers
  void multiply(); //multiplies the top two numbers
  void divide(); //divides the top two numbers
  void negate(); //negates the top number

 private:
  stack<int> s; 
};


#endif
