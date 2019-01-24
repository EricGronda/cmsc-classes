/***************************************************************
 * File:    Carrier.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for Carrier class
 *    in PROJ4: UMBC Shipping
 **************************************************************/

#include "Carrier.h"

// Constructor
// Preconditions: None
// Postconditions: None
Carrier::Carrier(){
}

// Destructor
// Preconditions: An initialized Carrier object in memory
// Postconditions: Object deallocated
Carrier::~Carrier(){
  for(unsigned int i = 0; i < m_storage.size(); i++){
    delete m_storage.at(i);
    m_storage.at(i) = NULL;
  }
}

// insert(Mail*) - Inserts mail into the vector of Mail*
// Preconditions: A valid Mail pointer. Not at max capacity
// Postconditions: Adds the mail pointer to m_storage
int Carrier::insert(Mail* mail){
  if((int)(m_storage.size()) < m_max_capacity){
    m_storage.push_back(mail);
    return 0; // 0 = success
  }
  
  else{
    cout << "Max capacity exceeded" << endl;
    return 1; // 1 = fail
  }
  
}

/*
// deliver() - Virtual function to handle delivering mail
// Preconditions: Mail to be present in m_storage
// Postconditions: Displays info about the delivery
virtual int Carrier::deliver() = 0;
*/

// setMaxCapacity(int) - Sets the max capacity of the Carrier
// Preconditions: a positive int
// Postconditions: m_max_capacity is set
void Carrier::setMaxCapacity(int max_capacity){
  m_max_capacity = max_capacity;
}

// setRate(float) - Sets the delivery cost rate of the Carrier
// Preconditions: a positve float
// Postconditions: m_delivery_rate is set
void Carrier::setRate(float delivery_rate){
  m_delivery_rate = delivery_rate;
}

// operator<<(ostream&, const Carrier&) - Allows the << operator to be
// used on a Carrier object
// Preconditions: valid ostream and Carrier objects
// Postconditions: returns ostream
ostream &operator<<(ostream& output, const Carrier& myCarrier){
  myCarrier.print(output);
  return output;
}

/*
// toString - Virtual function to return a string version of Carrier
// Preconditions: Carrier object exists
// Postconditions: Returns string
virtual ostream& print(ostream&) const = 0;
*/
