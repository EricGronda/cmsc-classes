#include <iostream>
using namespace std;

class MyBirthday {
public:
  int m_year;
  int m_month;
  int m_day;

};

int main() {
  MyBirthday happy;

  happy.m_year = 1999;
  happy.m_month = 07;
  happy.m_day = 07;

  cout << "Year:  " << happy.m_year << endl;
  cout << "Month: " << happy.m_month << endl;
  cout << "Day:   " << happy.m_day << endl;

  return 0;
}
