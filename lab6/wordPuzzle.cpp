//Nathan Nayda
//ntn4jg@virginia.edu
//ntn4jg
//10/15/2015
//hashTable.cpp
//
//Big theta can be found by multiplying the number of rows,number of columns, number of directions, number of different length words, and the runtime for finding the word in the table
//
//big theta = rows*cols*8*19*log(words)

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"
using namespace std;

#define MAXROWS 500
#define MAXCOLS 500

char table[MAXROWS][MAXCOLS];
bool readInTable (string filename, int &rows, int &cols);
string getWordInTable (int startRow, int startCol, int dir, int len, int numRows, int numCols);
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);
void printWord(int dir, int row, int col, string word);
bool checkBounds(int dir, int row, int col, int length,int totalrow, int totalcol);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    return 0;
  }
  else {
    int rows, cols;
    bool result = readInTable (argv[2],rows,cols);
    if (!result) {
      cout << "Error reading in file!" << endl;
      exit(1);
    }
    string line;
    int count = 0;
    ifstream myfile (argv[1]);
    if (myfile.is_open()) {
      while (getline(myfile,line)) {
	count++;
      }
      myfile.close();
    }
    count = count*1.5;
    int tablesize = getNextPrime(count);
    hashTable htable(tablesize);
    myfile.open(argv[1]);
    myfile.clear();
    myfile.seekg(0,myfile.beg);
  if (myfile.is_open()) {
    while (getline(myfile,line)) {
      if (line.size()>=3) {
	htable.push(line);
      }
    }
    myfile.close();
  }
timer t;
    t.start();
    int totalwordcount = 0;
    string lastword = " ";
    for (int x = 0; x<rows; x++) {
      for (int y = 0; y<cols; y++) {
	for (int dir = 0; dir<8; dir++) {
	  for (int length = 3; length < 23; length++) {
	    //cout <<dir<<", "<<x<<", "<<y<<", "<<length<<endl;
	    //cout <<checkBounds(dir,x,y,length,rows,cols)<<endl;
	    //cout <<rows<<endl;
	    //cout <<cols<<endl;
	    //cout<<"x: "<<x<<" y: "<<y<<" dir: "<<dir<<" length: "<<length<<" bound: "<<checkBounds(dir,x,y,length,rows,cols)<<endl;

	    //if (checkBounds(dir,x,y,length,rows,cols)) {
	      string fullword = getWordInTable(x,y,dir,length,rows,cols);
	      //cout<<fullword<<endl;
	      if ((fullword == lastword)||(fullword.length()<3)) {
		length = 23;
	      }
	      else{
	      //cout<< fullword<<endl;
	      //if (fullword.length()>=3) {
	      int findi = 1;
	      int findspot = htable.rehash(fullword,findi);
	      //bool found = false;
	      while(htable.get(findspot) != "") {
		if (htable.get(findspot) == fullword) {
		  printWord(dir,x,y,fullword);
		  totalwordcount++;
		  break;
		  //lastword = fullword;
		}
		  findi++;
		  findspot = htable.rehash(fullword,findi);
	      }
	      lastword = fullword;
	      }

	  }
	}
      }
    }

 t.stop();
 //cout << t << endl;
 cout << totalwordcount << " words found" << endl;
 cout << "Found all words in "<<t.getTime() << " seconds" << endl;
 int totaltime = (t.getTime()*1000);
 cout << totaltime <<endl;
    return 0;
  }
}

bool readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            table[r][c] = line[pos++];
            cout << table[r][c];
        }
        cout << endl;
    }
    // return success!
    return true;
}

string getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = table[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    string word = output;
    return word;
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

 void printWord(int dir, int row, int col, string word) {
switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
	      cout << "N (" << row << ", " << col << "):\t" << word << endl;
                break; // north
            case 1:
                cout << "NE(" << row << ", " << col << "):\t" << word << endl;
                break; // north-east
            case 2:
                cout << "E (" << row << ", " << col << "):\t" << word << endl;
                break; // east
            case 3:
                cout << "SE(" << row << ", " << col << "):\t" << word << endl;
                break; // south-east
            case 4:
                cout << "S (" << row << ", " << col << "):\t" << word << endl;
                break; // south
            case 5:
                cout << "SW(" << row << ", " << col << "):\t" << word << endl;
                break; // south-west
            case 6:
                cout << "W (" << row << ", " << col << "):\t" << word << endl;
                break; // west
            case 7:
                cout << "NW(" << row << ", " << col << "):\t" << word << endl;
                break; // north-west
        }
 }
bool checkBounds(int dir, int row, int col, int length,int totalrow, int totalcol) {
switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
	      if ((row-length) <-1) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // north
            case 1:
	      if (((row-length)<-1) || ((col+length)>totalcol)) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // north-east
            case 2:
	      if (((col+length)>totalcol)) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // east
            case 3:
	      if (((row+length)>totalrow)||((col+length)>totalcol)) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // south-east
            case 4:
	      if ((row+length)>totalrow) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // south
            case 5:
	      if (((row+length)>totalrow)||((col-length)<-1)) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // south-west
            case 6:
	      if ((col-length)<-1) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // west
            case 7:
	      if (((row-length)<-1)||((col-length)<-1)) {
		return false;
	      }
	      else {
		return true;
	      }
                break; // north-west
        }
}
