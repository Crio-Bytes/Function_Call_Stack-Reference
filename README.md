# Introduction

To Understand how the function call variables are represented and stored on the stack.

## Background
Process stack and heap are foundational concepts in computer science. Whenever a process runs, its memory is organized into a bunch of segments including heap and stack.

> Refer to the `Process_Memory_Layout` diagram in the repo folder `images`. 

## Stack
The stack area contains the program (function call) stack, a LIFO structure, typically located in the higher parts of memory. A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is "pushed" onto the stack. The set of values pushed for one function call is termed a "stack frame" or an “activation record”. A stack frame consists at minimum of a return address. Automatic/local variables are also allocated on the stack.

## Stack Frame / Activation Records
Each stack frame corresponds to a call to a subroutine which has not yet terminated with a return. For example, if a subroutine named DrawLine is currently running, having been called by a subroutine DrawSquare, the top part of the call stack might be laid out like in the below picture.
The stack frame at the top of the stack is for the currently executing routine (the stack pointer would be pointing here). The stack frame usually includes at least the following items (in push order):
- the arguments (parameter values) passed to the routine (if any);
- the return address back to the routine's caller (e.g. in the DrawLine stack frame, an address into DrawSquare's code); and
- space for the local variables of the routine (if any).

> Refer to the `Layout_Of_Activation_Record_In_Stack` diagram in the repo

The active frame is the function that is currently in execution. You will understand the Data section of an activation record in much higher detail as you go through the tasks. 

## Primary Goals
1. Understand the basic structure of a process stack (function call stack) and the way it gets used
2. Understand the layout of an activation record (stack frame)



# Prerequisites
You would need a Linux machine with sudo access.	
Have a g++ compiler to run simple cpp programs.
```
 g++ SampleProgram.cc -o SampleProgram
./SampleProgram
```
Understand how to run a process in the background and get its process id.

When you run a program with ‘&’ in the end, it runs as a background job and prints the process id.
You may have to periodically kill these processes you put in the background. Otherwise your system may become slow. If you run `ps` in the same terminal, you will be able to see the list of all processes. You can then kill the process either using pkill or kill commands.



# Activities

## Activity 1 - Can two variables access the same address?

Where do function variables get stored?
Start with a simple C++ program to understand how a process memory is typically laid out. Run the following program and get it’s process id.

> Refer to the file `FunctionCallStack.cc` in the repo

You would see something like this

> Refer to the `Activity1_Fig1` diagram in the repo

Now, check the proc maps output for this process to look at the stack and heap segment ranges.
To do this, you can pick up the process id shown after the function was executed (as seen above) or find the process id of the running FunctionCallStack process using the `ps` command. Then run `cat /proc/[process id]/maps`.

> Refer to the `Activity1_Fig2` diagram in the repo

Here you can see that Stack variables are between 0x7ffc9d60c000 - 0x7ffc9d60c000 and we can also see that -> 0x7ffc9d60c000 < 0x7ffc9d62b69c (function1_variable) > 0x7ffc9d60c000. 

This confirms that function variables are allocated within the stack. 

### References
- https://stackoverflow.com/questions/1401359/understanding-linux-proc-id-maps
- https://stackoverflow.com/questions/38557872/interpret-different-lines-of-the-proc-pid-maps-output


## Activity 2 - Body Double

Now let’s try adding another function call and see what happens. 

> Refer to the file `FunctionCallStackConsecutive.cc` in the repo

For the output:

> Refer to the `Activity1_Fig1` diagram in the repo

Did you see that? - function1 and function2 variables are pointing to the same memory location. 
What just happened here? Can you explain this? 

##### Hint
- function1() had already returned by the time function2() was invoked. Picture the stack.


## Activity 3 - Local static variables

Modify the program from the previous milestone to allocate a static variable within function1. Syntax as below 
```
static data_type var_name = var_value;
```
Print the address of var_name and find out the range that it is allocated to. 

### References

- https://unix.stackexchange.com/questions/476895/if-a-global-or-static-c-variable-is-not-explicitly-initialized-but-implicitly-i

### Further exploration

- Is there a difference between where an initialized static variable is stored vs an uninitialized static variable in the process memory map?
- How do different languages handle static variables?


## Activity 4 - Cross function access

Accessing variables from other functions. Can you do it?

Using the following program, can you try to access the value of function1_data from function2 (without passing it as a parameter to function2 of course :p)?

The `hexdhump.hpp` file can be downloaded from https://gitlab.crio.do/crio_bytes/me_ufcs/-/blob/master/hexdump.hpp. 
The Hexdump function can be used to print the values of addresses starting from a pointer till a specified range. 

Try printing the values of pointers near funtion2_data and see if you are able to access variables from other functions. 

> Refer to the file `CrossFunctionAccess.cc` in the repo

Output should look like this

> Refer to the `Activity4_Fig1` image in the repo


##### Hint
- Based on the direction of stack growth, try to print 50 or 100 bytes nearby and check the output of hexdump to see if you can access other variables.
- If you are still stuck try adding "+200" into the size variable and check your output to see if function1_data is available.
- I figured out that I had to print this (to see the function1_data) based on the above experiments - "Hexdump(function2_data + 47, 8)". It may be a bit different for you, play around.


## Activity 5 - Mess with function params

Can you access the function parameter value without using the argument variable?

Try to figure out how to print the function parameter value without using the variable that was passed directly.
If you try to print the hexdump similar to the previous task, you can see that the function parameter value is not visible. 
Do you need to print the bytes from the previous addresses? Visualize the stack.

> Start with the `MessWithFunctions.cc` file in the repo


##### Hint
- Try to print the address of function1_argument and function1_variable and see if you are able to find a relation between the two.
- Since function1_variable is an integer of 2 bytes, you have to move 2 locations backwards and you would be able to get a pointer to the function1_argument integer.
- Try to print this reinterpret_cast<int>(&function1_variable - 2)


# Summary

You are now confident (probably more than the people who designed it ;)) that local variables and function arguments are stored in the stack within each function’s stack frame/activation record. 
 

# References
https://learn.crio.do/home/me/ME_UFCS/
