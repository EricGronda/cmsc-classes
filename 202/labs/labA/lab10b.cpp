#include <iostream>
using namespace std;



//Use this to implement the templated class calculator
//The constructor should take in two "numbers" and then call displayResult
//displayResult should add, subtract, divide, and multiply each pair of numbers
//Implement the class calculator here:
template <class T>
class Calculator{
public:
  Calculator();
  Calculator(const T , const T);
  
  void displayResult();
  
private:
  T m_a;
  T m_b;

};

/*********************************************************************/

int main()
{
  Calculator<int> intCalc(2, 1);
  Calculator<float> floatCalc(2.4, 1.2);
  
  cout << "Int results:" << endl;
  intCalc.displayResult();
  
  cout << endl << "Float results:" << endl;
  floatCalc.displayResult();
  
  return 0;
}

/********************************************************************/

template <class T>
Calculator<T>::Calculator(){
}

template <class T>
Calculator<T>::Calculator(const T a , const T b){
  m_a = a;
  m_b = b;
}
  
template <class T>
void Calculator<T>::displayResult(){

  cout << "Numbers are:    " << m_a << " and " << m_b << endl;
  cout << "Addition is: :  " << m_a + m_b << endl;
  cout << "Subtraction is: " << m_a - m_b << endl;
  cout << "Product is:     " << m_a * m_b << endl;
  cout << "Division is:    " << m_a / m_b << endl;

}





