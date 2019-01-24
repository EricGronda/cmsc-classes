/***************************************************************
 * File:    StarWars.cpp
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    Contains function definitions for StarWars class
 *    in PROJ5: Star Wars
 **************************************************************/
#include "StarWars.h"

// Name: StarWars (Default Constructor)
// Preconditions: None
// Postconditions: Creates a new Star War object
StarWars::StarWars(){}

// Name: ~StarWars (Destructor)
// Preconditions: None
// Postconditions: Destructs Star War object
StarWars::~StarWars(){
  // delete objects in imperial and rebel vectors
  for(unsigned int i = 0; i < m_imperialShips.size(); i++){
    delete m_imperialShips.at(i);
    m_imperialShips.at(i) = NULL;
  }

  for(unsigned int i = 0; i < m_rebelShips.size(); i++){
    delete m_rebelShips.at(i);
    m_rebelShips.at(i) = NULL;
  }

}

// Name: loadShips
// Preconditions: Two files (imperial ships then rebel ships) passed in array
// Postconditions: Populates m_imperialShips and m_rebelShips (returns 1 on success)
bool StarWars::loadShips(char* files[]){
  ifstream ifp;

  // data variables
  string name;
  string type;
  int attack;
  int defense;
  string temp;

  // iterate over 2 files
  for(int i = 0; i < 2; i++){
    
    // validate file is open
    ifp.open(files[i]);
    if(!ifp.is_open())
      return false;

    // get data
    while( getline(ifp , name , ',') ){
      getline(ifp , type , ',');
      getline(ifp , temp , ',');
      attack = atoi(temp.c_str());
      getline(ifp , temp , '\n');
      defense = atoi(temp.c_str());

      Ship* newShip;
      
      /******* HELP ME MAKE A SHIP PLZZZZ *******/

      // imperial ship
      if(i == 0){
	newShip = new Imperial(name , type , attack , defense);
	m_imperialShips.push_back(newShip);
      }

      // rebel ship
      else if(i == 1){
	newShip = new Rebel(name , type , attack , defense);
	m_rebelShips.push_back(newShip);
      }
    }

    ifp.close();
  }

  return true;
}

// Name: Start
// Desc: Manages the game (loadsShips, requests team size, createsTeams, and Battles)
// Preconditions: Two files (imperial ships then rebel ships) passed in array
// Postconditions: None (game ends when it ends)
void StarWars::Start(char* files[]){
  
  // load ships
  if(!loadShips(files)){
    cout << "Ships were not able to load" << endl;
    return;
  }else{
    cout << "Ships loaded" << endl;
  }

  // request team size
  int teamSize;
  cout << "How many ships would you like on a team?" << endl;
  cin >> teamSize;
  
  // validate
  while(teamSize > (int)m_imperialShips.size() || 
	teamSize > (int)m_rebelShips.size()    ||
	teamSize < 0 ){
    cout << "Invalid team size. Please enter a number between 0 and ";
    
    if(m_imperialShips.size() > m_rebelShips.size())
      cout << m_rebelShips.size() << endl;
    else
      cout << m_imperialShips.size() << endl;

    cin >> teamSize;
  }

  // no ships case
  if(teamSize == 0){
    cout << "No ships to battle. Exiting." << endl;
    return;
  }

  // create teams
  createTeams(teamSize);

  // battle
  battle();

}

// Name: createTeams
// Desc: Populates two Tqueues of ships randomly
//        Tqueue m_myShips is populated from m_rebelShips (enqueue)
//        Tqueue m_imperialShips is populated from m_imperialShips (enqueue)
// Preconditions: None
// Postconditions: Teams created
void StarWars::createTeams(int numShips){
  srand(time(NULL));
  int myIndex; 
  int enemyIndex; 
  vector<int> myUsed; // make sure none of the indexes overlap
  vector<int> enemyUsed;
  bool badIndex;

  // populate teams
  for(int i = 0; i < numShips; i++){
    
    // validate my new index
    do{
      badIndex = false;
      myIndex = rand() % m_rebelShips.size();

      for(unsigned int j = 0; j < myUsed.size(); j++){
	if(myIndex == myUsed.at(j))
	  badIndex = true;
	else
	  myUsed.push_back(myIndex);
      }

    }while(badIndex);

    // validate enemy new index
    do{
      badIndex = false;
      enemyIndex = rand() % m_imperialShips.size();

      for(unsigned int j = 0; j < enemyUsed.size(); j++){
	if(enemyIndex == enemyUsed.at(j))
	  badIndex = true;
	else
	  enemyUsed.push_back(enemyIndex);
      }

    }while(badIndex);
    
    // add ships to queues
    m_myShips.enqueue( m_rebelShips.at(myIndex) );
    m_enemyShips.enqueue( m_imperialShips.at(enemyIndex) );
  }

}

// Name: battle
// Desc: Manages the battles (random team starts
//       Front of Tqueue attacks front of second Tqueue
//       If a member is destroyed, dequeued from Tqueue
//       Alternate turns and repeat until one of the Tqueues is empty
//       Note: If a ship is destroyed, it does not attack
// Preconditions: Two Tqueues of ships are populated
// Postconditions: A winner must be displayed
void StarWars::battle(){
  
  cout << "The battle begins..." << endl;

  // pick a random team to start
  srand(time(NULL));

  // imperials go first
  if( rand() % 2 == 0 ){
    
    // go until no ships left on at least one team
    while(m_enemyShips.size() > 0 && m_myShips.size() > 0){

      // imperials start
      while( m_enemyShips.size() > 0 && m_myShips.size() > 0 &&
	     m_enemyShips.queueFront()->attack(m_myShips.queueFront())){

	// as long as the imperials keep destroying, they continue to attack
	m_myShips.dequeue(); 
      }

      // rebel start
      while( m_myShips.size() > 0 && m_enemyShips.size() > 0 &&
	     m_myShips.queueFront()->attack(m_enemyShips.queueFront())){

	// as long as the rebels keep destroying, they continue to attack
	m_enemyShips.dequeue();
      }
    }
  }

  // rebels go first
  else{

    // go until no ships left on at least one team
    while(m_enemyShips.size() > 0 && m_myShips.size() > 0){

      // rebel start
      while( m_myShips.size() > 0 && m_enemyShips.size() > 0 &&
	     m_myShips.queueFront()->attack(m_enemyShips.queueFront())){

	// as long as the rebels keep destroying, they continue to attack
	m_enemyShips.dequeue();
      }

      // imperials start
      while( m_enemyShips.size() > 0 && m_myShips.size() > 0 &&
	     m_enemyShips.queueFront()->attack(m_myShips.queueFront())){

	// as long as the imperials keep destroying, they continue to attack
	m_myShips.dequeue(); 
      }

    }
  }

  // check who wins
  if( m_myShips.size() > m_enemyShips.size() )
    cout << "You win!!!" << endl;
  else if(m_myShips.size() == m_enemyShips.size())
    cout << "You tied!" << endl;
  else
    cout << "You lose..." << endl;
}

