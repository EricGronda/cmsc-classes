/***************************************************************
 * File:    MailHouse.cpp
 * Author:  Eric Gronda
 * Date:    4/24/18
 * Section: 04
 * Description:
 *    Controls the main operations for PROJ4: UMBC Shipping
 **************************************************************/

#include "MailHouse.h"

// Constructor
// Preconditions: None
// Postconditions: None
MailHouse::MailHouse(){
}

// loadMail(char*) - loads the file and sets any data from the file
// Preconditions: a valid filepath
// Postconditions: Loads m_mail. Returns int for status (1 - success, 0 - fail)
int MailHouse::loadMail(char* filename){
  Carrier *UpsPtr   = new Ups;
  Carrier *FedExPtr = new FedEx;
  ifstream ifp;
  ifp.open(filename);

  // verify that the file is open
  if(!ifp.is_open())
    return 0;

  // carrier data
  int   max_capacity;
  float speed;

  // max capacity
  ifp >> max_capacity; //ups
  UpsPtr->setMaxCapacity(max_capacity);
  ifp >> max_capacity; //fedex
  FedExPtr->setMaxCapacity(max_capacity);

  // speed
  ifp >> speed; 
  UpsPtr->setRate(speed);
  ifp >> speed;
  FedExPtr->setRate(speed);

  // load into vector
  m_carriers.push_back(UpsPtr);
  m_carriers.push_back(FedExPtr);
  
  // load m_mail
  float baseCostLetter , baseCostPackage;
  string temp;
  carrierType carrier;
  mailType mail;
  string sender , receiver;
  float size;
  
  // get base costs
  ifp >> baseCostLetter >> baseCostPackage;
  getline(ifp , temp);

  // get mail until end of file
  while( getline(ifp , temp , ',') ){
    // convert int to carrierType
    if(temp == "0")
      carrier = UPS;
    else if(temp == "1")
      carrier = FEDEX;
    else
      carrier = TOTAL_CARRIERS;

    // get mailType
    getline(ifp , temp , ',');
    if(temp == "0")
      mail = LETTER;
    else if(temp == "1")
      mail = PACKAGE;

    // sender, receiver , size
    getline(ifp , sender , ',');    
    getline(ifp , receiver , ',');
    ifp >> size;
        
    // clear \n
    getline(ifp , temp);

    // make new mail object
    Mail* newMail;
    if(mail == LETTER){
      newMail = new Letter(carrier , sender , 
			   receiver , size , baseCostLetter);
    }else if(mail == PACKAGE){
      newMail = new Package(carrier , sender , 
			    receiver , size , baseCostPackage);
    }else{
      return 0;
    }

    // add object to vector
    m_mail.push_back(newMail);
  }

  // POSTCONDITIONS
  ifp.close();
  return 1;

}

// fillCarriers() - Loads the carrier vectors from the m_mail vectors
// Preconditions: m_mail is populated. m_carriers is populated
// Postconditions: m_carriers have mail in their respective vectors.
// Returns int for status (1 - success, 0 - fail)
int MailHouse::fillCarriers(){
  bool fail = false;
  bool failMail = false;

  // loop through m_mail with boolean flags
  for(unsigned int i = 0; i < m_mail.size(); i++){

    // if not a ups or fedex, then fail
    if((carrierType)(m_mail.at(i)->getCarrier()) == TOTAL_CARRIERS ){
      failMail = true;
    }
  }
  
  // fail due to bad mail
  if( failMail ){
    for(unsigned int j = 0; j < m_mail.size(); j++){
      delete m_mail.at(j);
      m_mail.at(j) = NULL;
    }
    
    return 0;
  }

  // loop through mail and add to carriers
  for(unsigned int i = 0; i < m_mail.size(); i++){
    // put mail in ups
    if( (carrierType)((m_mail.at(i))->getCarrier()) == UPS ){
      if( ((m_carriers.at(0))->insert(m_mail.at(i))) == 1 ){
	
	// clear bad mail and fail
	delete m_mail.at(i);
	m_mail.at(i) = NULL;
	fail = true;
      }
    }
    // put mail in fedex
    else if( (carrierType)((m_mail.at(i))->getCarrier()) == FEDEX ){
      if( ((m_carriers.at(1))->insert(m_mail.at(i))) == 1 ){
	
	// clear bad mail and fail
	delete m_mail.at(i);
	m_mail.at(i) = NULL;
	fail = true;
      }
    }
  }

  // if there is a need to fail
  if( fail ){
    // get rid of unwanted data
    for(unsigned int i = 0; i < m_carriers.size(); i++){
      delete (m_carriers.at(i));
      (m_carriers.at(i)) = NULL;
    }
    
    return 0;
  }

  else{
    // display contents
    for(unsigned int i = 0; i < m_carriers.size(); i++){
      cout << *(m_carriers.at(i)) << endl;;
    }
    
    return 1;
  }

}

// deliverMail() - Send carriers out for delivery
// Preconditions: m_carriers are populated
// Postconditions: m_carriers have cleared their vectors.
// Returns int for status (1 - success, 0 - fail)
int MailHouse::deliverMail(){

  for(unsigned int i = 0; i < m_carriers.size(); i++){
    (m_carriers.at(i))->deliver();
  }
  
  return 1;
}

// cleanUp() - Any additional clean up is done here
// Preconditions: Allocated memory
// Postconditions: Deallocates any remaining allocations
int MailHouse::cleanUp(){

  for(unsigned int i = 0; i < m_carriers.size(); i++){
    delete m_carriers.at(i);
    m_carriers.at(i) = NULL;
  }

  return 1;
}
