#include <iostream>
#include <string>
using namespace std;

int main(){
  string teams[] = {"orioles" , "ravens" , "retrievers"};
  for(int i = 2; i >= 0; i--){
    cout << teams[i] << endl;
  }

  return 0;
}
