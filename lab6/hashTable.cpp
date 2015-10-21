//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//10/15/2015
//hashTable.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <list>
#include <cmath>
#include "hashTable.h"
using namespace std;

hashTable::hashTable(int size) {
  array = new string[size];
  asize = size;
}
  int hashTable::rehash(string line, int i) {
    int value = (int)line.at(0)+(int)line.at(1)+(int)line.at(2);
	int x = value % asize;
	int hash2 = pow(x,3);
	return (abs((value + i * hash2) % asize)); 
  }

  string hashTable::get(int spot) {        
    return array[spot];
  }
void hashTable::push(string line) {
int value = (int)line.at(0)+(int)line.at(1)+(int)line.at(2);
	int x = (value % asize);
	int hash2 = pow(x,3);
	int i = 1;
	int spot = (value+i*hash2)%asize;
	//cout <<spot<<endl;
	//cout <<line<<endl;

	while(array[spot].compare("") != 0) {
	i++;
	spot = abs((value+i*hash2)%asize);
	}
	array[spot] = line;
}
