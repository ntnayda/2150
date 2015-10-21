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

hashTable::hashTable(string filename,int size) {
  string line;
  array = new string[size];
  ifstream myfile (filename);
  if (myfile.is_open()) {
    while (getline(myfile,line)) {
      if (line.size()>=3) {
	char* word = line.c_str();
	int value = (int)word[0]+(int)word[1]+(int)word[2];
	int x = wordsize % size;
	int hash2 = pow(x,2);
	int i = 1;
	while(array[(value+i*hash2)%size] != NULL) {
	i++;
	}
	array[(value+i*hash2)%size] = line;
      }
    }
    myfile.close();
  }

  int hashTable::rehash(string line, int size,int i) {
	char* word = line.c_str();
	int value = (int)word[0]+(int)word[1]+(int)word[2];
	int x = wordsize % size;
	int hash2 = pow(x,2);
	return ((value + i * hash2) % size); 
  }

  string hashTable::get(int spot) {    
    return array[spot];
  }
