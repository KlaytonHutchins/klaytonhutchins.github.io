---
layout: default
title: Merge Sort
---

### Overview
Merge Sort is a stable, comparison-based sorting algorithm that uses the divide-and-conquer strategy to efficiently sort data. It recursively divides the input array into smaller subarrays until each contains a single element, then repeatedly merges these subarrays in sorted order to produce the final sorted array.

### How It Works
Merge Sort operates in two main phases: divide and merge.

1. **Divide Phase**: Recursively split the array in half until you have subarrays with only one element each (a single element is inherently sorted).
2. **Merge Phase**: Repeatedly merge pairs of sorted subarrays back together in sorted order.
   - Compare the smallest unmerged elements from each subarray
   - Place the smaller element into the result array
   - Continue until all elements from both subarrays are merged
3. **Recursion Unwinds**: As the recursive calls return, larger and larger sorted subarrays are merged until the entire array is sorted.

### Complexities
Best Case - O(n log n)
Average Case - O(n log n)
Worst Case - O(n log n)
Space - O(n)

### When to Use
**Advantages:**
- Guaranteed O(n log n) performance in all cases (predictable performance)
- Stable sort: maintains relative order of equal elements
- Excellent for sorting linked lists (no random access needed)
- Parallelizable: different subarrays can be sorted independently
- Works well with external sorting (data that doesn't fit in memory)

**Disadvantages:**
- Requires O(n) extra space for the temporary arrays
- Slower in practice than quicksort for in-memory sorting due to extra copying
- Overkill for small datasets where simpler algorithms would suffice
- Not in-place (requires additional memory allocation)

**Best suited for:**
- Sorting linked lists (where it can be implemented with O(1) extra space)
- When stable sorting is required
- When consistent O(n log n) performance is more important than average-case speed
- External sorting scenarios (sorting large files on disk)
- Parallel processing environments where divide-and-conquer can be exploited

### Example Walkthrough
Let's sort the array [5, 2, 8, 1, 9] using Merge Sort:

**Divide Phase:**
```
Initial:        [5, 2, 8, 1, 9]
                      |
            +---------+---------+
            |                   |
        [5, 2, 8]           [1, 9]
            |                   |
        +---+---+           +---+---+
        |       |           |       |
    [5, 2]     [8]         [1]     [9]
        |
    +---+---+
    |       |
   [5]     [2]
```

**Merge Phase (working bottom-up):**
```
Step 1: Merge [5] and [2]
        Compare 5 and 2 -> take 2, then 5
        Result: [2, 5]

Step 2: [2, 5] is already sorted, [8] is single element
        Left side: [2, 5, 8]

Step 3: Merge [1] and [9]
        Compare 1 and 9 -> take 1, then 9
        Result: [1, 9]

Step 4: Merge [2, 5, 8] and [1, 9]
        Compare 2 and 1 -> take 1
        Compare 2 and 9 -> take 2
        Compare 5 and 9 -> take 5
        Compare 8 and 9 -> take 8
        Take remaining 9
        Result: [1, 2, 5, 8, 9]

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python:**
```python
def merge_sort(arr):
    """
    Sorts an array using the merge sort algorithm.

    Args:
        arr: List of comparable elements

    Returns:
        Sorted list
    """
    # Base case: arrays with 0 or 1 element are already sorted
    if len(arr) <= 1:
        return arr

    # Divide: find the middle point and split the array
    mid = len(arr) // 2
    left_half = arr[:mid]
    right_half = arr[mid:]

    # Conquer: recursively sort both halves
    left_sorted = merge_sort(left_half)
    right_sorted = merge_sort(right_half)

    # Combine: merge the sorted halves
    return merge(left_sorted, right_sorted)


def merge(left, right):
    """
    Merges two sorted arrays into a single sorted array.

    Args:
        left: Sorted list
        right: Sorted list

    Returns:
        Merged sorted list
    """
    result = []
    i = j = 0

    # Compare elements from left and right, adding the smaller one
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Add remaining elements from left (if any)
    result.extend(left[i:])

    # Add remaining elements from right (if any)
    result.extend(right[j:])

    return result


# Example usage
if __name__ == "__main__":
    arr = [5, 2, 8, 1, 9]
    sorted_arr = merge_sort(arr)
    print(f"Original: {arr}")
    print(f"Sorted: {sorted_arr}")
```

### External Links
- [Merge Sort Visualization - VisuAlgo](https://visualgo.net/en/sorting) - Interactive visualization showing how merge sort works step-by-step
- [Merge Sort - GeeksforGeeks](https://www.geeksforgeeks.org/merge-sort/) - Comprehensive guide with examples and complexity analysis
- [Merge Sort - Wikipedia](https://en.wikipedia.org/wiki/Merge_sort) - Detailed explanation including history, variants, and analysis

---

[Up](./README.md)
