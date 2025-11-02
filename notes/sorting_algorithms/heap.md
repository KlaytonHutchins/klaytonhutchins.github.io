---
layout: default
title: Heap Sort
---

### Overview
Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to efficiently sort elements in-place. It works by building a max heap from the input array, then repeatedly extracting the maximum element and placing it at the end of the sorted portion.

### How It Works
The heap sort algorithm consists of two main phases:

**Phase 1: Build Max Heap**
1. Start with an unsorted array and treat it as a complete binary tree
2. Apply the heapify operation starting from the last non-leaf node up to the root
3. Heapify ensures that each parent node is greater than or equal to its children (max heap property)
4. After this phase, the largest element is at the root (index 0)

**Phase 2: Extract Elements**
1. Swap the root (maximum element) with the last element in the heap
2. Reduce the heap size by 1 (excluding the sorted element)
3. Heapify the root to restore the max heap property
4. Repeat steps 1-3 until the heap size is 1
5. The array is now sorted in ascending order

### Complexities
Best Case - O(n log n)
Average Case - O(n log n)
Worst Case - O(n log n)
Space - O(1) auxiliary space (in-place sorting)

### When to Use
**Advantages:**
- Guaranteed O(n log n) time complexity in all cases, making performance predictable
- In-place sorting with O(1) auxiliary space complexity
- No worst-case quadratic time behavior like Quick Sort
- Useful for finding the k largest or smallest elements efficiently
- Not affected by initial ordering of elements

**Disadvantages:**
- Not stable (does not preserve relative order of equal elements)
- Generally slower in practice than Quick Sort due to poor cache locality
- More complex to implement than simpler algorithms like Insertion Sort
- Not adaptive - doesn't take advantage of existing order in the data

**Best suited for:**
- Systems with limited memory where in-place sorting is critical
- Situations requiring guaranteed O(n log n) performance
- Priority queue implementations
- Finding top-k elements in a dataset
- Embedded systems or real-time systems with strict performance guarantees

### Example Walkthrough
Sorting the array [5, 2, 8, 1, 9] using Heap Sort:

```
Initial array: [5, 2, 8, 1, 9]

Phase 1: Build Max Heap
Array indices:  0  1  2  3  4
Tree structure:     5
                   / \
                  2   8
                 / \
                1   9

Step 1: Heapify subtree at index 1 (node 2)
  - Compare 2 with children 1 and 9
  - Swap 2 with 9 (larger child)
  - Array: [5, 9, 8, 1, 2]

Step 2: Heapify subtree at index 0 (node 5)
  - Compare 5 with children 9 and 8
  - Swap 5 with 9 (larger child)
  - Array: [9, 5, 8, 1, 2]
  - Heapify subtree at index 1 again
  - Compare 5 with children 1 and 2
  - No swap needed (5 > 1 and 5 > 2)

Max heap built: [9, 5, 8, 1, 2]
Tree:           9
               / \
              5   8
             / \
            1   2

Phase 2: Extract Elements and Sort
Step 1: Swap 9 with last element (2), reduce heap size
  - Array: [2, 5, 8, 1 | 9]
  - Heapify root: [8, 5, 2, 1 | 9]

Step 2: Swap 8 with last element (1), reduce heap size
  - Array: [1, 5, 2 | 8, 9]
  - Heapify root: [5, 1, 2 | 8, 9]

Step 3: Swap 5 with last element (2), reduce heap size
  - Array: [2, 1 | 5, 8, 9]
  - Heapify root: [2, 1 | 5, 8, 9]

Step 4: Swap 2 with last element (1), reduce heap size
  - Array: [1 | 2, 5, 8, 9]

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python:**
```python
def heap_sort(arr):
    """
    Sorts an array in ascending order using heap sort algorithm.

    Args:
        arr: List of comparable elements to sort

    Returns:
        The sorted array (modifies in-place)
    """
    n = len(arr)

    # Build max heap (rearrange array)
    # Start from last non-leaf node and heapify each node
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        # Move current root (maximum) to end
        arr[0], arr[i] = arr[i], arr[0]

        # Heapify the reduced heap
        heapify(arr, i, 0)

    return arr


def heapify(arr, n, i):
    """
    Heapifies a subtree rooted at index i.

    Args:
        arr: The array representing the heap
        n: Size of the heap
        i: Index of the root of the subtree to heapify
    """
    largest = i  # Initialize largest as root
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child

    # Check if left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if right child exists and is greater than current largest
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root, swap and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        # Recursively heapify the affected subtree
        heapify(arr, n, largest)


# Example usage
if __name__ == "__main__":
    arr = [5, 2, 8, 1, 9]
    print(f"Original array: {arr}")
    heap_sort(arr)
    print(f"Sorted array: {arr}")
```

### External Links
- [Heap Sort - Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
- [Heap Sort Visualization - VisuAlgo](https://visualgo.net/en/heap)
- [Heap Sort Tutorial - GeeksforGeeks](https://www.geeksforgeeks.org/heap-sort/)

---

[Up](./README.md)
