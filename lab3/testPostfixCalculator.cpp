//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//testPostfixCalculator.cpp
//9/13/2015

#include <iostream>
#include "postfixCalculator.h"
using namespace std;

int main() {
  postfixCalculator p;
  p.push(1);
  p.push(2);
  p.push(3);
  p.push(4);
  p.push(5);
  p.add();
  p.add();
  p.add();
  p.add();

  /*divide
 p.push(-1512);
  p.push(-12);
  p.push(-2);
  p.divide();
  p.divide();
  p.push(-2);
  p.divide();
  p.push(3);
  p.divide();
  */
  /*
negate
  p.push(-1);
  p.negate();
  p.negate();
  p.negate();
  */
  cout << "Result is: " << p.top() <<endl;
  return 0;
}
