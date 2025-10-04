# Overview

These files, 1 $\rightarrow$ 12, are meant to deepen my understanding of C++, and is meant to be read as if I were teaching someone else C++. The RK4 program is the culmination of this work

A quick overview of each file:

### [Hello World!](1_helloworld.cpp)

This is a standard set up page. Just making sure that C++ is working correctly with VSCode.

### [Datatypes](2_datatypes.cpp)

This goes over the basic datatypes and a few modifiers that go along with them, as well as the size of each type.

### [Input/Output](3_InputOutput.cpp)

This file will use basic inputs from the console and will output something to the console. In this case, a person's name. It also goes over the difference between cin and getline().

### [Control Flow](4_ControlFlow.cpp)

This goes over if statements, loops, and switches. It also gives examples of the various keywords relavant to Control Flow.

### [Functions](5_Functions.cpp)

Function prototypes, data types, and definitions are all demonstrated here. Overloading functions, pass by references, and recursion are all given here too.

### [Pointers](6_Pointers.cpp)

This one goes over what pointers are, and goes through an example of how you might use them. It also dynamically manages the memory.

### [Arrays, Vectors, and Memory](7_ArraysVectorsMemory.cpp)

At this point, I thought it best to demonstrate the differences between Vectors and Arrays, and then demonstrate dynamic memory allocation and deletion.

### [Classes](8_Classes.cpp)

Classes are very interesting, since we went over them extensively in CSE 210. Because of that, I decided to tackle classes at a much more basic level, just highlighting how one uses a class in C++.

### [Structs](9_Structs.cpp)

Structs were an object I didn't really understand, so I decided to make a program that highlighted the differences between the two.

### [OOP](10_OOP.cpp)

Object Oriented Programming is very powerful I've learned. Encapsulation, Polymorphism, Abstraction, and Inheritance are all shown here, and explained in this file

### [File Input/Output]()

This file uses a struct called student, and will output every student's information to a txt file. Then the txt file is read and outputted to the console

### [RK4 Gravity Sim](11_FileIO.cpp)

For this simulation, I made gravity about 15 billion times stronger, and used a numerical method called Runge-Kutta order 4 for solving ordinary differential equations. This file also outputs all the position data to a csv, and then a separate Julia file rreads that file and turns it into an animation.

[Software Demo Video](http://youtube.link.goes.here)

# Development Environment

The only tools I used for developing these programs were VSCode

I used C++, and a tiny, tiny amount of Julia for data visualization

# Useful Websites


- [cplusplus.com](https://cplusplus.com/doc/)
- [C++ Full Course for free ⚡️ ](https://www.youtube.com/watch?v=-TkoO8Z07hI)

# Future Work

- One thing that could be improved is a better Gravity sim method. RK4 is $O(n^{2})$, but there is another method called the Barnes-Hut algorithm that is $O(n \, log_{2}(n))$
- Another item that could be improved is to explain RK4 in more detail. 'A numerical method for solving ODEs' is pretty ambiguous.
- The last item that could be improved is to go more in depth between structs and classes
