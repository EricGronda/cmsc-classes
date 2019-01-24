#include "Gemstone.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor should ask for user input and initialize array
Gemstone::Gemstone(){
  cout << "Enter amount of gemstones in your collection: ";
  cin >> m_num;
  m_ptr = new string[m_num];

  cout << "Enter the name of Gemstone:" << endl;
  for(int i = 0; i < m_num; i++){
    cout << "Gemstone name " << i + 1 << ": ";
    cin >> m_ptr[i];
    //    (*m_ptr).at(i) = new Gemstone;

    
  }
}
Gemstone::~Gemstone(){
  delete[] m_ptr;
  m_ptr = NULL;
}

// Go through dynamically allocated array
void Gemstone::Display(){
  cout << "\nDisplaying Gemstone Names:" << endl;
  for(int i = 0; i < m_num; i++){
    cout << "Gemstone name " << i + 1 << ": ";
    cout << m_ptr[i] << endl;
  }
}
  // number of gemstone in the collection
  //int m_num;
  // dynamically allocated array of gemstones
  //string *m_ptr;
