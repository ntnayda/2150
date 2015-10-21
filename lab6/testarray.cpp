#include <iostream>
using namespace std;

int main() {
  char *array = new char[10];
  if (array[2]=='\0') {
    cout <<"null"<<endl;
  }
  else { 
cout << array[2];
  }
}
