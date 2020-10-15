// File: CrossFunctionAccess.cc

#include <iostream>
#include <cstring>
#include "hexdump.hpp"

using namespace std;

void function2() {
  unsigned char function2_data[] = "!Doing!";
  int size = sizeof(function2_data);

  cout << "Address of function2_data: " << &function2_data << endl;
  cout << Hexdump(function2_data, size) << endl;
  //cout << /* try to print value of function1_data here */
}

void function1() {
  char function1_data[] = "Learn by";
  cout << "Address of function1_data: " << &function1_data << endl;
  function2();
}

int main() {
  cout << endl << "Let's Learn by Doing!" << endl;

  int stack_variable;
  cout << "Address of stack variable: " << &stack_variable << endl;

  function1();
}

