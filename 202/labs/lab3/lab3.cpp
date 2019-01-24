#include <iostream>
using namespace std;

// max number of elements in the array
const int NUMBER_OF_ELEMENTS = 25;

// Function prototypes - do not change!
void reverse(int data[] , int dataLen);

int main(){
  int arr[NUMBER_OF_ELEMENTS];
  int numElements = 0;
  int inputValue;
  int i = 0;

  /////////////////////////////////////////////////
  // CODE TO READ ELEMENTS OF ARRAY FRO KEYBOARD
  /////////////////////////////////////////////////
  do{
    cout << "Enter a number (-1 when done): ";
    cin >> inputValue;
    if(inputValue != -1){
      arr[numElements] = inputValue;
      numElements += 1;
    }
  }while(inputValue != -1);
  numElements -= 1;

  /////////////////////////////////////////////////
  // CODE TO PRINT ELEMENTS OF ARRAY GOES HERE
  /////////////////////////////////////////////////
  cout << "Contents of array: ";
  for(i = 0; i < numElements ; i++){
    cout << arr[i] << ", ";
  }
  cout << arr[numElements] << endl;

  ///////////////////////////////////////////////////
  // CALL TO reverse() GO HERE
  //////////////////////////////////////////////////
  reverse(arr , numElements);

  /////////////////////////////////////////////////
  // CODE TO PRINT ELEMENTS OF ARRAY GOES HERE
  /////////////////////////////////////////////////
  cout << "Reversed Array: ";
  for(i = 0; i < numElements ; i++){
    cout << arr[i] << ", ";
  }
  cout << arr[numElements] << endl;


  return 0;


}

void reverse(int data[] , int dataLen){
  
  ////////////////////////////////////////////////////////
  // CODE TO REVERSE THE ELEMENTS OF THE ARRAY GOES HERE
  ////////////////////////////////////////////////////////
  int tempNum;
  int tempNum2;

  for(int i = 0 ; i < (dataLen / 2) ; i++){
    tempNum = data[i];
    tempNum2 = data[dataLen - i];

    data[i] = tempNum2;
    data[dataLen - i] = tempNum;
  }
  
}
