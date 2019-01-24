#include <iostream>
#include <string>
using namespace std;

void swapNum2(int *xPtr , int *yPtr);

int main(){
  int x;
  int *xPtr = &x;
  int y;
  int *yPtr = &y;
  
  cout << "Value of x:" << endl;
  cin >> x;
  cout << "Value of y:" << endl;
  cin >> y;

  cout << "Calling the function swapNum2" << endl;
  swapNum2(xPtr , yPtr);
  
  cout << "The values of x and y after swapNum2:" << endl;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;

  return 0;
}

void swapNum2(int *xPtr , int *yPtr){
  int temp;

  temp = *xPtr;
  *xPtr = *yPtr;
  *yPtr = temp;
}
