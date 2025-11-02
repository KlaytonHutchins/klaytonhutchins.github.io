---
layout: default
title: Selection Sort
---

### Overview
Selection Sort is a simple comparison-based sorting algorithm that divides the input into a sorted and unsorted region, repeatedly selecting the smallest (or largest) element from the unsorted region and moving it to the end of the sorted region. It performs well on small datasets but is inefficient on large lists due to its O(n²) time complexity.

### How It Works
The algorithm maintains two subarrays: a sorted portion at the beginning and an unsorted portion for the remainder.

1. Start with the entire array as unsorted
2. Find the minimum element in the unsorted portion
3. Swap it with the first element of the unsorted portion
4. Move the boundary between sorted and unsorted portions one element to the right
5. Repeat steps 2-4 until the entire array is sorted

### Complexities
Best Case - O(n²)
Average Case - O(n²)
Worst Case - O(n²)
Space - O(1)

### When to Use
**Advantages:**
- Simple to understand and implement
- Performs well on small datasets
- Requires only O(1) auxiliary space (in-place sorting)
- Minimizes the number of swaps (at most n-1 swaps), useful when writing to memory is costly

**Disadvantages:**
- O(n²) time complexity makes it inefficient for large datasets
- Not adaptive - performs the same number of comparisons even if the array is already sorted
- Not stable - does not preserve the relative order of equal elements

**Best suited for:**
- Small datasets where simplicity is more important than efficiency
- Situations where memory write operations are expensive (uses minimal swaps)
- Educational purposes to teach basic sorting concepts
- When auxiliary space is severely limited

### Example Walkthrough
Sorting the array [5, 2, 8, 1, 9] in ascending order:

```
Initial:  [5, 2, 8, 1, 9]  (sorted: [], unsorted: [5, 2, 8, 1, 9])

Pass 1:   Find minimum in [5, 2, 8, 1, 9] -> 1
          Swap 1 and 5
          [1, 2, 8, 5, 9]  (sorted: [1], unsorted: [2, 8, 5, 9])

Pass 2:   Find minimum in [2, 8, 5, 9] -> 2
          No swap needed (already in position)
          [1, 2, 8, 5, 9]  (sorted: [1, 2], unsorted: [8, 5, 9])

Pass 3:   Find minimum in [8, 5, 9] -> 5
          Swap 5 and 8
          [1, 2, 5, 8, 9]  (sorted: [1, 2, 5], unsorted: [8, 9])

Pass 4:   Find minimum in [8, 9] -> 8
          No swap needed (already in position)
          [1, 2, 5, 8, 9]  (sorted: [1, 2, 5, 8], unsorted: [9])

Final:    [1, 2, 5, 8, 9]  (sorted: [1, 2, 5, 8, 9])
```

### Implementation(s)

**Python:**
```python
def selection_sort(arr):
    """
    Sorts an array in-place using Selection Sort algorithm.

    Args:
        arr: List of comparable elements

    Returns:
        The sorted list (same object as input, modified in-place)
    """
    n = len(arr)

    # Traverse through all array elements
    for i in range(n - 1):
        # Find the minimum element in the remaining unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

    return arr


# Example usage
if __name__ == "__main__":
    data = [5, 2, 8, 1, 9]
    print("Original array:", data)
    selection_sort(data)
    print("Sorted array:", data)
```

### External Links
- [Selection Sort - Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Selection Sort Visualization - VisuAlgo](https://visualgo.net/en/sorting)
- [GeeksforGeeks - Selection Sort](https://www.geeksforgeeks.org/selection-sort/)

---

[Up](./README.md)
