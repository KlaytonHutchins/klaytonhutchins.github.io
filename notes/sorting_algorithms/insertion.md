---
layout: default
title: Insertion Sort
---

### Overview
Insertion Sort is a simple sorting algorithm that builds the final sorted array one item at a time by repeatedly taking elements from the unsorted portion and inserting them into their correct position in the sorted portion. It works similarly to how most people sort playing cards in their hands, picking up one card at a time and placing it in the correct position among the already sorted cards.

### How It Works
The algorithm divides the array into a sorted and unsorted region, gradually expanding the sorted region by inserting one unsorted element at a time.

1. Start with the second element (index 1) and consider the first element as already sorted
2. Compare the current element with the elements in the sorted portion (moving backwards)
3. Shift all larger elements in the sorted portion one position to the right
4. Insert the current element into its correct position in the sorted portion
5. Move to the next unsorted element and repeat steps 2-4 until the entire array is sorted

### Complexities
Best Case - O(n) - when array is already sorted
Average Case - O(n²) - random order
Worst Case - O(n²) - when array is reverse sorted
Space - O(1) - in-place sorting algorithm

### When to Use
**Advantages:**
- Simple to understand and implement
- Efficient for small datasets or nearly sorted data
- Stable sorting algorithm (maintains relative order of equal elements)
- In-place sorting with O(1) space complexity
- Adaptive - performs well when array is almost sorted
- Online algorithm - can sort data as it receives it

**Disadvantages:**
- Inefficient for large datasets due to O(n²) time complexity
- Poor performance on reverse-sorted arrays
- More comparisons and shifts than advanced algorithms like Merge Sort or Quick Sort

**Best suited for:**
- Small datasets (typically less than 50 elements)
- Nearly sorted or partially sorted arrays
- Situations where simplicity is more important than performance
- Online sorting where elements arrive one at a time
- When memory space is limited (in-place sorting)

### Example Walkthrough
Let's sort the array [5, 2, 8, 1, 9] using Insertion Sort:

```
Initial: [5, 2, 8, 1, 9]
         ^
         sorted portion

Pass 1 (i=1, key=2):
  Compare 2 with 5: 2 < 5, so shift 5 right
  Insert 2 at index 0
  Result: [2, 5, 8, 1, 9]
          ----
          sorted

Pass 2 (i=2, key=8):
  Compare 8 with 5: 8 > 5, already in correct position
  Result: [2, 5, 8, 1, 9]
          -------
          sorted

Pass 3 (i=3, key=1):
  Compare 1 with 8: 1 < 8, shift 8 right
  Compare 1 with 5: 1 < 5, shift 5 right
  Compare 1 with 2: 1 < 2, shift 2 right
  Insert 1 at index 0
  Result: [1, 2, 5, 8, 9]
          ----------
          sorted

Pass 4 (i=4, key=9):
  Compare 9 with 8: 9 > 8, already in correct position
  Result: [1, 2, 5, 8, 9]
          -------------
          sorted (complete!)

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python:**
```python
def insertion_sort(arr):
    """
    Sorts an array in-place using Insertion Sort algorithm.

    Args:
        arr: List of comparable elements

    Returns:
        None (sorts in-place)
    """
    # Traverse from second element to end
    for i in range(1, len(arr)):
        key = arr[i]  # Current element to be inserted
        j = i - 1     # Index of last element in sorted portion

        # Move elements greater than key one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        # Insert key at correct position
        arr[j + 1] = key

# Example usage:
numbers = [5, 2, 8, 1, 9]
insertion_sort(numbers)
print(numbers)  # Output: [1, 2, 5, 8, 9]
```

### External Links
- [Insertion Sort - GeeksforGeeks](https://www.geeksforgeeks.org/insertion-sort/)
- [Insertion Sort Visualization - VisuAlgo](https://visualgo.net/en/sorting)
- [Insertion Sort - Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)

---

[Up](./README.md)
