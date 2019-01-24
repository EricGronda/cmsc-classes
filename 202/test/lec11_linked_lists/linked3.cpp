#include <iostream>
#include <string>
using namespace std;

struct Node{
public:
  string m_grocery; //Data in the node
  Node *m_next; //Pointer in the node
};

class LinkedList{
public:
  LinkedList(); //Default Constructor
  ~LinkedList(); //Destructor
  void insert_begin(string grocery);
  void display();

private:
  Node *m_head; //Front of our linked list
  Node *m_tail; //Back of our linked list
  int m_size; //Size of our linked list
};

LinkedList::LinkedList(){
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

LinkedList::~LinkedList(){
  Node *temp = m_head;
  while(m_head != NULL){
    temp = m_head->m_next;
    delete m_head;
    m_head = temp;
  }
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}

void LinkedList::insert_begin(string grocery){
  Node *temp = new Node();
  temp->m_grocery = grocery;
  m_size++;
  if(m_head == NULL){
    //If linked list is completely empty
    temp->m_next = NULL;
    m_tail = temp;
  }else{
    //If linked list has at least one node
    temp->m_next = m_head;
  }
  m_head = temp;
}

void LinkedList::display(){
  if(m_head == NULL){
    cout << "The Linked List is empty" << endl;
  }else{
    Node *temp = m_head;
    for(int i = 0; i < m_size; i++){
      cout << temp->m_grocery << "->";
      temp = temp->m_next;
    }
    cout << "END" << endl;
  }
}

int main () {
  LinkedList list1;
  list1.display();
  list1.insert_begin("eggs");
  list1.insert_begin("bread");
  list1.insert_begin("Ramen");
  list1.display();

  return 0;
}
