# Push_swap
## Created a sorting algorithm following these specs:

### The game is composed of 2 stacks named a and b.
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

## Solution
To solve this problem I have created four different algorithms:
### solve three
This one is fairly easy, you determine the position of the biggest and smallest number. If you know on which position they are located inside the array you just swap them.
### solve five
This one builds on the earlier on the solve three. It pushes the biggest and smallest number to the B stack. After that it solves the A stack using solve three then it pushes from stack B the biggest to the top and the smallest to the bottom of stack A.
### solve 100
From here it start to become fun.

#### Batches
I'm using an algorithm which puts the numbers in the B stack in batches. I first determine the batch sizes, I solve a couple of stack with different stack sizes and check how much rotations it needs to solve it. As soon as I found one which is fairly efficient I use that batch size as the standard. For 100 I use a batch size of 5. So the stack which contains 100 numbers is putted in 5 groupes each with its own upper and lower limit.

#### Closest to upper of lower border
As soon as I know the batches I start pushing the smallest batch to the B stack. I determine the position of all the numbers which are part of this batch inside the A stack. After that I check which of those numbers is closest to the top or buttom of the A stack. 

#### Moving number up or down the stack
When I know which number is closest I start moving that number to the Top or Buttom of the stack. As soon as it gets there I push the number to the B stack. These steps continue until the entire stack is added to the B stack in batches. This way I know that all numbers which have to be pushed back in order are fairly close to eachother inside the B stack. 

#### Moving back to the A stack
The last step is pushing all these numbers back to the A stack. Again I calculate the distance from the highest number to the top or buttom and start pushing them back to A untill all numbers are sorted inside the A stack. 

### solve big stack which means more than 100
The bigstack is solved in nearly the same way as solve 100 the only difference is the batch size. I determine the batch size again and use this new batch size inside my logic. The perfect batch size for an array of 500 is around 13 batches.

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



