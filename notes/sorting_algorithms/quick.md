---
layout: default
title: Quick Sort
---

### Overview
Quick Sort is an efficient divide-and-conquer sorting algorithm that selects a 'pivot' element and partitions the array around it, placing smaller elements to the left and larger elements to the right. It then recursively sorts the sub-arrays on either side of the pivot until the entire array is sorted.

### How It Works
Quick Sort works by recursively partitioning the array around a pivot element:
1. **Choose a pivot**: Select an element from the array as the pivot (commonly the last element, first element, or middle element)
2. **Partition**: Rearrange the array so that all elements smaller than the pivot come before it, and all elements greater than the pivot come after it. The pivot is now in its final sorted position
3. **Recursively sort**: Apply the same process to the sub-array of elements less than the pivot and the sub-array of elements greater than the pivot
4. **Base case**: When a sub-array has 0 or 1 elements, it's already sorted and the recursion stops

### Complexities
Best Case - O(n log n)
Average Case - O(n log n)
Worst Case - O(n^2)
Space - O(log n) for the recursion stack

### When to Use
**Advantages:**
- Very fast in practice with O(n log n) average case performance
- In-place sorting (requires only O(log n) extra space for recursion)
- Cache-friendly due to good locality of reference
- Often outperforms other O(n log n) algorithms like Merge Sort in practice

**Disadvantages:**
- Worst case time complexity of O(n^2) when poorly chosen pivots occur (e.g., already sorted arrays with naive pivot selection)
- Not stable (doesn't preserve relative order of equal elements)
- Performance depends heavily on pivot selection strategy
- Recursive implementation can cause stack overflow for very large datasets

**Best suited for:**
- General-purpose sorting when average-case performance is more important than worst-case guarantees
- Large datasets where in-place sorting is preferred to minimize memory usage
- Systems where cache performance matters (better cache locality than Merge Sort)
- Situations where the data is randomly distributed

### Example Walkthrough
Let's sort the array [5, 2, 8, 1, 9] using Quick Sort with the last element as the pivot:

```
Initial array: [5, 2, 8, 1, 9]

First partition (pivot = 9):
  - Compare 5 with 9: 5 < 9, keep at index 0
  - Compare 2 with 9: 2 < 9, keep at index 1
  - Compare 8 with 9: 8 < 9, keep at index 2
  - Compare 1 with 9: 1 < 9, keep at index 3
  - Place pivot 9 at index 4
  Result: [5, 2, 8, 1, 9] (9 is now in its final position)
  Recursively sort left: [5, 2, 8, 1] | Right: [] (empty, done)

Second partition on [5, 2, 8, 1] (pivot = 1):
  - Compare 5 with 1: 5 > 1, skip
  - Compare 2 with 1: 2 > 1, skip
  - Compare 8 with 1: 8 > 1, skip
  - Place pivot 1 at index 0
  Result: [1, 2, 8, 5] (1 is now in its final position)
  Recursively sort left: [] (empty, done) | Right: [2, 8, 5]

Third partition on [2, 8, 5] (pivot = 5):
  - Compare 2 with 5: 2 < 5, keep at index 0
  - Compare 8 with 5: 8 > 5, skip
  - Place pivot 5 at index 1
  Result: [2, 5, 8] (5 is now in its final position)
  Recursively sort left: [2] (single element, done) | Right: [8] (single element, done)

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python:**
```python
def quick_sort(arr, low=0, high=None):
    """
    Sorts an array in-place using Quick Sort algorithm.

    Args:
        arr: List to be sorted
        low: Starting index (default 0)
        high: Ending index (default len(arr) - 1)
    """
    if high is None:
        high = len(arr) - 1

    if low < high:
        # Partition the array and get the pivot index
        pivot_index = partition(arr, low, high)

        # Recursively sort elements before and after partition
        quick_sort(arr, low, pivot_index - 1)
        quick_sort(arr, pivot_index + 1, high)

    return arr


def partition(arr, low, high):
    """
    Partitions the array around a pivot element.
    Uses the last element as the pivot.

    Args:
        arr: List to be partitioned
        low: Starting index
        high: Ending index (pivot is at this index)

    Returns:
        Final position of the pivot
    """
    pivot = arr[high]  # Choose the last element as pivot
    i = low - 1  # Index of smaller element

    for j in range(low, high):
        # If current element is smaller than or equal to pivot
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap

    # Swap the pivot element with the element at i+1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# Example usage
if __name__ == "__main__":
    arr = [5, 2, 8, 1, 9]
    print(f"Original array: {arr}")
    quick_sort(arr)
    print(f"Sorted array: {arr}")
```

### External Links
- [Quick Sort - GeeksforGeeks](https://www.geeksforgeeks.org/quick-sort/)
- [Quick Sort Visualizer - VisuAlgo](https://visualgo.net/en/sorting)
- [Quick Sort - Wikipedia](https://en.wikipedia.org/wiki/Quicksort)

---

[Up](./README.md)
