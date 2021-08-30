# sort_stack
study project \
We have two stacks A and B, A contains a random number of either positive or negative numbers without any duplicates; B is empty. \
The goal is to sort in ascending order numbers into stack A.\
To do this we have the following operations:\
sa : swap a - swap the first 2 elements at the top of stack a\
sb : swap b;\
ss : sa and sb at the same time.\
pa : push a - take the first element at the top of b and put it at the top of a\
pb : push b\
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.\
rb : rotate b\
rr : ra and rb at the same time.\
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.\
rrb : reverse rotate b\
rrr : rra and rrb at the same time.\

Project contains two programs: push_swap and checker.\
push_swap sorts stack A, checker helps to check result of push_swap\

For compile and test programs\
sh my_test.sh
