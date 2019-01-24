/*Title: linked1.cpp
Author: CMSC 202
Date: 3/5/2018
Description: This is introducing linked lists in C++.
*/

#include <iostream>
using namespace std;

//Each node of the linked list holds at least one piece of data and
//at least one pointer (usually to the next node in the linked list)
struct Node {
  int info; //Data for the linked list
  Node *next; //Pointer to the next node of the linked list
};

class LinkedList{ //Linked list structure
public:
  LinkedList(); //Default constructor that builds an empty linked list
  void insert_begin(); //Function that inserts new nodes at the beginning of the linked list
  void display(); //Function that iterates over the linked list to display the contents
private:
  Node *m_head; //Pointer to the beginning of the linked list
  Node *m_tail; //Pointer to the end of the linked list
  int m_size; //Counter for the size of the linked list
};

LinkedList::LinkedList(){
  m_head = NULL; //Sets the pointer to point at nothing
  m_tail = NULL; //Sets the pointer to point at nothing
  m_size = 0; //Sets the size of the linked list to 0
}

void LinkedList::insert_begin(){
  Node *temp = new Node(); //Builds a new node
  if(m_head == NULL){ //Checks to see if the linked list is empty
    m_head = temp; //Inserts the first node to the linked list
    m_tail = temp; //Inserts the first node to the linked list
    m_size = 1; //Updates the size
    temp->info = 1; //Sets the value of the first node
    temp->next = NULL; //Sets the first node in the linked list to point to nothing
  }
  else{
    temp->next = m_head; //Because this is inserting in the beginning, 
                        //this sets the new node to point at the first node in the linked list
    m_head = temp; //After the new node is set to point to the first node, we then set the new node to be the beginning of the list
    temp->info = 1; //Sets the value of the new node
    m_size++; //Increments the size of the linked list
  }
}

void LinkedList::display(){
  if(m_size==0){ //Checks to see if the linked list is empty
    cout << "The linked list is empty" << endl; //Output if it is empty
  }
  else{
    Node *temp = m_head; //Creates a new pointer to iterate over list
    for(int i = 0; i < m_size; i++){ //Iterates to end of list
      cout << temp->info << "->"; //Outputs value in node
      temp = temp->next; //Moves to next node
    }
    cout << "END" << endl; //Indicates the end of the linked list
  }
}

int main () {
  LinkedList list1; //Creates a new, empty linked list
  list1.display(); //Outputs the linked list (empty)
  list1.insert_begin(); //Inserts a node (the first node!)
  list1.insert_begin(); //Inserts a node
  list1.display(); //Outputs the linked list (should have two nodes each with a value of 1)
  list1.insert_begin(); //Inserts a node
  list1.insert_begin(); //Inserts a node
  list1.display(); //Outputs the linked list (should have four nodes each with a value of 1)
  return 0;
}
