#include <iostream>
#include <string>
using namespace std;

double sum(double , double);
double sum(double , double , double);

int main(){
  cout << "The sum of 3.65 and 4.12 is: " << sum(3.65 , 4.12) << endl;
  cout << "The sum of 5.02, 6.33, and 7.89 is: "
       << sum(5.02 , 6.33 , 7.89) << endl;
}

double sum(double a, double b){
  return a + b;
}
double sum(double a, double b, double c){
  return a + b + c;
}

