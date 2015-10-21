#include <iostream>
#include <string>
#include "hashTable.h"
#include <fstream>

using namespace std;
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);
int main(int argc, char *argv[]) {
  string line;
    hashTable htable(37717);
    ifstream myfile (argv[1]);
  if (myfile.is_open()) {
    while (getline(myfile,line)) {
      if (line.size()>=3) {
	cout <<line<<endl;
	//htable.push(line);
      }
    }
    //int spot = htable.rehash("abbe",tablesize,1);
  //cout << htable.get(spot) << endl;
  return 0;
}
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
