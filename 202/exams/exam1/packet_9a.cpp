#include <iostream>
using namespace std;

int main(){
  int x = 3;
  x = 4;
  int* ptrX = &x;
  x = 5;
  cout << x << endl;
  cout << ptrX << endl;

  return 0;
}
