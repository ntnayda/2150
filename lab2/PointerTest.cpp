#include <iostream>
using namespace std;
class myClass;
class myClass {
 public:
  myClass();
  int value;
  myClass * previous;
  myClass * next;
};
myClass::myClass() {
  previous = new myClass;
  next = new myClass;
}
int main() {
 int x=10;
 myClass * first;
 myClass * second;
 cout << first << endl;
 cout << &first << endl;
 //cout << first << endl;
 //cout << *first <<endl;
 // cout << second->value << endl;
 //cout << second->previous << endl;
 //cout << first->*previous << endl;
 //cout << second->previous->previous << endl;
 //cout << second->previous->previous << endl;



return 0;
}
