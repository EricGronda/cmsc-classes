/***************************************************************
 * File:    Mail.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for Mail class
 *    in PROJ4: UMBC Shipping
 **************************************************************/
#include "Mail.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Mail::Mail(){
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Mail::Mail(int carrier, string sender, string recipient, 
	   float size, float baseCost){
  m_carrier   = carrier;
  m_sender    = sender;
  m_recipient = recipient;
  m_size      = size;
  m_baseCost  = baseCost;
}

// getCarrier() - returns the type of the carrier
// Preconditions: m_carrier is set
// Postconditions: returns an int reffering to which carrier
int Mail::getCarrier(){
  return m_carrier;
}

// getSender() - returns the sender of the mail
// Preconditions: m_sender is set
// Postconditions: returns a string of the sender
string Mail::getSender(){
  return m_sender;
}

// getRecipient() - returns the recipient of the mail
// Preconditions: m_recipient is set
// Postconditions: returns a string of the recipient
string Mail::getRecipient(){
  return m_recipient;
}

// getSize() - returns the size of the Mail
// Preconditions: m_size is set
// Postconditions: returns a float
float Mail::getSize(){
  return m_size;
}

// getBaseCost() - returns the base cost of the mail
// Preconditions: m_baseCost is set
// Postconditions: returns a float
float Mail::getBaseCost(){
  return m_baseCost;
}

// operator<<(ostream&, Mail&) - overload the << operator to handle a Mail object
// Preconditions: a valid ostream and Mail operator
// Postconditions: returns an ostream object
ostream& operator<<(ostream& output, Mail& myMail){
  output << myMail.toString() << endl;
  return output;
}
