/***************************************************************
 * File:    Tqueue.cpp
 * Editor:  Eric Gronda
 * Date:    5/8/18
 * Section: 04
 * Description:
 *    defines a templated queue class for PROJ5: Star Wars
 **************************************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue.
  //If queue is at capacity, doubles size and copies everything starting at 0
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  //If queue is less than half capacity, halves capacity
  //and copies everything starting at 0
  void dequeue(); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Returns front item in queue (does not remove it)
  T& queueFront();    // Retrieve front (does not remove it)
  //Name: getBack()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_back
  int getBack();
  //Name: getFront()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_front
  int getFront();
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (not capacity but m_back - m_front)
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T>& operator=( const Tqueue<T> &y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
  //Name: displayTqueue (Test function)
  //Precondition: Existing Tqueue
  //Postcondition: Used to display all members in the Tqueue
  void displayTqueue();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
  int m_capacity; //Capacity of the queue
};

//**** Add class definition below ****

//Name: Tqueue - Default Constructor
//Precondition: None (Must be templated)
//Postcondition: Creates a queue using dynamic array
template <class T>
Tqueue<T>::Tqueue(){ //Default Constructor
  m_front = 0;
  m_back = 0;
  m_capacity = 1;
  m_data = new T[m_capacity];
}

//Name: Copy Constructor
//Precondition: Existing Tqueue
//Postcondition: Copies an existing Tqueue
template <class T>
Tqueue<T>::Tqueue( const Tqueue<T>& x ):
  m_front(x.m_front) , m_back(x.m_back) , m_capacity(x.m_capacity) {

  // make new array
  m_data = new T[m_capacity];

  // assign data
  for(int i = 0; i < size(); i++){
    m_data[i] = x.m_data[i];
  }

}

//Name: Destructor
//Precondition: Existing Tqueue
//Postcondition: Destructs existing Tqueue
template <class T>
Tqueue<T>::~Tqueue(){ //Destructor
  delete[] m_data;
  m_data = NULL;
}

//Name: enqueue
//Precondition: Existing Tqueue
//Postcondition: Adds item to back of queue.
//If queue is at capacity, doubles size and copies everything starting at 0
template <class T>
void Tqueue<T>::enqueue(T data){ //Adds item to queue (to back)
  T* temp;

  // protect from errors case
  if(m_capacity == 0)
    m_capacity += 1;

  // queue is full
  if(size() >= m_capacity){

    // make new array of double size
    temp = new T[m_capacity * 2];

    // copy data
    for(int i = 0; i < size(); i++){
      temp[i] = m_data[i];
    }

    // reassign array
    delete[] m_data;
    m_data = temp;

    // double capacity
    m_capacity *= 2;
  }

  // put in item
  m_data[size()] = data;

  // postconditions
  m_back += 1;

}

//Name: dequeue
//Precondition: Existing Tqueue
//Postcondition: Removes item from front of queue
//If queue is less than half capacity, halves capacity
//and copies everything starting at 0
template <class T>
void Tqueue<T>::dequeue(){ //Removes item from queue (from front)
  T* temp;

  // nothing in dequeue
  if(size() == 0){
    cout << "Invalid dequeue: nothing stored" << endl;
    return;
  }

  // queue is less than half capacity
  else if(size() <= m_capacity / 2)
    temp = new T[m_capacity / 2];

  // queue is more than half capacity
  else
    temp = new T[m_capacity];

  // copy data into temp (skip first one)
  for(int i = 1; i < size(); i++){
    temp[i - 1] = m_data[i];
  }

  // reassign arrays
  delete[] m_data;
  m_data = temp;


  // postconditions
  m_back -= 1;
  if(size() <= m_capacity / 2)
    m_capacity /= 2;

  // protect from errors case
  if(m_capacity == 0)
    m_capacity += 1;

}

//Name: queueFront
//Precondition: Existing Tqueue
//Postcondition: Returns front item in queue (does not remove it)
template <class T>
T& Tqueue<T>::queueFront(){    // Retrieve front (does not remove it)
  return m_data[m_front];
}

//Name: getBack()
//Precondition: Existing Tqueue
//Postcondition: Retrieve int of m_back
template <class T>
int Tqueue<T>::getBack(){
  return m_back;
}

//Name: getFront()
//Precondition: Existing Tqueue
//Postcondition: Retrieve int of m_front
template <class T>
int Tqueue<T>::getFront(){
  return m_front;
}

//Name: isEmpty
//Precondition: Existing Tqueue
//Postcondition: Returns 1 if queue is empty else 0
template <class T>
int Tqueue<T>::isEmpty(){ //Returns 1 if queue is empty else 0
  cout << "Tqueue<T>::isEmpty()" << endl;
  if(size() <= 0)
    return 1;
  else
    return 0;
}

//Name: size
//Precondition: Existing Tqueue
//Postcondition: Returns size of queue (not capacity but m_back - m_front)
template <class T>
int Tqueue<T>::size(){ //Returns size of queue
  return m_back - m_front;
}

//Name: Overloaded assignment operator
//Precondition: Existing Tqueue
//Postcondition: Sets one Tqueue to same as a second Tqueue using =
template <class T>
Tqueue<T>& Tqueue<T>::operator=( const Tqueue<T> &y){

  // if object is same
  if(this == &y)
    return *this;

  // set member variables
  m_front = y.m_front;
  m_back = y.m_back;
  m_capacity  = (y.m_capacity);

  // reassign m_data
  delete[] m_data;
  m_data = new T[m_capacity];
  for(int i = 0; i < size(); i++){
    m_data[i] = y.m_data[i];
  }

  return *this;
}

//Name: Overloaded [] operator
//Precondition: Existing Tqueue
//Postcondition: Returns object from Tqueue using []
template <class T>
T& Tqueue<T>::operator[] (int x){//Overloaded [] operator to pull data
  return m_data[x];
}

//Name: displayTqueue (Test function)
//Precondition: Existing Tqueue
//Postcondition: Used to display all members in the Tqueue
template <class T>
void Tqueue<T>::displayTqueue(){
  if(size() == 0){
    cout << "Nothing stored in Tqueue to display." << endl;
    return;
  }

  else{
    for(int i = 0; i < size() - 1; i++){
      cout << m_data[i] << " ";
    }
    cout << m_data[size() - 1] << endl;
  }
}



// This is the type of code you should test your Tqueue with
// Once you have coded all of the functions, compile just Tqueue and test it

int main () {
cout << "newQ" << endl;
  Tqueue<int> newQ;
  newQ.displayTqueue();
  newQ.enqueue(10);
  newQ.displayTqueue();
  newQ.enqueue(20);
  newQ.displayTqueue();
  newQ.enqueue(30);
  newQ.displayTqueue();


  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.enqueue(40);
  newQ.displayTqueue();

  newQ.enqueue(40);
  newQ.enqueue(50);
  newQ.displayTqueue();
  cout << "newQ2 using assignment operator" << endl;
  Tqueue<int> newQ2;
  newQ2 = newQ;
  newQ2.displayTqueue();
  cout << "newQ3 using copy constructor" << endl;
  Tqueue<int> newQ3(newQ2);
  newQ3.displayTqueue();
  cout << endl << "newQ after two dequeue" << endl;
  newQ.dequeue();
  newQ.dequeue();
  newQ.displayTqueue();
  cout << endl;
  cout << "newQ4 using copy with deletes" << endl;
  Tqueue<int> newQ4(newQ);
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  cout << "newQ4 dequeued 4 times" << endl;
  newQ4.displayTqueue();
  newQ3 = newQ4;
  newQ3.displayTqueue();

  Tqueue<int> newQ5;
  for(int i = 0;i<400;i++){
    newQ5.enqueue(i);
  }
  cout << "size()=" << newQ5.size() << endl;
  newQ5.displayTqueue();

  return 0;
}


#endif
