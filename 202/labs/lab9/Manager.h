#ifndef MANAGER_H
#define MANAGER_H

#include "Emp.h"
#include <string>
#include <iostream>
using namespace std;

class Manager : public Employee{
 public:
  Manager();
  Manager(string , int , int);

  virtual void raiseSalary();
  virtual void showDesignation();
  
};


#endif
