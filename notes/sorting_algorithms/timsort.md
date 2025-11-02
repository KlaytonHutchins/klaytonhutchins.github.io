---
layout: default
title: Tim Sort
---

### Overview
Tim Sort is a hybrid sorting algorithm derived from merge sort and insertion sort, designed to perform well on real-world data with existing order patterns. Invented by Tim Peters in 2002 for Python, it is now the default sorting algorithm in Python, Java, Android, and Swift.

### How It Works
Tim Sort exploits existing order in data by identifying and merging sorted subsequences called "runs":

1. **Divide into Runs**: Scan the array to identify runs (consecutive elements that are already sorted, either ascending or strictly descending)
2. **Minimum Run Size**: Calculate minimum run size (typically 32-64 elements) using a sophisticated formula based on array length
3. **Extend Short Runs**: If a natural run is shorter than the minimum, extend it using insertion sort to reach the minimum size
4. **Reverse Descending Runs**: Convert strictly descending runs to ascending by reversing them in-place
5. **Push to Stack**: Push each run onto a stack while maintaining invariants that ensure balanced merging
6. **Merge Runs**: Merge runs from the stack using an optimized merge operation that uses galloping mode for efficiency
7. **Final Merge**: Continue merging until only one run remains, which is the fully sorted array

### Complexities
Best Case - O(n) (when data is already sorted or reverse sorted)
Average Case - O(n log n)
Worst Case - O(n log n)
Space - O(n) (requires temporary array for merging)

### When to Use
**Advantages:**
- Excellent performance on real-world data with partial ordering or patterns
- Stable sort (preserves relative order of equal elements)
- Adaptive: takes advantage of existing order in data
- Consistent O(n log n) worst-case performance
- Highly optimized with techniques like galloping mode

**Disadvantages:**
- More complex to implement than simpler algorithms
- Requires O(n) extra space for merging
- Overhead may not be worth it for small arrays or completely random data
- Not as cache-efficient as some in-place algorithms like quicksort

**Best suited for:**
- Sorting data with existing patterns or partial order (common in real-world applications)
- When stability is required (maintaining order of equal elements)
- General-purpose sorting where consistency and reliability matter
- Large datasets where the adaptive nature provides significant benefits

### Example Walkthrough
Sorting the array `[5, 2, 8, 12, 1, 6, 9, 3, 7, 4]` with minimum run size of 4:

```
Initial array: [5, 2, 8, 12, 1, 6, 9, 3, 7, 4]

Step 1: Identify first run starting at index 0
  Natural run: [5] (length 1, ascending stops immediately)
  Extend to minrun=4 using insertion sort: [2, 5, 8, 12]
  Run 1: [2, 5, 8, 12]

Step 2: Identify next run starting at index 4
  Natural run: [1] (length 1)
  Extend to minrun=4 using insertion sort: [1, 3, 6, 9]
  Run 2: [1, 3, 6, 9]

Step 3: Identify final run starting at index 8
  Natural run: [7, 4] - descending!
  Reverse it: [4, 7]
  Length is 2, less than minrun, so it stays as is (end of array)
  Run 3: [4, 7]

Step 4: Merge runs from stack
  Merge Run 2 and Run 3: [1, 3, 4, 6, 7, 9]
  Merge Run 1 and merged result: [1, 2, 3, 4, 5, 6, 7, 8, 9, 12]

Final sorted array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 12]
```

### Implementation(s)

**Python (Simplified):**
```python
def insertion_sort(arr, left, right):
    """Sort arr[left:right+1] using insertion sort."""
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, left, mid, right):
    """Merge two sorted subarrays arr[left:mid+1] and arr[mid+1:right+1]."""
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i = j = 0
    k = left

    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1

def timsort(arr):
    """Simplified Tim Sort implementation."""
    n = len(arr)
    min_run = 32  # Simplified: typically calculated based on n

    # Step 1: Sort individual runs using insertion sort
    for start in range(0, n, min_run):
        end = min(start + min_run - 1, n - 1)
        insertion_sort(arr, start, end)

    # Step 2: Merge runs starting from size min_run
    size = min_run
    while size < n:
        for left in range(0, n, size * 2):
            mid = min(left + size - 1, n - 1)
            right = min(left + size * 2 - 1, n - 1)

            if mid < right:
                merge(arr, left, mid, right)

        size *= 2

    return arr

# Example usage
arr = [5, 2, 8, 12, 1, 6, 9, 3, 7, 4]
timsort(arr)
print(arr)  # Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 12]
```

**Note:** The actual Tim Sort implementation in Python's standard library is far more complex, including run detection, galloping mode, and sophisticated merge strategies. This is a simplified educational version demonstrating the core concept.

### External Links
- [Tim Peters' Original Description of Timsort](https://github.com/python/cpython/blob/main/Objects/listsort.txt) - The authoritative source document explaining Tim Sort's design and implementation
- [Timsort on Wikipedia](https://en.wikipedia.org/wiki/Timsort) - Comprehensive overview with complexity analysis and history
- [Understanding Timsort (Deep Dive)](https://www.geeksforgeeks.org/timsort/) - Detailed explanation with examples and code

---

[Up](./README.md)
