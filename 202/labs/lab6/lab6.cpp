#include "Produce.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

// fill vector - fills produce info
// vector<Produce>& - produce in your grocery list
void fillVector(vector<Produce>&);

// printVectorWithIterator - prints the information 
// of all produce using unsigned int
void printVectorWithIterator(vector<Produce>&);

// printVectorWithoutIterator - prints the information 
// of all produce using the ::iterator
void printVectorWithoutIterator(vector<Produce>&);

int main () {
  //Creates a new vector of produce for your grocery list
  vector<Produce> myGroceryList;

  //Populates the vector
  fillVector(myGroceryList);

  cout << "Grocery List using unsigned int: " << endl;
  // Prints the contents of the vector using unsigned int
  printVectorWithoutIterator(myGroceryList);  

  cout << "\n";
  cout  << "Grocery List using the ::iterator:" << endl;
  // Prints the contents of the vector using ::iterator 
  printVectorWithIterator(myGroceryList);
  
  return 0;
}

void fillVector(vector<Produce>& newGroceryList) {
  int numItems;
  string produceName;
  double price;
  int barcode;
  Produce food;

  //Write this function
  //Needs to ask how many items/produce
  cout << "How many items in your gorcery list?" << endl;
  cin >> numItems;
  //Gets produce name, price, and barcode of the item
  for(int i = 0; i < numItems; i++){
    cout << "Produce " << i + 1 << " name: ";
    cin >> produceName;
    cout << "Produce " << i + 1 << " price: ";
    cin >> price;
    cout << "Produce " << i + 1 << " barcode: ";
    cin >> barcode;

    food.SetProduceName(produceName);
    food.SetPrice(price);
    food.SetBarcode(barcode);
  

    //Needs to add produce to the vector
    newGroceryList.push_back(food);
  }
}

void printVectorWithoutIterator(vector<Produce>& newGroceryList){
  // Print out the vector using unsigned int
  for(unsigned int i = 0; i < newGroceryList.size(); i++){
    cout << newGroceryList.at(i).GetProduceName() << " $" 
	 << newGroceryList.at(i).GetPrice() << " "
	 << newGroceryList.at(i).GetBarcode() << endl;
  }

}
void printVectorWithIterator(vector<Produce>& newGroceryList){
  // Print out the vector using ::iterator
  for(vector<Produce>::iterator it = newGroceryList.begin();
      it != newGroceryList.end(); it++){
    cout << (*it).GetProduceName() << " $" 
	 << (*it).GetPrice() << " "
	 << (*it).GetBarcode() << endl;
  }
}

