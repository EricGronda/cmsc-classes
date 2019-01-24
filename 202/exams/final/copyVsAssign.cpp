#include <iostream>
#include <cstdlib>
//#include <time>
#include <vector>
using namespace std;

class foo{
public:
  foo(){ cout << "Default" << endl; }
  foo( const foo& ){ cout << "Copy" << endl; }
  foo& operator= (const foo&){ cout << "Assign" << endl; }
  foo& operator() (const foo&){ cout << "copy not construct" << endl; };
};

int main(){
  foo a;
  foo b = a;
  foo c(b);
  a(c);
  b = c;

  foo* d = new foo();
  delete d;

  srand(time(NULL));
  int e = rand() % 9999999 + 1;
  vector<foo*> foos;

  while(e != 9999999){
    for(int i = 0; i < 10; i++){
      foo* newfoo = new foo();
      foos.push_back( newfoo );
    }
  }

  return 0;
}
