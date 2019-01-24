/***************************************************************
 * File:    FedEx.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for FedEx class
 *    in PROJ4: UMBC Shipping
 **************************************************************/
#include "FedEx.h"

// Constructor
// Preconditions: None
// Postconditions: None
FedEx::FedEx(){
}

// Destructor
// Preconditions: An allocated object in memory
// Postconditions: Deallocates the memory
FedEx::~FedEx(){

}

// deliver() - performs the actions of delivering as a FedEx object
// Preconditions: mail present in m_storage
// Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
int FedEx::deliver(){
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
// Preconditions: a valid FedEx object
// Postconditions: returns the FedEx object as a string
ostream& FedEx::print(ostream& output) const{
  output << "************************************" << endl;
  output << "FedEx Truck Contents:" << endl;
  
  for(unsigned int i = 0; i < m_storage.size(); i++){
    output << *(m_storage.at(i));
  }

  output << "************************************" << endl;

  return output;
}
