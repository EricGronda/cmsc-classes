/***********************************************************
 * File:    proj1.cpp
 * Author:  Eric Gronda
 * Date:    2/08/18
 * Section: 04
 * E-mail:  eric.gronda@umbc.edu
 *
 * Project 1: Urban Heat Island details and models varying
 * land temperatures based on land cover.
 **********************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// constants
const int MIN_BASE_TEMP = -130;
const int MAX_BASE_TEMP =  134;
const int FILE_WIDTH  = 5;
const int FILE_LENGTH = 6;
const int LAND_SPACING = 2;
const int TEMP_SPACING = 6;
const string EMPTY_STRING = "";
const double CLEAR_NUM = 200;

// temperature multipliers
const double R = 1.01; // Rural
const double S = 1.03; // Suburban Residential
const double C = 1.05; // Commercial
const double U = 1.04; // Urban Residential
const double D = 1.09; // Downtown
const double P = 1.02; // Park
const double F = 1.00; // Rural Farmland

// function declarations

/*********************************************************************
 * mainMenu() Welcomes the user to the application and has the user
 *            choose between loading in a new file, modeling the
 *            temperatures, and exiting
 * Input:     None
 * Output:    userVal; an int, used to decide which portion of the 
 *                     is activated
 ********************************************************************/
int mainMenu();

/*********************************************************************
 * loadLandCoverFile() loads in a provided file and stores input
 *                     into a 2D array
 * Input:              array2D; a 2D array, used to store file data
 * Output:             None
 ********************************************************************/
void loadLandCoverFile(string array2D[FILE_LENGTH][FILE_WIDTH]);

/*********************************************************************
 * printGrid() iterates over the array of strings and 
 *             displays each land cover/ temperature
 * Input:      array2D; a 2D array, used as a source for data to
 *                      be displayed to console
 * Output:     None
 ********************************************************************/
void printGrid(string array2D[FILE_LENGTH][FILE_WIDTH]);
void printGrid(double array2D[FILE_LENGTH][FILE_WIDTH]);

/*********************************************************************
 * modelTemps() asks for the current temperature; uses current
 *              temperatures and iterates over the array and
 *              calculates the correct temperature for each of the
 *              land covers
 * Input:       landCoverList; a 2D array, filled with land types
 *                             that decide multipliers
 *              tempList; a 2D array, filled with temperatures
 *                        that are multiplied based on land type
 * Output:      None
 ********************************************************************/
void modelTemps(string landCoverList[FILE_LENGTH][FILE_WIDTH] ,
		double tempList[FILE_LENGTH][FILE_WIDTH]      );

/*********************************************************************
 * clearList() sets all data in a 2D array to a certain value
 * Input:      list; a 2D array, used to reset data
 * Output:     None
 ********************************************************************/
void clearList(string list[FILE_LENGTH][FILE_WIDTH]);
void clearList(double list[FILE_LENGTH][FILE_WIDTH]);

/********************************************************************/

int main() {
  // initialize variables
  int menuChoice;
  string landCoverList[FILE_LENGTH][FILE_WIDTH];
  double tempList[FILE_LENGTH][FILE_WIDTH];
  
  // make empty list
  clearList(landCoverList);
  clearList(tempList);

  do{
    menuChoice = mainMenu(); // gets menu choice from main menu

    // picks menu
    switch(menuChoice){
    case 1:
      // print out land covers from 2D array
      loadLandCoverFile(landCoverList);
      printGrid(landCoverList);
      break;

    case 2:
      // print out temps from 2D array
      modelTemps(landCoverList , tempList);
      printGrid(tempList);
      break;

    case 3:
      // exit
      break;
    }
    
  }while( menuChoice != 3 );

  cout << "Thank you for using the Urban Heat Island Model" << endl;

  return 0;
}

/********************************************************************/

// function definitions

int mainMenu(){
  int userVal = 0;

  // display menu and get input
  do{
    cout << "Welcome to the Urban Heat Island Model" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Load Land Cover File" << endl;
    cout << "2. Model Temperatures Based on Land Cover" << endl;
    cout << "3. Exit" << endl;
    cin >> userVal;
  }while( userVal > 3 || userVal < 1 ); // only validates integers
  
  return userVal;
}

