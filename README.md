# Push Swap

## Description
Push Swap is a sorting algorithm project for the 42 School curriculum. The goal is to sort a stack of integers using two stacks (A and B) with a limited set of operations.

## Features
- Implements an efficient sorting algorithm using chunking for large stacks.
- Uses a small sort algorithm for stacks of 10 elements or fewer.
- Bonus part includes a checker program to verify the sorting.

## Algorithm
### Small Sort (≤ 10 elements)
For small stacks (10 or fewer elements), a simple sorting algorithm is used, optimized for minimal operations. The logic involves:
- Checking for the smallest element and moving it to the correct position.
- Using swap (`sa`), rotate (`ra`), and reverse rotate (`rra`) operations effectively.

### Chunking Algorithm (> 10 elements)
For larger stacks, the algorithm divides the stack into multiple chunks to optimize sorting:
1. **Divide the stack into chunks** based on the median and quartiles.
2. **Push elements to Stack B** in an organized manner to minimize future operations.
3. **Sort Stack B efficiently** while keeping track of the correct order.
4. **Move elements back to Stack A** in sorted order.

## Operations Used
- `sa` (swap A), `sb` (swap B), `ss` (swap A and B)
- `pa` (push A), `pb` (push B)
- `ra` (rotate A), `rb` (rotate B), `rr` (rotate A and B)
- `rra` (reverse rotate A), `rrb` (reverse rotate B), `rrr` (reverse rotate A and B)

## Bonus Part
- **Checker Program**: A separate program (`checker_bonus.c`) reads operations and verifies if the stack is sorted correctly.
- **Additional Utility Functions**: Used for reading input, parsing commands, and handling memory management.

## Compilation and Usage
Compile the project using the provided Makefile:
```bash
make
```
Run the program:
```bash
./push_swap "4 67 3 87 23"
```
For the bonus checker:
```bash
./push_swap "4 67 3 87 23" | ./checker "4 67 3 87 23"
```

## Files Structure
```
- push_swap.c  (Main program file)
- small_sort.c (Sorting logic for small stacks)
- sorting.c (Main sorting functions)
- operations*.c (Push swap operations)
- utils_linked.c (Linked list utility functions)
- bonus/ (Contains checker and additional functionalities)
```
