/***************************************************************
 * File:    Rebel.cpp
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    Contains function definitions for Rebel class
 *    in PROJ5: Star Wars
 **************************************************************/
#include "Rebel.h"

/*
// Name: Rebel (Default Constructor)
// Preconditions: Uses ship constructor (initialization list)
// Postconditions: Creates a Rebel ship
Rebel(string name, string type, int attack, int defense)
  :Ship(name, type, attack, defense){}
*/

// Name: Attack (inherited from Ship)
// Preconditions: Requires valid enemy ship
// Postconditions: Compares Rebel attack to Imperial defense
// Returns 1 if destroyed or 0 if damaged
bool Rebel::attack(Ship* enemy){
  cout << "The Rebel " << getName() 
       << " attacks the Imperial " << enemy->getName() << endl;
  cout << "The Imperial " << enemy->getName();

  // compare attack to defense
  if(getAttack() >= enemy->getDefense()){
    cout << " is destroyed." << endl;
    return true;
  }
  
  else{
    cout << " is damaged." << endl;
    enemy->setDefense( enemy->getDefense() - getAttack() );
    return false;
  }

}

// Name: toString() - method to format a rebel
// Preconditions: A rebel object
// Postconditions: returns the rebel object as a ostream object
ostream& Rebel::toString(ostream& os){
  os << getName();
  return os;
}
