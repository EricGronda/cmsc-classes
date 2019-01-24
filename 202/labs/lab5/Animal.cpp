#include "Animal.h"

// getters
string Animal::GetSound(){
  return m_makeSound;
}
string Animal::GetName(){
  return m_name;
}
 
// setters
void Animal::SetSound(string sound){
  m_makeSound = sound;
}
void Animal::SetName(string name){
  m_name = name;
}

// other functions
void Animal::WhoAmI(){
  if(m_name == "" || m_makeSound == ""){
    cout << "I do not have a name or do not make a sound" << endl;
  }else{
    cout << "My name is " << m_name << " and I say " << m_makeSound << endl;
  }
}
