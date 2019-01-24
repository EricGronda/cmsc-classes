#include <iostream>
#include <string>
using namespace std;

class Computer{
public:
  // accessors
  string GetMake();
  string GetModel();
  double GetMSRP();

  // mutators
  void SetMake(string);
  void SetModel(string);
  void SetMSRP(double);

private:
  string m_make;
  string m_model;
  double m_msrp;
};

int main(){
  Computer comp1;
  string make, model;
  double msrp;
  
  cout << "Enter the make of your computer: ";
  getline(cin, make);
  cout << "Enter the model of your computer: ";
  getline(cin, model);
  cout << "Enter the MSRP of your computer: ";
  cin >> msrp;

  comp1.SetMake(make);
  comp1.SetModel(model);
  comp1.SetMSRP(msrp);

  cout << "Your computer is a " << comp1.GetMake() << " " 
       << comp1.GetModel() << " and costs $" << comp1.GetMSRP() << endl;

  return 0;
}

// accessors
string Computer::GetMake(){
  return m_make;
}
string Computer::GetModel(){
  return m_model;
}
double Computer::GetMSRP(){
  return m_msrp;
}

// mutators
void Computer::SetMake(string make){
  m_make = make;
}
void Computer::SetModel(string model){
  m_model = model;
}
void Computer::SetMSRP(double msrp){
  m_msrp = msrp;
}
