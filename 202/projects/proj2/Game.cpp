/******************************************************
 * File:    Game.cpp
 * Author:  Eric Gronda
 * Date:    3/27/18
 * Section: 04
 * E-mail:  eric.gronda@umbc.edu
 * Description:
 *     Contains all of the function definitions for
 *     Game class in Project 2: Dragon Wars
 *****************************************************/
#include "Game.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int QUIT = 5; // used in main menu

const int DISPLAY_HEADER1 = 29; // used in display formatting
const int DISPLAY_HEADER2 = 10;
const int DISPLAY_NUM     = 3;
const int DISPLAY_NAME    = 25;
const int DISPLAY_TYPE    = 11;
const int DISPLAY_CURSIZE = 13;
const int DISPLAY_MAXSIZE = 9;

const int MIN_RARITY = 1; // rarities used in searchEgg()
const int MAX_RARITY = 10;
const int MIN_CHANCE = 100 - (MAX_RARITY * 9); // chance to find egg
const int MAX_CHANCE = 100 - (MIN_RARITY * 9);

const string RUN_AWAY = "n"; // input validation in attack()
const string FIGHT    = "y";
const int NUM_SIZES   = 5;

//Name: Game() Default Constructor
// Desc - Builds a new game by:
// 1. Asking user for their name,
// 2. Loading all dragons from file (function call)
// Preconditions - None
// Postconditions - m_dragons is populated
Game::Game(){
  cout << "Welcome to Dragon Wars!" << endl;
  cout << "What is your name?" << endl;
  getline(cin , m_name);

  // load dragons from file
  LoadDragons();
}

// Name: LoadDragons
// Desc - Loads each dragon into m_dragon from file
// Preconditions - Requires file with valid dragon data
// Postconditions - m_dragons is populated with Dragon objects
void Game::LoadDragons(){
  ifstream ifp;
  string name , type , temp; // temp is a temporary location
  int maxSize , rarity;

  ifp.open( PROJ2_DRAGONS.c_str() );
  if(ifp.is_open()){

    // get data
    while( getline(ifp , name , ',') ){
      getline(ifp , type , ',');
      getline(ifp , temp , ',');
      maxSize = atoi(temp.c_str());
      ifp >> temp;
      rarity = atoi(temp.c_str());
      
      getline(ifp , temp); // get rid of escape sequences

      // add to dragon vector
      m_dragons.push_back( Dragon(name , type , false , small , 
				  (dragonSize)maxSize , rarity) );

    }    
    ifp.close();
  }
}

// Name: SearchEgg
// Desc - Randomly chooses an egg and adds to players dragon vector
// Preconditions - m_dragons is populated
// Postconditions - m_myDragons is populated
void Game::SearchEgg(){
  int rarity, chance, index; 

  // prompt rarity
  cout << "What rarity egg would you like to search for?" << endl;
  do{
    cout << "Enter a rarity (1 = very common and 10 = very rare):" << endl;
    cin >> rarity;
  }while(rarity < MIN_RARITY || rarity > MAX_RARITY);

  // random chance to find egg
  srand(time(NULL)); // RNG
  chance = 100 - (rarity * 9);
  if( rand() % MAX_CHANCE + MIN_CHANCE < chance){

    // pick random dragon
    do{
      index = rand() % m_dragons.size();
    }while(m_dragons.at(index).GetRarity() != rarity);
    m_myDragons.push_back(m_dragons.at(index));

    cout << "You have found a " 
	 << m_myDragons.at(m_myDragons.size() - 1).GetName() 
	 << " egg!" << endl;

  }else{
    cout << "Sorry, you did not find an egg of that rarity." << endl;
  }
}

