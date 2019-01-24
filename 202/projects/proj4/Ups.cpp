/***************************************************************
 * File:    Ups.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for Ups class
 *    in PROJ4: UMBC Shipping
 **************************************************************/
#include "Ups.h"

// Constructor
// Preconditions: None
// Postconditions: None
Ups::Ups(){
}

// Destructor
// Preconditions: An allocated object in memory
// Postconditions: Deallocates the memory
Ups::~Ups(){

}

// deliver() - performs the actions of delivering as a Ups object
// Preconditions: mail present in m_storage
// Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
int Ups::deliver(){
  double totalPay = 0;

  for(unsigned int i = 0; i < m_storage.size(); i++){
    cout << "Delivered:" << endl;
    cout << *(m_storage.at(i));
    
    totalPay += (m_storage.at(i))->getBaseCost() * 
      (m_storage.at(i))->getSize() * m_delivery_rate;

  }

  cout << "Deliveries completed. UPS total earned: $" 
       << setprecision(2) << fixed << totalPay << endl;

  return 1;
}

// toString() - method to format the object as a string
// Preconditions: a valid Ups object
// Postconditions: returns the Ups object as a string
ostream& Ups::print(ostream& output) const{
  output << "************************************" << endl;
  output << "Ups Truck Contents:" << endl;
  for(unsigned int i = 0; i < m_storage.size(); i++){
    output << *(m_storage.at(i));
  }
  output << "************************************" << endl;  

  return output;
}
