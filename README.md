# push_swap

Push_swap is a sorting interger program that use 2 stack and a limited amount operations.
We receive the list of integers as arguments of the `push_swap` program as follows : `./push_swap 4 3 6`
The list is sent to the `stack A`, the `stack B` empty at start.

The permitted operations are :

| Names | Behaviour |
| --- | --- |
| sa | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements) |
| sb | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements) |
| ss | sa and sb at the same time |
| pa | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty |
| pb | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
| ra | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| rb | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| rr | ra and rb at the same time |
| rra | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| rrb | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| rrr | rra and rrb at the same time |
