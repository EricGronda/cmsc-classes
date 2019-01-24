#include <iostream>
using namespace std;

int main(){
  int a = 1;
  int b = 2;
  int *p = &a;
  int *q = &b;
  p = q;
  *p = 3;

  cout << a << " " << b << endl;

  return 0;
}
