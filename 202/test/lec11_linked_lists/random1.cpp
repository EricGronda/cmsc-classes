/*Title: random1.cpp
Author: CMSC 202
Date: 3/5/2018
Description: This is introducing psuedorandom numbers in C++.
*/
#include <cstdlib> //Required for rand
#include <ctime> //Required for time
#include <iostream>
using namespace std;


int main () {
  srand(time(NULL)); //Seeds random number generator (psuedo)
  cout << time(NULL) << endl; //Outputs time value

  cout << rand() << endl; //Outputs a random number
  cout << rand() % 10 + 1 << endl; //Outputs a random number in a range
  return 0;
}
