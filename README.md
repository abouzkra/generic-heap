# Heap

Heaps are a tree-based data structure that optimizes the retrieval of specific elements, it satisfies two necessary conditions:
- All levels must be filled from left to right, and they should all be fully filled except for the last level.
- Each child should fulfil the heap property relative to its parent.

There are two main types which are implemented in this library:
- **Min heap**: every node should be **smaller or equal** to its children, and the minimum value is always at the root.
- **Max heap**: every node should be **greater or equal** to its children, and the maximum value is always at the root.

When storing the heap as a 0-indexed array, the parent-child relationship is defined as follows (assume `i` is an index from the array):
- **Parent**: `(i - 1) // 2`
- **Left Child**: `i * 2 + 1`
- **Right Child**: `i * 2 + 2`

# Implementation
This is lightweight generic heap library in C providing a flexible implementation that supports any data type through `void *` and custom comparison functions.

### Features
- **Generic**: As long as the user provides correct input about the data they want to use it should work with any data type (primitive types, pointers, structures...).
- **Flexible**: Easily swith between Max and Min heap by just flipping the comparison function.
- **Visual**: To see the results in action, `pretty_print_q` is a built-in function that provides a heap visualization.
- **Opaque**: `s_heap` structure's internal state is encapsulated to prevent the user from shooting themselves in the foot by messing with the `s_heap` structure's internal state.

# Instuctions

### Compiling the library

```make
make heap.a # to make static library only
make heap.so # to make shared library only
make #or make all # to make them both
```

### Quick start
I've provided some usage examples inside `examples/` folder, to compile them just use:

```
make examples
```
And run one of them using:

```
./examples/int_example
```

# Quick Library overview

|**Function**|**Description**|
| :--- | :--- |
|`create_heap`|Initializes a heap with initial capacity, element width and a comparison function|
|`heapify`|Builds a heap from an array of elements.|
|`insert`|Inserts an element to the heap, it pushes it as the last element and uses `sift_up` to maintain the heap property.|
|`get_heap_count`|Getter for the element count in the heap.|
|`pop`|Pops the top element of the heap, it writes it to a variable, swaps top with the last element in the heap and uses `sift_down` to maintian the heap property|
|`del`|Removes an element at index `idx`, uses `sift_down` and `sift_up` at each parent node to maintain the heap property.|
|`destroy_heap`|Frees all memory associated with the heap.|
|`pretty_print_heap`|Visualizes the heap strucutre through recursive printing using dfs.|

### Comparison function
For correct heap behaviour, the user should provide a correct comparison functon `cmp` that respects the following rules:
- **Signature**: it should respect this signature `int comparison_function(void *el1, void *el2)`
- **Comparison**: it should follow standard C comparison functions such as `strcmp`, it returns the difference between the two elements as an integer:
  - **< 0**: el1 is smaller than el2
  - **== 0**: el1 is equal to el2
  - **< 0**: el1 is greater than el2

### Element printing function
So that `pretty_print_heap` correctly prints the heap, the `print_data` function should respect the following rules:
- **Signature**: it should respect this signature `void print_data(void *data)`
- **Formatting**: the user can print data as they whish except that the printed string should end with a new line `\n`.

## Improvements
- []**Dynamic Resizing**
- []**Thread Safety**
- []**More Utility Functions**
- []**Custom Allocation/Deallocation**
- etc...

# Resources
- [Heap (data structure)](https://en.wikipedia.org/wiki/Heap_(data_structure))
