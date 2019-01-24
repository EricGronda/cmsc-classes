#include "Manager.h"
#include "Emp.h"

Manager::Manager(){
  setName("No name");
  setAge(-1);
  setSalary(-1);
}

Manager::Manager(string name, int age, int salary){
  setName(name);
  setAge(age);
  setSalary(salary);
}


void Manager::raiseSalary(){
  setSalary( 1.4 * getSalary() );
}

void Manager::showDesignation(){
  cout << "I am a manager" << endl;
}
