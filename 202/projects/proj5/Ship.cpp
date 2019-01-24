/***************************************************************
 * File:    Ship.cpp
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    Contains function definitions for Ship class
 *    in PROJ5: Star Wars
 **************************************************************/
#include "Ship.h"


// Name: Ship (Default Constructor)
// Preconditions: Cannot call directly (used by subclasses)
// Postconditions: Either a Imperial or Rebel ship is created
Ship::Ship(string name, string type, int attack, int defense){
  m_name = name;
  m_type = type;
  m_attack = attack;
  m_defense = defense;
}

// Name: Getters and Setters
// Preconditions: Must have a ship
// Postconditions: Either sets or gets part of class
string Ship::getName(){ 
  return m_name;
}
void Ship::setName(string name){
  m_name = name;
}
string Ship::getType(){
  return m_type;
}
void Ship::setType(string type){
  m_type = type;
}
int Ship::getAttack(){
  return m_attack;
}
void Ship::setAttack(int attack){
  m_attack = attack;
}
int Ship::getDefense(){
  return m_defense;
}
void Ship::setDefense(int defense){
  m_defense = defense;
}

/*
// Name: attack (Purely virtual)
// Preconditions: One ship is attacking another ship
// Postconditions: Returns a 1 if enemy is destroyed, 0 if enemy damaged
virtual bool attack(Ship* enemy) = 0;
*/

// operator<<(ostream&, Ship&) - overload the << operator to handle a Ship object
// Preconditions: a valid ostream and Ship operator (calls toString)
// Postconditions: returns an ostream object
ostream& operator<<(ostream& os, Ship& b){
  b.toString(os);
  return os;
}
