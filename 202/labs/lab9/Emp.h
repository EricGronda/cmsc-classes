#ifndef EMP_H
#define EMP_H

#include <iostream>
#include <string>
using namespace std;

class Employee{
 public:
  Employee();
  Employee(string , int , int);

  virtual void raiseSalary() = 0;
  virtual void showDesignation() = 0;

  string getName();
  void setName(string name);
  int getAge();
  void setAge(int age);
  int getSalary();
  void setSalary(int salary);

  void printSalary(){
    cout << "My salary is: " << m_salary << endl;
  }

 private:
  string m_name;
  int m_age;
  int m_salary;
};

#endif