/******************************************************/
void clearList(string list[FILE_LENGTH][FILE_WIDTH]){
  int i = 0, j = 0;

  for(i = 0; i < FILE_LENGTH; i++){
    for(j = 0; j < FILE_WIDTH; j++){
      list[i][j] = EMPTY_STRING;
    }
  }
}
void clearList(double list[FILE_LENGTH][FILE_WIDTH]){
  int i = 0, j = 0;

  for(i = 0; i < FILE_LENGTH; i++){
    for(j = 0; j < FILE_WIDTH; j++){
      list[i][j] = CLEAR_NUM;
    }
  }
}

/*********************************************************************/
void loadLandCoverFile(string landCoverList[FILE_LENGTH][FILE_WIDTH]){
  string fileName;
  ifstream ifp;
  string landCover;
  int i = 0 , j = 0;

  // get file name
  cout << "What is the name of the file to import?" << endl;
  cin >> fileName;
  
  
  ifp.open( fileName.c_str() );
  if( ifp.is_open() ){
    // convert data to 2D array
    cout << "File succesfully loaded" << endl;
    
    // make 2D array
    for(i = 0; i < FILE_LENGTH; i++){
      for(j = 0; j < FILE_WIDTH; j++){
	ifp >> landCoverList[i][j];
      }
    }
    
  }else{
    // return to main menu if not opened
    cout << "The file " << fileName << " was not opened." << endl;
    
  }
  
  ifp.close();

}

/*********************************************************/
void printGrid(string array2D[FILE_LENGTH][FILE_WIDTH]){
  int i = 0, j = 0;
  // see if array is able to print
  if(array2D[0][0] == "R" or
     array2D[0][0] == "S" or
     array2D[0][0] == "C" or
     array2D[0][0] == "U" or
     array2D[0][0] == "D" or
     array2D[0][0] == "P" or
     array2D[0][0] == "F" ){

    // print array
    for(i = 0; i < FILE_LENGTH; i++){
      for(j = 0; j < FILE_WIDTH; j++){
	cout << setw(LAND_SPACING) << array2D[i][j] << " ";
      }
      cout << "\n";
    }
  }
}

void printGrid(double array2D[FILE_LENGTH][FILE_WIDTH]){
  int i = 0, j = 0;
 
  if(array2D[0][0] != CLEAR_NUM){
    cout << setprecision(1) << fixed;

    for(i = 0; i < FILE_LENGTH; i++){
      for(j = 0; j < FILE_WIDTH; j++){
	
	cout << setw(TEMP_SPACING) << array2D[i][j] << " ";
      }
      cout << "\n";
    }
  }
}

/****************************************************************/
void modelTemps(string landCoverList[FILE_LENGTH][FILE_WIDTH] ,
	        double tempList[FILE_LENGTH][FILE_WIDTH]      ){
  double baseTemp;
  double multTemp;
  int i = 0 , j = 0;

  if(landCoverList[0][0] == EMPTY_STRING){
    cout << "Please load a file first." << endl;
  
  }else{
    // get valid base temp
    do{
      cout << "What is the base temperature? (-130 to 134)" << endl;
      cin >> baseTemp;
    }while(baseTemp < MIN_BASE_TEMP || baseTemp > MAX_BASE_TEMP);
    
    // calculate area temps, update tempList
    for(i = 0 ; i < FILE_LENGTH ; i++){
      for(j = 0 ; j < FILE_WIDTH ; j++){
	
	// multiplies base temperature by area multiplier
	if(landCoverList[i][j] == "R"){
	  tempList[i][j] = double(baseTemp * R);
	}else if(landCoverList[i][j] == "S"){
	  tempList[i][j] = double(baseTemp * S);
	}else if(landCoverList[i][j] == "C"){
	  tempList[i][j] = double(baseTemp * C);
	}else if(landCoverList[i][j] == "U"){
	  tempList[i][j] = double(baseTemp * U);
	}else if(landCoverList[i][j] == "D"){
	  tempList[i][j] = double(baseTemp * D);
	}else if(landCoverList[i][j] == "P"){
	  tempList[i][j] = double(baseTemp * P);
	}else if(landCoverList[i][j] == "F"){
	  tempList[i][j] = double(baseTemp * F);
	}	
      }
    }   
  }
}
