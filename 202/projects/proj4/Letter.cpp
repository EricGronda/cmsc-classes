/***************************************************************
 * File:    Letter.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for Letter class
 *    in PROJ4: UMBC Shipping
 **************************************************************/
#include "Letter.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Letter::Letter(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Letter::Letter(int carrier, string sender, string recipient,
       float size, float baseCost){
  m_carrier   = carrier;
  m_sender    = sender;
  m_recipient = recipient;
  m_size      = size;
  m_baseCost  = baseCost;
}

// Destructor
// Preconditions: A letter object allocated in memory
// Postconditions: Deallocates the object in memory
Letter::~Letter(){
}

// toString() - method to format the Letter object as a string
// Preconditions: A Letter object
// Postconditions: returns the letter object as a string
string Letter::toString(){
  stringstream myStream;
  myStream << fixed << setprecision(1) << m_size;
  string size = myStream.str();

  string myLetter = "----------------------------------\n";
  myLetter +=       "LETTER\n";
  myLetter +=       "To:   " + m_recipient + "\n";
  myLetter +=       "From: " + m_sender    + "\n";
  myLetter +=       "Size: " + size;
  myLetter +=       " square inches\n";
  myLetter +=       "----------------------------------";

  return myLetter;
}
