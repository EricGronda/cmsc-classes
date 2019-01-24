/***************************************************************
 * File:    Imperial.h
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    Header file for Imperial class in PROJ5: Star Wars
 **************************************************************/
#ifndef IMPERIAL_H
#define IMPERIAL_H

#include "Ship.h"

class Imperial:public Ship{
 public:
  // Name: Imperial (Default Constructor)
  // Preconditions: Uses ship constructor (initialization list)
  // Postconditions: Creates an Imperial ship
  Imperial(string name, string type, int attack, int defense)
    :Ship(name, type, attack, defense){}
  // Name: Attack (Inherited from Ship)
  // Preconditions: Requires valid enemy ship
  // Postconditions: Compares Imperial attack to Rebel defense
  // Returns 1 if destroyed or 0 if damaged
  bool attack(Ship* enemy);
  // Name: toString() - Method to format a rebel
  // Preconditions: A rebel object
  // Postconditions: returns the rebel object as a ostream object
  ostream& toString(ostream& os);
};

#endif
