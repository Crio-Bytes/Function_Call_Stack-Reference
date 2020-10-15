// File: MessWithFunctions.cc

#include <iostream>
using namespace std;

void function1(int function1_argument) {
  int function1_variable = 5;
  cout << "Address of function1_variable: " << &function1_variable << endl;
  cout << "Address of function1_argument: " << &function1_argument << endl;
  //cout << "Value of function1_argument: " << /* TODO: fill in here  */ << endl;
}

int main() {
  cout << endl << "Let's Learn by Doing!" << endl;
  int input = 2;
  function1(input);
}

