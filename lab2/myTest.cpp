#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include "ListItr.h"
#include "List.h"
using namespace std;

int main() {
  
  ListNode *nodetest = new ListNode();
  //nodetest->value = 4;
  //cout<<nodetest->value<<endl;
  ListNode *test = new ListNode();
  test = nodetest;
  //List *test = new List;
  // cout << test->size() << endl;
  cout << nodetest <<endl;
  cout << &nodetest <<endl;
  cout << test <<endl;
  cout <<&test <<endl;
  //cout <<test->value<<endl;



  return 0;
}
