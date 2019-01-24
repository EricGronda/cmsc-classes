#include "Emp.h"
#include "Manager.h"
#include "Developer.h"

int main(){
  Employee* emp;
  Manager mng("John" , 34 , 20000);
  Developer dev("Patrick" , 23 , 10000);
  mng.showDesignation();
  mng.printSalary();
  dev.showDesignation();
  dev.printSalary();

  cout<< endl 
      << "Following Prints are done using Pointer of SuperClass" <<endl;

  emp = &mng; //Assigning Manager Object to Emp.
  emp->raiseSalary();
  emp->showDesignation();
  emp->printSalary();

  emp = &dev; //Assigning Developer Object to Emp.
  emp->raiseSalary();
  emp->showDesignation();
  emp->printSalary();
  return 0;
}
