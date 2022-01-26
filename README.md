# push_swap

`Push_swap` is a sorting integer algorithm that uses 2 stacks and a limited amount operations.
We receive the list of integers as arguments of the `push_swap` program as follows : `./push_swap 4 3 6`
The list is sent to the `stack A`, the `stack B` remains empty at start.

The permitted operations are :

| Names | Behaviour |
| --- | --- |
| `sa` | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements |
| `sb` | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements|
| `ss` | sa and sb at the same time |
| `pa` | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty |
| `pb` | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
| `ra` | rotate a - shift up all elements of stack a by 1. The first element becomes the last one |
| `rb` | rotate b - shift up all elements of stack b by 1. The first element becomes the last one |
| `rr` | ra and rb at the same time |
| `rra` | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one |
| `rrb` | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one |
| `rrr` | rra and rrb at the same time |

The program then outputs the list of operations needed to sort the list into the `stack A`

<img width="373" alt="Capture d’écran 2022-01-26 à 13 57 19" src="https://user-images.githubusercontent.com/56319429/151166887-fe1fbef8-38fa-4cf8-9c8b-c1fc47a94445.png">

## checker

The `checker` program receive as argument the list of integers, then read on `stdin` the list of operations. When `EOF` is reached, the program display `OK` if the list is sorted or `KO` is the list isn't sorted.

<img width="373" alt="Capture d’écran 2022-01-26 à 14 01 45" src="https://user-images.githubusercontent.com/56319429/151167560-bd563096-4c33-4e22-9c0b-e6f6ab831fb7.png">

The 2 programs can be combined as follows using `bash` : `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG`
