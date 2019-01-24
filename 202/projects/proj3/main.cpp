/**************************************************************
 * File:    main.cpp
 * Author:  Eric Gronda
 * Project: CMSC 202 PROJ3, SP 18
 * Date:    4/10/18
 * E-mail:  eric.gronda@umbc.edu
 * Description:
 *   Driver file for PROJ3: UMBC Trains
 *************************************************************/
#include "Car.h"
#include "Train.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// CONSTANTS
string ADD    = "add";    // strings used in getTrains();
string REMOVE = "remove";

string BIOL = "BIOLOGICAL";  // strings used in stringToCargo()
string POIS = "POISONOUS";
string COMB = "COMBUSTIBLE";
string OXID = "OXIDIZER";
string RADI = "RADIOACTIVE";
string LOCO = "LOCOMOTIVE";
string CABO = "CABOOSE";

// function headers

// getTrains() reads in data from a file and fills a vector of trains
// Input:      char []; c-string containing the name of the file
// Output:     vector <Train*>; a filled vector of trains
vector <Train*> getTrains(char []);

// verifyTrain() verifies whether there needs to be a new train in a vector
// Input:        vector <Train*>; vector to add a train pointer to
//               int;             number of train
// output:       vecotr <Train*>; adds new train if necessary
vector <Train*> addTrain(vector <Train*> , int);

// stringToCargo() converts a string to a CARGO_TYPE
// Input:          string; a string to be converted
// Output:         CARGO_TYPE; the converted string
CARGO_TYPE stringToCargo(string);

/**********************************************************************/

int main(int argc , char* argv[]){
  vector <Train*> myTrains;

  // file verification
  if(argv[1] > 0){
    cout << "A file has been loaded. Starting Program." << endl;
  }else{
    cout << "No file loaded. Exiting Program." << endl;
    return 0;
  }

  // file i/o
  myTrains = getTrains(argv[1]);

  // display output
  for(unsigned int i = 0; i < myTrains.size(); i++){
    cout << *(myTrains.at(i));
  }

  // clear trains
  for(unsigned int i = 0; i < myTrains.size(); i++){
    delete myTrains.at(i);
    myTrains.at(i) = NULL;
  }

  return 0;
}

/*********************************************************************/

vector <Train*> getTrains(char c_string[]){
			  
  // file i/o
  string temp;
  int number;
  string action;
  string type;
  CARGO_TYPE cargo;
  ifstream ifp;
  vector <Train*> myTrains;
  
  ifp.open(c_string); // open file

  while( getline(ifp, temp , ',') ){
    // get data
    number = atoi(temp.c_str());
    getline(ifp, action , ',');
    getline(ifp, type,'\n');

    // convert type to CARGO_TYPE
    cargo = stringToCargo(type);
 
    // verify and add train
    myTrains = addTrain(myTrains , number);

    // loop through trains
    for(unsigned int i = 0; i < myTrains.size(); i++){
      if(number == (int)( (myTrains.at(i))->getNumber() )){

	// add cars
	if(action == ADD){
	  Car* newCar = new Car( cargo );
	  (myTrains.at(i))->addCar( newCar->getCargo() , 
				    (myTrains.at(i))->getLength() );
	  delete newCar;
	}
	
	// remove cars
	else if(action == REMOVE){
	  (myTrains.at(i))->removeCar( cargo );
	}

      }
    }
    
  }

  ifp.close(); // close file
  return myTrains;
}

/****************************************************************/

vector <Train*> addTrain(vector <Train*> myTrains, int number){
  bool needsTrain; // flag
 
  // verify if new train is needed
  if(myTrains.size() > 0){
    needsTrain = true;

    for(unsigned int i = 0; i < myTrains.size(); i++){
      //if this is not a new number train
      if(number == (int)( (myTrains.at(i))->getNumber() ))
	needsTrain = false;
    }
    
    // if we need to add a train
    if(needsTrain){
      Train* newTrain = new Train(number);
      myTrains.push_back( newTrain );
    }
    
    //adds train if no trains
  }else{
    Train* newTrain = new Train(number);
    myTrains.push_back( newTrain );
  }
  
  return myTrains;
}

/*********************************************************************/

CARGO_TYPE stringToCargo(string type){
  CARGO_TYPE cargo;
 
  if(type == BIOL)
    cargo = BIOLOGICAL;
  else if(type == POIS)
    cargo = POISONOUS;
  else if(type == COMB)
    cargo = COMBUSTIBLE;
  else if(type == OXID)
    cargo = OXIDIZER;
  else if(type == RADI)
    cargo = RADIOACTIVE;
  else if(type == LOCO)
    cargo = LOCOMOTIVE;
  else if(type == CABO)
    cargo = CABOOSE;
  
  return cargo;
}
