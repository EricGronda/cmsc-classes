/**************************************************************
 * File: Car.cpp
 * Author: Eric Gronda
 * Project: CMSC 202 PROJ3, SP 18
 * Date: 4/10/18
 * E-mail: eric.gronda@umbc.edu
 * Description:
 *   Contains all the function definitions for the Car class
 *************************************************************/
#include "Car.h"

// Name: Car (Default Constructor)
// PreCondition:  none
// PostCondition: instantiates a default-constructed Car object
Car::Car(){
  //  m_cargo = (CARGO_TYPE)NULL;
  m_next = NULL;
}

// Name: Car (Overloaded Constructor)
// PreCondition:  CARGO_TYPE is valid
// PostCondition: instantiates a Car object with given cargo
Car::Car(CARGO_TYPE cargo){
  m_cargo = cargo;
  m_next = NULL;
}

// Name: ~Car (Destructor)
// PreCondition:  none
// PostCondition: destroys car object and deallocates memory
Car::~Car(){
    
}

// Name: getCargo
// PreCondition:  none
// PostCondition: returns current cargo
CARGO_TYPE Car::getCargo() const{
  return m_cargo;
}

// Name: Car
// PreCondition:  CARGO_TYPE is valid
// PostCondition: sets a new cargo type for the object
void Car::setCargo(CARGO_TYPE cargo){
  m_cargo = cargo;
}

// Name: getNext
// PreCondition:  none
// PostCondition: returns the next node in the list (or null)
Car *const Car::getNext() const{
  return m_next;
}

// Name: setNext
// PreCondition:  given Car* is a valid pointer to a car object
// PostCondition: sets the next car to the given pointer.
void Car::setNext(Car* next){
  m_next = next;
}

// Name: getLength
// PreCondition:  none
// PostCondition: returns the current length of the train, assuming callee
//                is the head of the list.
int Car::getLength() const{
  int numCars = 0;

  //while(*m_next != NULL) //last car will point to null
      //numCars++
  
  return numCars;
}
