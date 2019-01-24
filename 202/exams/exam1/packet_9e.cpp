#include <iostream>
using namespace std;

int main(){
  int sum , num;
  
  sum = 0;
  cout << "Enter num: " << endl;
  cin >> num;
  for(int j = 1; j <= 4; j++){
    sum = sum + num;
    cout << "Enter num: " << endl;
    cin >> num;
  }
  cout << "Sum: " << sum << endl;

  return 0;
}