// Name: HatchEgg
// Desc - Tries to change from egg to small dragon
// Preconditions - m_dragons is populated
// Postconditions - m_myDragons is populated
void Game::HatchEgg(){
  int numDragons, userVal, index;
  
  numDragons = m_myDragons.size(); // creates a signed int
  DisplayMyDragons();

  // get valid input
  do{
  cout << "Which dragon would you like to try and hatch?" << endl;
  cin >> userVal;
  }while(userVal < 1 || userVal > numDragons);

  // 50% chance to hatch
  srand(time(NULL));
  index = userVal - 1;

  if(rand() % 2 < 1 && m_myDragons.at(index).GetIsHatched() == false){
    cout << "Your " << m_myDragons.at(index).GetName()
	 << " egg hatches into a dragon!" << endl;
    m_myDragons.at(index).HatchDragon();

  }else{
    cout << "The dragon did not hatch or is already hatched." << endl;
  }
}

// Name: StartGame()
// Desc - Manages the game itself including win conditions continually
//         calling the main menu
// Preconditions - Player has an egg or a dragon
// Postconditions - Continually checks to see if player has an egg or a dragon
void Game::StartGame(){
  int userVal;
  bool hasDragon;

  do{  
    cout << "\n";
    userVal = MainMenu(); // need to prevent using other menus if not ready

    // choose menu
    switch(userVal){
      // SearchEgg
    case 1:
      cout << "\n";
      SearchEgg();
      break;

      // HatchEgg
    case 2:
      cout << "\n";
      if(m_myDragons.size() > 0)
	HatchEgg();
      else
	cout << "You must have an egg or a dragon first." << endl;
      break;

      // DisplayMyDragons
    case 3:
      cout << "\n";
      if(m_myDragons.size() > 0)
	DisplayMyDragons();
      else
	cout << "You must have an egg or a dragon first." << endl;
      break;

      // Attack
    case 4:
      cout << "\n";
      if(m_myDragons.size() > 0){
	hasDragon = false;
	for(unsigned int i = 0; i < m_myDragons.size(); i++){
	  if(m_myDragons.at(i).GetIsHatched() == true)
	    hasDragon = true;
	}
	if(hasDragon == true)
	  Attack();
	else
	  cout << "You must hatch an egg into a dragon first." << endl;
      }
      else
	cout << "You must have an egg or a dragon first." << endl;
      break;

      // Quit
    default:
      break;
    }

  }while(userVal != QUIT);

  cout << "\nThank you for playing Dragon Wars!" << endl;
}

