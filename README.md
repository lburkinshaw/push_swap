# push_swap 🔃
## A sorting algorithm in C using two stacks and linked lists

A project created as part of my studies at Hive Helsinki.

This was my first experience working with sorting algorithms. The program sorts a set of integers using only two stacks and push_swap instructions, aiming for optimal sorting efficiency in terms of move count. 

To compile, run `make`. Run the program and enter the desired set of integers as arguments, e.g.: `./push_swap 45 12 -6 456 88888 -4565`. The program will sort the integers given as arguments in as short a number of steps as possible, printing the steps taken to the standard output.

### Allowed operations:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

### Goals:
Sort the integers in no more than the steps indicated below:
- 5 integers: 12 steps
- 100 integers: 700 steps
- 500 integers: 5500 steps
