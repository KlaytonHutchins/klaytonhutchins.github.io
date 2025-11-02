---
layout: default
title: Radix Sort
---

### Overview
Radix Sort is a non-comparison based sorting algorithm that sorts integers by processing individual digits from least significant to most significant (or vice versa). It achieves linear time complexity by grouping numbers by their individual digits and using a stable sorting algorithm (typically counting sort) as a subroutine.

### How It Works
1. Find the maximum number in the array to determine the number of digits
2. Start with the least significant digit (rightmost digit)
3. Use a stable sorting algorithm (like counting sort) to sort the entire array based on the current digit position
4. Move to the next more significant digit position (moving left)
5. Repeat step 3-4 until all digit positions have been processed
6. After processing all digits, the array is fully sorted

### Complexities
Best Case - O(d * n)
Average Case - O(d * n)
Worst Case - O(d * n)
Space - O(n + k)

Where:
- n = number of elements
- d = number of digits in the largest number
- k = range of digit values (typically 10 for decimal numbers)

### When to Use
**Advantages:**
- Linear time complexity O(d * n) can be faster than comparison-based sorts when d is small
- Stable sort - maintains relative order of equal elements
- Can be faster than quicksort or mergesort for certain datasets (integers with limited range)
- Does not use comparisons, making it useful for data types where comparisons are expensive

**Disadvantages:**
- Only works for integers or strings (data that can be represented by digits/characters)
- Requires extra space O(n + k) for counting sort subroutine
- Performance degrades when d (number of digits) is large
- Not in-place, requires additional memory
- Generally slower than quicksort for random data with many digits

**Best suited for:**
- Sorting large sets of integers with a limited number of digits
- Sorting strings of equal length
- When you need a stable sort for numeric data
- Specialized applications like sorting IP addresses, dates, or phone numbers

### Example Walkthrough
Sorting [170, 45, 75, 90, 802, 24, 2, 66] using LSD (Least Significant Digit) Radix Sort:

```
Original array: [170, 45, 75, 90, 802, 24, 2, 66]

Step 1: Sort by ones place (position 0)
  170 -> 0
  45  -> 5
  75  -> 5
  90  -> 0
  802 -> 2
  24  -> 4
  2   -> 2
  66  -> 6

After sorting by ones place: [170, 90, 802, 2, 24, 45, 75, 66]

Step 2: Sort by tens place (position 1)
  170 -> 7
  90  -> 9
  802 -> 0
  2   -> 0
  24  -> 2
  45  -> 4
  75  -> 7
  66  -> 6

After sorting by tens place: [802, 2, 24, 45, 66, 170, 75, 90]

Step 3: Sort by hundreds place (position 2)
  802 -> 8
  2   -> 0
  24  -> 0
  45  -> 0
  66  -> 0
  170 -> 1
  75  -> 0
  90  -> 0

After sorting by hundreds place: [2, 24, 45, 66, 75, 90, 170, 802]

Final sorted array: [2, 24, 45, 66, 75, 90, 170, 802]
```

### Implementation(s)

**Python:**
```python
def counting_sort_by_digit(arr, exp):
    """
    Stable sort by a specific digit position using counting sort.
    exp determines which digit: 1 for ones, 10 for tens, 100 for hundreds, etc.
    """
    n = len(arr)
    output = [0] * n
    count = [0] * 10  # digits 0-9

    # Store count of occurrences
    for i in range(n):
        digit = (arr[i] // exp) % 10
        count[digit] += 1

    # Change count[i] to contain actual position in output array
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build output array (iterate backwards to maintain stability)
    for i in range(n - 1, -1, -1):
        digit = (arr[i] // exp) % 10
        output[count[digit] - 1] = arr[i]
        count[digit] -= 1

    # Copy output array to arr
    for i in range(n):
        arr[i] = output[i]


def radix_sort(arr):
    """
    Sort array using radix sort (LSD variant).
    """
    if not arr:
        return arr

    # Find the maximum number to determine number of digits
    max_num = max(arr)

    # Do counting sort for every digit
    # exp represents the current digit position (1, 10, 100, ...)
    exp = 1
    while max_num // exp > 0:
        counting_sort_by_digit(arr, exp)
        exp *= 10

    return arr


# Example usage
if __name__ == "__main__":
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    print(f"Original array: {arr}")
    radix_sort(arr)
    print(f"Sorted array: {arr}")
```

### External Links
- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Radix Sort Visualization - VisuAlgo](https://visualgo.net/en/sorting)
- [Radix Sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)

---

[Up](./README.md)
