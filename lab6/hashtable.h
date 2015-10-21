//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//hashTable.h
//10/19/2015
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

using namespace std;
class hashTable {
public:
hashTable(string filename, int size);
int rehash(string line, int size, int i);
string get(int spot);

private:
string[] array;
};

#endif
