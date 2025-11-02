---
layout: default
title: Bubble Sort
---

### Overview
Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The algorithm gets its name from the way smaller or larger elements "bubble" to their correct positions with each pass through the array.

### How It Works
The algorithm works by making multiple passes through the array, comparing and swapping adjacent elements:
1. Start at the beginning of the array and compare the first two adjacent elements
2. If the first element is greater than the second, swap them
3. Move to the next pair of adjacent elements and repeat the comparison and swap
4. Continue this process until reaching the end of the array (one complete pass)
5. After each pass, the largest unsorted element "bubbles up" to its correct position at the end
6. Repeat passes through the array, reducing the range by one element each time (since the last elements are already sorted)
7. Continue until no more swaps are needed, indicating the array is fully sorted

### Complexities
Best Case - O(n) - when the array is already sorted (with optimization)
Average Case - O(n^2)
Worst Case - O(n^2) - when the array is sorted in reverse order
Space - O(1) - only requires a constant amount of additional memory for swapping

### When to Use
**Advantages:**
- Simple to understand and implement, making it excellent for teaching sorting concepts
- Requires no additional memory (in-place sorting with O(1) space complexity)
- Stable sort - maintains the relative order of equal elements
- Can detect if the list is already sorted with an optimized version

**Disadvantages:**
- Very poor performance on large datasets with O(n^2) time complexity
- Inefficient compared to other sorting algorithms like Quick Sort, Merge Sort, or even Insertion Sort
- Makes many unnecessary comparisons even when the array is nearly sorted

**Best suited for:**
- Educational purposes and learning algorithm fundamentals
- Very small datasets (fewer than 10-20 elements)
- Nearly sorted data where an optimized version can terminate early
- Situations where code simplicity is more important than performance

### Example Walkthrough
Let's sort the array [5, 2, 8, 1, 9] in ascending order:

```
Initial array: [5, 2, 8, 1, 9]

Pass 1:
  [5, 2, 8, 1, 9] -> Compare 5 and 2, swap -> [2, 5, 8, 1, 9]
  [2, 5, 8, 1, 9] -> Compare 5 and 8, no swap
  [2, 5, 8, 1, 9] -> Compare 8 and 1, swap -> [2, 5, 1, 8, 9]
  [2, 5, 1, 8, 9] -> Compare 8 and 9, no swap
  Result: [2, 5, 1, 8, 9] (9 is now in correct position)

Pass 2:
  [2, 5, 1, 8, 9] -> Compare 2 and 5, no swap
  [2, 5, 1, 8, 9] -> Compare 5 and 1, swap -> [2, 1, 5, 8, 9]
  [2, 1, 5, 8, 9] -> Compare 5 and 8, no swap
  Result: [2, 1, 5, 8, 9] (8 is now in correct position)

Pass 3:
  [2, 1, 5, 8, 9] -> Compare 2 and 1, swap -> [1, 2, 5, 8, 9]
  [1, 2, 5, 8, 9] -> Compare 2 and 5, no swap
  Result: [1, 2, 5, 8, 9] (5 is now in correct position)

Pass 4:
  [1, 2, 5, 8, 9] -> Compare 1 and 2, no swap
  Result: [1, 2, 5, 8, 9] (no swaps made, array is sorted!)

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python (Basic Version):**
```python
def bubble_sort(arr):
    """
    Basic bubble sort implementation.
    Time: O(n^2), Space: O(1)
    """
    n = len(arr)

    # Traverse through all array elements
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Swap if the element is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr
```

**Python (Optimized Version):**
```python
def bubble_sort_optimized(arr):
    """
    Optimized bubble sort with early termination.
    Best case: O(n), Worst case: O(n^2), Space: O(1)
    """
    n = len(arr)

    for i in range(n):
        # Flag to detect if any swap happened
        swapped = False

        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        # If no swaps occurred, array is already sorted
        if not swapped:
            break

    return arr
```

### External Links
- [Bubble Sort - GeeksforGeeks](https://www.geeksforgeeks.org/bubble-sort/)
- [Bubble Sort - Visualgo (Interactive Visualization)](https://visualgo.net/en/sorting)
- [Bubble Sort Algorithm - Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)

---

[Up](./README.md)
