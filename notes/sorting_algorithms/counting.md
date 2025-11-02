---
layout: default
title: Counting Sort
---

### Overview
Counting Sort is a non-comparison based integer sorting algorithm that works by counting the number of occurrences of each distinct element in the input array. It then uses arithmetic to determine the positions of each element in the sorted output array, making it extremely efficient for sorting integers within a known, limited range.

### How It Works
The algorithm operates in three main phases:

1. **Find the Range**: Determine the minimum and maximum values in the input array to establish the range of values that need to be counted.

2. **Count Occurrences**: Create a count array where each index represents a value from the range, and the value at that index represents how many times that number appears in the input array.

3. **Calculate Cumulative Counts**: Modify the count array so that each element stores the cumulative sum up to that index. This tells us the position where each value should end up in the sorted array.

4. **Build the Output Array**: Iterate through the input array (typically from right to left to maintain stability), and for each element, look up its position in the count array, place it in the output array, and decrement the count.

### Complexities
Best Case - O(n + k)
Average Case - O(n + k)
Worst Case - O(n + k)
Space - O(n + k)

Where n is the number of elements in the input array and k is the range of input values (max - min + 1).

### When to Use
**Advantages:**
- Linear time complexity O(n + k), which can be faster than comparison-based sorts (O(n log n)) when k is relatively small
- Stable sorting algorithm (preserves the relative order of equal elements)
- Simple and easy to implement
- Predictable performance - no worst-case degradation based on input distribution

**Disadvantages:**
- Only works with non-negative integers or data that can be mapped to non-negative integers
- Space complexity becomes prohibitive when the range k is very large
- Inefficient when k >> n (range is much larger than the number of elements)
- Not an in-place algorithm - requires additional memory proportional to the range

**Best suited for:**
- Sorting integers within a known, limited range (e.g., ages, grades, small ID numbers)
- When the range of values (k) is not significantly larger than the number of elements (n)
- Situations where stability is important (maintaining order of equal elements)
- As a subroutine in other algorithms like Radix Sort
- Counting occurrences or frequency distributions

### Example Walkthrough
Let's sort the array [4, 2, 2, 8, 3, 3, 1] using Counting Sort:

```
Initial array: [4, 2, 2, 8, 3, 3, 1]

Step 1: Find the range
  min = 1, max = 8
  range = 8 - 1 + 1 = 8

Step 2: Count occurrences (adjusted for min value)
  Index:  0  1  2  3  4  5  6  7
  Value:  1  2  3  4  5  6  7  8
  Count: [1, 2, 2, 1, 0, 0, 0, 1]

  Meaning: 1 appears 1 time, 2 appears 2 times, 3 appears 2 times,
           4 appears 1 time, 8 appears 1 time

Step 3: Calculate cumulative counts
  Count: [1, 3, 5, 6, 6, 6, 6, 7]

  This tells us:
  - Values <= 1 occupy positions 0-0 (1 element)
  - Values <= 2 occupy positions 0-2 (3 elements)
  - Values <= 3 occupy positions 0-4 (5 elements)
  - etc.

Step 4: Build output array (processing from right to left for stability)
  Process 1: count[0]=1, place at index 0, decrement → [1, _, _, _, _, _, _]
  Process 3: count[2]=5, place at index 4, decrement → [1, _, _, _, 3, _, _]
  Process 3: count[2]=4, place at index 3, decrement → [1, _, _, 3, 3, _, _]
  Process 8: count[7]=7, place at index 6, decrement → [1, _, _, 3, 3, _, 8]
  Process 2: count[1]=3, place at index 2, decrement → [1, _, 2, 3, 3, _, 8]
  Process 2: count[1]=2, place at index 1, decrement → [1, 2, 2, 3, 3, _, 8]
  Process 4: count[3]=6, place at index 5, decrement → [1, 2, 2, 3, 3, 4, 8]

Final sorted array: [1, 2, 2, 3, 3, 4, 8]
```

### Implementation(s)

**Python:**
```python
def counting_sort(arr):
    """
    Sorts an array of non-negative integers using Counting Sort.

    Args:
        arr: List of integers to sort

    Returns:
        Sorted list
    """
    if not arr:
        return arr

    # Step 1: Find the range
    min_val = min(arr)
    max_val = max(arr)
    range_size = max_val - min_val + 1

    # Step 2: Count occurrences
    count = [0] * range_size
    for num in arr:
        count[num - min_val] += 1

    # Step 3: Calculate cumulative counts
    for i in range(1, range_size):
        count[i] += count[i - 1]

    # Step 4: Build output array (iterate backwards for stability)
    output = [0] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        num = arr[i]
        index = count[num - min_val] - 1
        output[index] = num
        count[num - min_val] -= 1

    return output


# Example usage
if __name__ == "__main__":
    arr = [4, 2, 2, 8, 3, 3, 1]
    sorted_arr = counting_sort(arr)
    print(f"Original: {arr}")
    print(f"Sorted:   {sorted_arr}")
```

### External Links
- [Counting Sort - GeeksforGeeks](https://www.geeksforgeeks.org/counting-sort/)
- [Counting Sort Visualization - VisuAlgo](https://visualgo.net/en/sorting)
- [Counting Sort - Wikipedia](https://en.wikipedia.org/wiki/Counting_sort)

---

[Up](./README.md)
