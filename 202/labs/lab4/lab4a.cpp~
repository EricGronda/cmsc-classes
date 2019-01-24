#include <iostream>
#include <string>
using namespace std;

void buyGems(int&);

int main(){
  int gems = 100;
  string userInput;
  
  cout << "You currently have " << gems << " gems" << endl;
  
  buyGems(gems);

  cout << "You now have " << gems << " gems." << endl;

  return 0;
}

void buyGems(int& gems){
  string userInput;
  int gemsToBuy;

  cout << "What would you like to do?" << endl;
  getline(cin , userInput);

  if(userInput == "Purchase gems"){
    cout << "How many gems would you like to purchase?" << endl;
    cin >> gemsToBuy;

    gems = gems + gemsToBuy;
  }


}
