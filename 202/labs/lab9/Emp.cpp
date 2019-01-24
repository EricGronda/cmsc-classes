#include "Emp.h"

Employee::Employee(){
  m_name = "No name";
  m_age = -1;
  m_salary = -1;
}

Employee::Employee(string name, int age, int salary){
  m_name = name;
  m_age = age;
  m_salary = salary;

}

void Employee::raiseSalary(){
  m_salary = 1 * m_salary;
}

void Employee::showDesignation(){
  cout << "You are an employee" << endl;
}

string Employee::getName(){return m_name;}
void Employee::setName(string name){m_name = name;}

int Employee::getAge(){return m_age;}
void Employee::setAge(int age){m_age = age;}

int Employee::getSalary(){return m_salary;}
void Employee::setSalary(int salary){m_salary = salary;}
