//Nathan Nayda
//ntn4jg@virgina.edu
//ntn4jg
//inlab4.cpp
//9/22/2015

#include <iostream>
#include <climits>
#include <cfloat>

using namespace std;

int main() {
  int i=INT_MAX;
  int i1 =1;
  unsigned int ui=0;
  unsigned int ui1=1;
  float f = 0.0;
  float f1 = 1.0;
  double d = DBL_MAX;
  double d1 = 1.0;
  char c =CHAR_MAX;
  char c1 = '1';
  bool b=false;
  bool b1=true;
  int *ip = NULL;
  char *cp=NULL;
  double *dp=NULL;
  cout << i<<i1<<ui<<ui1<<f<<f1<<d<<d1<<c<<c1<<b<<b1<<ip<<cp<<dp<<endl;
  cout << "done"<< endl;

  //*****************PART2***************************************//

  int IntArray[10]={0,1,2,3,4,5,6,7,8,9};
  char CharArray[10]={'a','b','c','d','e','f','g','h','i','j'};
  int IntArray2D[6][5]={{1,2,3,4,5},{5,7,3,9,8},{3,5,7,9,0},{2,4,6,8,10},{11,12,13,14,15},{16,17,18,19,20}};
  char CharArray2D[6][5]={{'p','i','z','z','a'},{'h','o','u','s','e'},{'h','u','s','k','y'},{'f','o','r','k','s'},{'g','o','o','s','e'},{'s','a','u','c','e'}};
  cout <<IntArray[0]<<CharArray[0]<<IntArray2D[0][0]<<CharArray2D[0][0]<<endl;
  cout <<"done"<<endl;
}
