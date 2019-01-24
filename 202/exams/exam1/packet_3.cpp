#include <iostream>
using namespace std;

int divide(int a , int b = 2);

int main(){
  int num1 , num2;

  cout << "num1? ";
  cin >> num1;
  cout << "num2? ";
  cin >> num2;

  cout << "num1 / num2 = " << divide(num1 , num2) << endl;
  cout << "num1 / default = " << divide(num1) << endl;

  return 0;
}

int divide(int a , int b){
  return a / b;
}
