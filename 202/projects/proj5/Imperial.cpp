/***************************************************************
 * File:    Imperial.cpp
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    Contains function definitions for Imperial class
 *    in PROJ5: Star Wars
 **************************************************************/
#include "Imperial.h"

/*
// Name: Imperial (Default Constructor)
// Preconditions: Uses ship constructor (initialization list)
// Postconditions: Creates an Imperial ship
Imperial::Imperial(string name, string type, int attack, int defense)
  :Ship(name, type, attack, defense){}
*/

// Name: Attack (Inherited from Ship)
// Preconditions: Requires valid enemy ship
// Postconditions: Compares Imperial attack to Rebel defense
// Returns 1 if destroyed or 0 if damaged
bool Imperial::attack(Ship* enemy){
  cout << "The Imperial " << getName()
       << " attacks the Rebel " << enemy->getName() << endl;
  cout << "The Rebel " << enemy->getName();
  
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

// Name: toString() - Method to format a rebel
// Preconditions: A rebel object
// Postconditions: returns the rebel object as a ostream object
ostream& Imperial::toString(ostream& os){
  os << getName();
  return os;
}
