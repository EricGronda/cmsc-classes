#include "Developer.h"
#include "Emp.h"

Developer::Developer(){
  setName("No name");
  setAge(-1);
  setSalary(-1);
}

Developer::Developer(string name, int age, int salary){
  setName(name);
  setAge(age);
  setSalary(salary);
}


void Developer::raiseSalary(){
  setSalary( 1.3 * getSalary() );
}

void Developer::showDesignation(){
  cout << "I am a developer" << endl;
}
