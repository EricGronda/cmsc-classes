/********************************************
 * absolute value using pointers
 *******************************************/

#include <iostream>
using namespace std;

void absoluteValue(int *ptr);

int main(){
  int input;
  int *inPtr = &input;
 
  cout << "Enter a number: " << endl;
  cin >> input;
  absoluteValue(inPtr);
  cout << "Abs val: " << input << endl;
  
  return 0;
}

void absoluteValue(int *ptr){
  if(*ptr >= 0){
    //*ptr = *ptr;
  }else{
    *ptr = -*ptr;
  }
}
