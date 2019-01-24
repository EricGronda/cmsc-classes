/*Title: dynamic1.cpp
Author: CMSC 202
Date: 3/5/2018
Description: This is introducing dynamic memory allocation in C++.
*/
#include <iostream>
using namespace std;

int main ()
{
  int i,n;
  int * p; //Declare a pointer
  cout << "How many numbers would you like to type? ";
  cin >> i; //Stores how many numbers to input
  p = new int[i]; //Creates a new dynamically allocated array
  for (n=0; n<i; n++) {
    cout << "Enter number: ";
    cin >> p[n]; //Inserts number into array
  }
  cout << "You have entered: ";
  for (n=0; n<i; n++)
    cout << p[n] << ((n != (i-1))?",":""); //Iterates over array and outputs - also ternary!
  cout << endl;
  delete[] p; //Deallocates dynamically allocated array - without would be memory leak
  return 0;
}
