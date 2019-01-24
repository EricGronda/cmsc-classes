/********************************************
 * call by reference
 *******************************************/

#include <iostream>
using namespace std;

void myFxn(int& , int&);

int main(){
  int a = 0;
  int b = 6;

  cout << "The output is: ";
  for(int i = 0; i < 4; i++){
    myFxn(a , b);
    cout << a;

    if(i < 3){
      cout << ", ";
    }else{
      cout << "." << endl;
    }
    
  }
  return 0;
}

void myFxn(int& a , int& b){
  a = a + b;
}
