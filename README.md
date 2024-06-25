# Push_swap

## Overview
Push_swap is a school project part of Codam core curriculum that involves sorting data on two stacks, named `a` and `b`, using a predefined set of operations. The primary goal is to sort the numbers in ascending order in stack `a` with the lowest possible number of operations.

## Rules
- **Stacks**: Two stacks are used, `a` and `b`. Initially, stack `a` contains a random set of integers, and stack `b` is empty.
- **Goal**: Sort the integers in stack `a` in ascending order.
- **Operations**: A set of operations are available to manipulate the stacks, including swapping, pushing, and rotating elements.


## Operations
- `sa` (swap a): Swap the first 2 elements at the top of stack `a`.
- `sb` (swap b): Swap the first 2 elements at the top of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa` (push a): Move the first element from stack `b` to stack `a`.
- `pb` (push b): Move the first element from stack `a` to stack `b`.
- `ra` (rotate a): Shift all elements of stack `a` up by 1.
- `rb` (rotate b): Shift all elements of stack `b` up by 1.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Shift all elements of stack `a` down by 1.
- `rrb` (reverse rotate b): Shift all elements of stack `b` down by 1.



## Installation

To install Push Swap, clone this repository to your local machine using the following command:

```bash
git clone git@github.com:Y4ZK4Y/c-push_swap.git
```

After cloning, navigate to the project directory:

```bash
cd c-push_swap
```

Compile the project using the Makefile:

```bash
make
```

## Usage

To run Push_swap, you need to provide a list of integers as arguments. For example:

```bash
./push_swap 4 67 3 87 23
```

## License

[MIT](https://choosealicense.com/licenses/mit/)