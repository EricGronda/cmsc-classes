/***************************************************************
 * File:    Package.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Contains the function definitions for Package class
 *    in PROJ4: UMBC Shipping
 **************************************************************/
#include "Package.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Package::Package(){

}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Package::Package(int carrier, string sender, string recipient,
	       float size, float baseCost){
  m_carrier   = carrier;
  m_sender    = sender;
  m_recipient = recipient;
  m_size      = size;
  m_baseCost  = baseCost;
}

// Destructor
// Preconditions: A package object allocated in memory
// Postconditions: Deallocates the object in memory
Package::~Package(){
}

// toString() - method to format the Package object as a string
// Preconditions: A Package object
// Postconditions: returns the package object as a string
string Package::toString(){
  stringstream myStream;
  myStream << fixed << setprecision(1) << m_size;
  string size = myStream.str();

  string myPackage = "----------------------------------\n";
  myPackage +=       "PACKAGE\n";
  myPackage +=       "To:   " + m_recipient + "\n";
  myPackage +=       "From: " + m_sender    + "\n";
  myPackage +=       "Size: " + size;
  myPackage +=       " lbs\n";
  myPackage +=       "----------------------------------";

  return myPackage;
}
