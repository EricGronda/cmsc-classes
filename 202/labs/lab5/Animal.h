#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

class Animal{
 public:
  // getters
  string GetSound();
  string GetName();

  // setters
  void SetSound(string sound);
  void SetName(string name);

  // other functions
  void WhoAmI();

 private:
  string m_makeSound;
  string m_name;

};

#endif
