/*****************************************************
 * File:    lab1.cpp
 * Author:  Eric Gronda
 * Date:    2/1/18
 * Section: 04
 * E-mail:  eric.gronda@umbc.edu
 *
 * This file asks the user for 3 grades and 
 * returns an average
 *
 *******************************************************/

#include <iostream>
using namespace std;

int main() {
  // declare variables
  string name;
  double grade1;
  double grade2;
  double grade3;
  double average;

  // ask the user for name
  cout << "Enter your first name:" << endl;
  cin >> name;

  // ask the user for grades
  cout << "Enter your first grade:" << endl;
  cin >> grade1;  
  cout << "Enter your second grade:" << endl;
  cin >> grade2;
  cout << "Enter your third grade:" << endl;
  cin >> grade3;

  // calculate average
  average = (grade1 + grade2 + grade3) / 3;

  // print average to console
  cout << "Jeremy your average is " << average << endl;

  return 0;
}
