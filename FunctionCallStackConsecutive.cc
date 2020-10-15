// File: FunctionCallStackConsecutive.cc

#include <iostream>

using namespace std;

void function1() {
  int funtion1_variable;
  cout << "Address of function1 variable: " << &funtion1_variable << endl;
}

void function2() {
  int function2_variable;
  cout << "Address of function2 variable: " << &function2_variable << endl;
}

int main() {
  cout << endl << "Let's Learn by Doing!" << endl;

  int stack_variable;
  cout << "Address of stack variable: " << &stack_variable << endl;

  int *ptr_heap = new int;
  cout << "Address of heap: " << ptr_heap << endl;

  function1();
  function2();

  // Infinite loop to keep the process running for you to examine the procfs.
  while (1) {}
}

