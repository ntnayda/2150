//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//bitCounter.cpp
//9/23/2015

#include <iostream>
#include <stdlib.h>
using namespace std;

int bitCount(int x);

int bitCount(int x) {     //recursive method to find the number of bits in an integer
  if (x <= 1) {
    return 1;
  }
  else {
    return 1 + bitCount(x/2);
  }
}


int main(int argc, char *argv[]) {     //main method

  if (argc == 1) {
    return 0;
  }
  else {  
    int x = atoi(argv[1]);
    cout << bitCount(x) << endl;
    return 0;
  }

}
