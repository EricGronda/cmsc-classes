#include <iostream>
using namespace std;
void myFunction( int counter){  
  if(counter == 0)    
    return;  
  else    {      
    cout<<"hello"<<counter<<endl;      
    myFunction(--counter);      
    cout<<counter<<endl;      
    return;    
  }
}
int main () {  
  myFunction(4);  
  return 0;
}
