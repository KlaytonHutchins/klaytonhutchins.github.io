---
layout: default
title: Arrays
---

### Overview
An array is a fundamental data structure that stores a collection of elements in contiguous memory locations, where each element can be accessed directly using its index. Arrays provide constant-time random access to elements and are one of the most basic and widely-used data structures in computer science.

### Structure
Arrays store elements in contiguous blocks of memory, with each element occupying a fixed amount of space. The memory address of any element can be calculated using the formula: `address = base_address + (index * element_size)`. In static arrays, the size is fixed at creation time and cannot be changed, while dynamic arrays (like Python lists or Java ArrayLists) can grow or shrink by allocating new memory and copying elements. Each element in an array is accessed by its zero-based index, making direct access extremely efficient.

### Operations

**Access:**
Accessing an element in an array is done using its index: `arr[i]`. Since the memory address can be calculated directly using the base address and index, access is O(1) constant time. This makes arrays ideal when you need fast random access to elements.

**Search:**
To find an element in an unsorted array, you must check each element sequentially (linear search), taking O(n) time. If the array is sorted, binary search can be used to find elements in O(log n) time. Search operations don't modify the array structure.

**Insert:**
Inserting into an array requires shifting elements to make room. Inserting at the end of a dynamic array is O(1) amortized, but inserting at the beginning or middle requires shifting all subsequent elements, making it O(n). Static arrays don't support insertion after creation unless you create a new larger array.

**Delete:**
Deleting an element requires shifting all subsequent elements to fill the gap, taking O(n) time in the worst case. Deleting from the end is O(1), but deleting from the beginning or middle requires moving all following elements one position to the left.

**Other Operations:**
- **Update:** Modifying an element at a known index is O(1)
- **Traverse:** Visiting all elements takes O(n) time
- **Resize:** Dynamic arrays resize (typically doubling capacity) when full, which is O(n) but amortized to O(1) per insertion

### Complexities
Access    Ave - O(1)    Worst - O(1)
Search    Ave - O(n)    Worst - O(n)
Insert    Ave - O(n)    Worst - O(n)
Delete    Ave - O(n)    Worst - O(n)
Space - O(n)

### When to Use
**Advantages:**
- Constant-time O(1) access to any element by index
- Cache-friendly due to contiguous memory layout
- Simple and memory-efficient (minimal overhead)
- Excellent performance for iteration and sequential access
- Predictable memory usage

**Disadvantages:**
- Fixed size in static arrays (must know size in advance)
- Expensive insertions and deletions O(n) due to shifting
- Wasted memory if array is not fully utilized
- Dynamic arrays require occasional costly resizing operations
- No built-in functionality for shrinking (in many implementations)

**Common use cases:**
- Storing and accessing data by numeric index
- Implementing other data structures (stacks, queues, heaps, hash tables)
- Lookup tables and caches
- Mathematical computations and matrix operations
- Buffer management for I/O operations
- When the size is known in advance and rarely changes

### Visual Representation
```
Array in Memory:
┌─────┬─────┬─────┬─────┬─────┬─────┐
│  10 │  20 │  30 │  40 │  50 │  60 │
└─────┴─────┴─────┴─────┴─────┴─────┘
Index: 0     1     2     3     4     5
Addr:  100   104   108   112   116   120  (assuming 4 bytes per element)

Accessing arr[3]:
- Base address: 100
- Index: 3
- Element size: 4 bytes
- Address = 100 + (3 * 4) = 112
- Value at address 112: 40

Inserting 35 at index 2:
Before: [10, 20, 30, 40, 50, 60]
         ↓
After:  [10, 20, 35, 30, 40, 50, 60]  (elements shifted right)
```

### Implementation(s)

**Python:**
```python
# Python lists are dynamic arrays
# Basic array operations

# Create an array
arr = [10, 20, 30, 40, 50]

# Access - O(1)
element = arr[2]  # Gets 30
print(f"Element at index 2: {element}")

# Update - O(1)
arr[2] = 35
print(f"After update: {arr}")

# Search - O(n) for unsorted array
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

index = linear_search(arr, 40)
print(f"Index of 40: {index}")

# Insert at end - O(1) amortized
arr.append(60)
print(f"After append: {arr}")

# Insert at specific position - O(n)
arr.insert(2, 25)  # Insert 25 at index 2
print(f"After insert at index 2: {arr}")

# Delete by index - O(n)
del arr[3]
print(f"After delete at index 3: {arr}")

# Delete by value - O(n)
arr.remove(25)  # Removes first occurrence of 25
print(f"After remove 25: {arr}")

# Delete from end - O(1)
last = arr.pop()
print(f"Popped: {last}, Array: {arr}")

# Traverse - O(n)
print("Traversing array:")
for i, val in enumerate(arr):
    print(f"  Index {i}: {val}")

# Binary search on sorted array - O(log n)
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

sorted_arr = [10, 20, 30, 40, 50, 60, 70]
result = binary_search(sorted_arr, 40)
print(f"Binary search for 40: index {result}")

# Using array module for static arrays (more memory efficient)
import array

# Create typed array of integers
int_array = array.array('i', [1, 2, 3, 4, 5])
print(f"Typed array: {int_array}")
```

### External Links
- [Arrays - GeeksforGeeks](https://www.geeksforgeeks.org/array-data-structure/)
- [Array Data Structure - Wikipedia](https://en.wikipedia.org/wiki/Array_data_structure)
- [Python List Documentation](https://docs.python.org/3/tutorial/datastructures.html#more-on-lists)

---

[Up](./README.md)
