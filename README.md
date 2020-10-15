# Introduction

Understand how the function call variables are represented and stored on the stack.

## Background
Process stack and heap are foundational concepts in computer science. Whenever a process runs, its memory is organized into a bunch of segments including heap and stack.

> Refer to the Process_Memory_Layout diagram in the repo. 

## Stack
The stack area contains the program (function call) stack, a LIFO structure, typically located in the higher parts of memory. A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is "pushed" onto the stack. The set of values pushed for one function call is termed a "stack frame" or an “activation record”. A stack frame consists at minimum of a return address. Automatic/local variables are also allocated on the stack.

## Stack Frame / Activation Records
Each stack frame corresponds to a call to a subroutine which has not yet terminated with a return. For example, if a subroutine named DrawLine is currently running, having been called by a subroutine DrawSquare, the top part of the call stack might be laid out like in the below picture.
The stack frame at the top of the stack is for the currently executing routine (the stack pointer would be pointing here). The stack frame usually includes at least the following items (in push order):
- the arguments (parameter values) passed to the routine (if any);
- the return address back to the routine's caller (e.g. in the DrawLine stack frame, an address into DrawSquare's code); and
- space for the local variables of the routine (if any).

> Refer to the Layout_Of_Activation_Record_In_Stack diagram in the repo

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

When you run a program with ‘&’ in the end, it runs as a background job and prints the process id. In the above case, 226285 is the process id.
You may have to periodically kill these processes you put in the background. Otherwise your system may become slow. If you run `ps` in the same terminal, you will be able to see the list of all processes. You can then kill the process either using pkill or kill commands.






# Activities

## Activity 1
Where do function variables get stored?
Start with a simple C++ program to understand how a process memory is typically laid out. Run the following program and get it’s process id.

> Refer to the file FunctionCallStack.cc

You would see something like this

> Refer to the Activity1_Fig1 diagram in the repo

Now, check the proc maps output for this process to look at the stack and heap segment ranges.
To do this, you can pick up the process id shown after the function was executed (as seen above) or find the process id of the running FunctionCallStack process using the `ps` command. Then run `cat /proc/[process id]/maps`.

> Refer to the Activity1_Fig2 diagram in the repo

Here you can see that Stack variables are between 0x7ffc9d60c000 - 0x7ffc9d60c000 and we can also see that -> 0x7ffc9d60c000 < 0x7ffc9d62b69c (function1_variable) > 0x7ffc9d60c000. 

This confirms that function variables are allocated within the stack. 

### References
- https://stackoverflow.com/questions/1401359/understanding-linux-proc-id-maps
- https://stackoverflow.com/questions/38557872/interpret-different-lines-of-the-proc-pid-maps-output


## Activity 2


## Activity 3






# References
www.crio.do