// Name: DisplayMyDragons()
// Desc - Displays the current dragons (both hatched and unhatched)
// Preconditions - Player has dragons (either hatched or unhatched)
// Postconditions - Displays a numbered list of dragons
void Game::DisplayMyDragons(){
  string eggDragon;

  // header
  cout << "*********************************************" << endl;
  cout << m_name << "'s Dragons" << endl;
  cout << setw(DISPLAY_HEADER1) << "Name" << " " 
       << setw(DISPLAY_HEADER2) << "Type" << " " << "Egg/Dragon" 
       << " " << "Current Size" << " " << "Max Size" << endl; 
 
  // dragon data
  for(unsigned int i = 0; i < m_myDragons.size(); i++){
    if(m_myDragons.at(i).GetIsHatched() == false){
      eggDragon = "egg";
    }else{
      eggDragon = "dragon";
    }
    
    cout << setw(DISPLAY_NUM)     << (i + 1) << "." 
	 << setw(DISPLAY_NAME)    << m_myDragons.at(i).GetName()
	 << setw(DISPLAY_TYPE)    << m_myDragons.at(i).GetType()
	 << setw(DISPLAY_TYPE)    << eggDragon
	 << setw(DISPLAY_CURSIZE) << m_myDragons.at(i).GetCurSize()
	 << setw(DISPLAY_MAXSIZE) << m_myDragons.at(i).GetMaxSize()
	 << endl;

  }
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - Player has a dragon (either hatched or unhatched)
// Postconditions - Returns number indicating exit
int Game::MainMenu(){
  int userVal;

  // validate input
  while(userVal < 1 || userVal > QUIT){
    // display menu
    cout << "What would you like to do?" << endl;
    cout << "1. Search for an egg" << endl;
    cout << "2. Try to hatch an egg" << endl;
    cout << "3. Display all dragons and eggs" << endl;
    cout << "4. Attack!" << endl;
    cout << "5. Quit" << endl;
    cin >> userVal;    
  }
  return userVal;
}

// Name: Attack()
// Desc - Manages the dragons attacking each other
// FYI: remove element at front of a vector is m_vectorName.erase(m_vectorName.begin());
// Preconditions - Player has hatched dragons
// Postconditions - Player attacks a random dragon of random size
void Game::Attack(){
  int enemyIndex, playerIndex;
  int playerDragons = m_myDragons.size();
  string flee;
  bool life;

  // randomly choose enemy dragon
  // must be random size under max size
  srand(time(NULL));
  enemyIndex = rand() % m_dragons.size();

  cout << "You found a " << m_dragons.at(enemyIndex).GetName()
  << " to fight!" << endl;
  
  // option to flee
  do{
    cout << "Do you want to fight it? (y/n)" << endl;
    cin >> flee;
  }while(flee != RUN_AWAY && flee != FIGHT);

  // fight the dragon
  if(flee == FIGHT){
    // pick dragon
    DisplayMyDragons();
    do{
      cout << "Which dragon would you like to fight with?" << endl;
      cin >> playerIndex;
      playerIndex -= 1;
    }while((playerIndex < 0 || playerIndex > playerDragons) ||
	   m_myDragons.at(playerIndex).GetIsHatched() == false);

    cout << "Your " << m_myDragons.at(playerIndex).GetName()
	 << " attacks the " << m_dragons.at(enemyIndex).GetName()
	 << endl;
    
    // compare
    life = m_myDragons.at(playerIndex)
      .AttackDragon(m_dragons.at(enemyIndex));
  }

  else{
    cout << "You fled the battle!" << endl;
  }

  if(life == true){
    // attempt to grow
    m_myDragons.at(playerIndex).AttemptGrow();
  }
  else{
    cout << "Your " << m_myDragons.at(playerIndex).GetName()
	 << " was defeated by the enemy " 
	 << m_dragons.at(enemyIndex).GetName() << endl;
    // remove dragon
    m_myDragons.erase(m_myDragons.begin() + playerIndex);
  }
}

// Name: DisplayAllDragons (Test Function)
// Desc - Used to test that all dragons were loaded into m_dragons correctly
// Preconditions - Requires file with valid dragon data
// Postconditions - m_dragons is displayed (all relevant data from m_dragons)
void Game::DisplayAllDragons(){
  string eggDragon;

  // header
  cout << "*********************************************" << endl;
  cout << m_name << "'s Dragons" << endl;
  cout << setw(DISPLAY_HEADER1) << "Name" << " " 
       << setw(DISPLAY_HEADER2) << "Type" << " " << "Egg/Dragon" 
       << " " << "Current Size" << " " << "Max Size" << endl; 
 
  // dragon data
  for(unsigned int i = 0; i < m_dragons.size(); i++){
    if(m_dragons.at(i).GetIsHatched() == false){
      eggDragon = "egg";
    }else{
      eggDragon = "dragon";
    }
    
    cout << setw(DISPLAY_NUM)     << (i + 1) << "." 
	 << setw(DISPLAY_NAME)    << m_dragons.at(i).GetName()
	 << setw(DISPLAY_TYPE)    << m_dragons.at(i).GetType()
	 << setw(DISPLAY_TYPE)    << eggDragon
	 << setw(DISPLAY_CURSIZE) << m_dragons.at(i).GetCurSize()
	 << setw(DISPLAY_MAXSIZE) << m_dragons.at(i).GetMaxSize()
	 << endl;
  }
}
