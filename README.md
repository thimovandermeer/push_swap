# Push_swap
## Created a sorting algorithm following these specs:

### The game is composed of 2 stacks named a and b. • To start with:
* a contains a random number of either positive or negative numbers without any duplicates.
* b is empty
### The goal is to sort in ascending order numbers into stack a.
#### To do this you have the following operations at your disposal:
* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## How it works
Once you clone this repository you have a couple of make options:

### Make
This command compiles the two programs, checker and push_swap. After that you are able to manually put numbers in the push_swap program. After push_swap is done you can give the output to the checker program and this one will return true or false. True if the stack is sorted, false if it isn't. all makefiles are linked so if you make the main make file the two underlying makefiles are also called. A symbolic link is created to make sure that the programs are callable from the root folder.

### Make visualize100
The following to commands how ever are way more fun. make visualize100 executes a python script which visualizes the procress of the push_swap program. It generates 100 numbers and feeds it to the push_swap program. The python script shows the steps in the following way: 


https://user-images.githubusercontent.com/57872522/125064730-40725500-e0b1-11eb-904c-e1b3096b51d1.mov


### Make visualize500
Make visualize500 works in exactly the same way, the only difference is that the random input is 500 instead of 100. 

## file structure
### checker_srcs
In de checker_srcs all .c files related to the checker function are stored. They are separated in a include, obj, and src file. 
### lib
in the lib file we have the shared_srcs and the python script. The shared srcs are compiled individually so that the two main programs can use them 
### push_swap_srcs
In de checker_srcs all .c files related to the checker function are stored. They are separated in a include, obj, and src file. 
### benchmark
The benchmark script is used to check if your push_swap is giving the correct answer. It generates input data and gives the answer from the checker program. 
### Makefile
The Makefile contains different make options which are mentioned in the how it works part of this readme



