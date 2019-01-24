#include <iostream>
#include <string>
using namespace std;

void fun(int arrLength , int array[]);

int main(){
  int arrLength = 10;
  int arry[10] = {1,2,3,4};

  cout << "Before fun: " << arry[4] << "; and length: " << arrLength << endl;

  fun(arrLength , arry);

  cout << "First Num:" << arry[4] << "; Second Num:" << arrLength << endl;


  return 0;
}

void fun(int arrLength , int arry[]){
  arry[4] = 32;
  arrLength = 9;
  
}
