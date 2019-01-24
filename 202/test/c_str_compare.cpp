#include <iostream>;
using namespace std;

int main(){
  char str1[] = "Hello there!";
  char str2[] = "Hello there!";
  
  if(str1 == str2)
    cout << str1 << endl;
  else
    cout << str1 << str2 << endl;

  return 0;

}
