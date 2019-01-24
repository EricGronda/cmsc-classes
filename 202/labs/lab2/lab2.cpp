/*
* File:    lab2.cpp
* Author:  Eric Gronda
* Date:    02/06/18
* Section: 04
* E-mail:  eric.gronda@umbc.edu
*
* This file tells the user his age group based on their age
************************************************************/

#include <iostream>
#include <string>
using namespace std;

// declarations
string getName();
int    getAge();
void   printLetter(int);


int main() {
  // initialize variables
  string name = getName();
  int age = getAge();

  // print final statement
  cout << name << " is in the ";
  printLetter(age);
  cout << " generation" << endl;

  return 0;
}

string getName() {
  string name;
  
  // prompt name
  do{
    cout << "Enter your name:" << endl;
    getline(cin , name);
  }while( name.length() < 2 || name.length() > 15);

  return name;
}

int getAge() {
  int age;
  
  // gets an age and validates
  do{
    cout << "Enter your age (>= 0):" << endl;
    cin >> age;
  }while(age < 0);
  
  return age;
}

void printLetter(int age) {
  string ageGroup;
  
  // pick age group based on age
  switch(age){
    
  case 0 ... 34:
    ageGroup = "Millenial";
    break;
    
  case 35 ... 50:
    ageGroup = "Gen X";
    break;

  case 51 ... 69:
    ageGroup = "Boomer";
    break;

  case 70 ... 87:
    ageGroup = "Silent";
    break;

  default:
    ageGroup = "Greatest";
    break;

  }

  // print out age group
  cout << ageGroup;
  
}
