//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//prelab4.cpp
//9/20/2015

#include<iostream>
#include <math.h>
#include <cmath>
#include <cfloat>
#include <climits>


using namespace std;


void sizeOfTest() {
  cout << "int: " << sizeof(int) << endl;
cout << "unsigned int: " << sizeof(unsigned int) << endl;
cout << "float: " << sizeof(float) << endl;
cout << "double: " << sizeof(double) << endl;
cout << "char: " << sizeof(char) << endl;
cout << "bool: " << sizeof(bool) << endl;
cout << "int*: " << sizeof(int*) << endl;
 cout << "char*: " << sizeof(char*) << endl;
cout << "double*: " << sizeof(double*) << endl;
}

void outputBinary(unsigned int x) {
  int value = (short) x; 
  int list[36] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (int i=35;i>=0;i--) {
    list[i] = x%2;
    x = x/2;
  }

  for (int i =0;i<36;i++) {
    if ((i+1)%4 ==0) {
      cout << list[i];
	cout << " ";
    }
    else {
      cout << list[i];
    }
  }
  cout << endl;

}
void overflow() {
  unsigned int i = 4294967295;
  cout << i << endl;
  cout << i+1 << endl;
  cout << "All bits are at 1 and so when it tries to add another it resests all the bits back to 0, giving you a value of 0." << endl;
}

int main() {
  unsigned int x;  
cin >> x;
  sizeOfTest();
  outputBinary(x);
    overflow();
    cout << "int: " << INT_MAX << endl;
    cout << "unsigned int: " << UINT_MAX << endl;
    cout << "float: " << FLT_MAX << endl;
    cout << "double: " << DBL_MAX << endl;
    cout << "char: " << CHAR_MAX << endl;

}
