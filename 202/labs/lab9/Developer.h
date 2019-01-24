#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Emp.h"
#include <string>
#include <iostream>
using namespace std;

class Developer : public Employee{
 public:
  Developer();
  Developer(string name, int age, int salary);

  virtual void raiseSalary();
  virtual void showDesignation();
};

#endif
