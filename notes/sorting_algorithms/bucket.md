---
layout: default
title: Bucket Sort
---

### Overview
Bucket Sort is a distribution-based sorting algorithm that divides elements into a number of buckets, sorts each bucket individually (often using another sorting algorithm), and then concatenates the buckets to produce the final sorted array. It works best when input data is uniformly distributed across a range.

### How It Works
Bucket Sort distributes elements across multiple buckets, then sorts each bucket and combines them:

1. **Create Buckets**: Initialize an array of empty buckets (typically the same number as elements or based on range)
2. **Distribute Elements**: Place each element into the appropriate bucket based on its value (often using a hash function or range mapping)
3. **Sort Individual Buckets**: Sort each non-empty bucket using an appropriate sorting algorithm (insertion sort, quicksort, or recursively bucket sort)
4. **Concatenate Buckets**: Merge all buckets in order to produce the final sorted array

### Complexities
Best Case - O(n + k) where n is the number of elements and k is the number of buckets
Average Case - O(n + k) assuming uniform distribution
Worst Case - O(n²) when all elements fall into a single bucket
Space - O(n + k) for storing elements and buckets

### When to Use
**Advantages:**
- Very fast O(n + k) performance when data is uniformly distributed
- Stable sorting algorithm (maintains relative order of equal elements)
- Works well with parallel processing (buckets can be sorted independently)
- Efficient for floating-point numbers in a known range

**Disadvantages:**
- Performance degrades to O(n²) with non-uniform distributions
- Requires knowledge of input data range for optimal bucket sizing
- Higher space complexity due to bucket overhead
- Not ideal for data with many duplicate values

**Best suited for:**
- Sorting floating-point numbers uniformly distributed between 0 and 1
- Data sets where the range and distribution are known in advance
- External sorting when data can be partitioned into memory-sized chunks
- Scenarios where parallel processing can be leveraged

### Example Walkthrough
Sorting the array [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68] using 5 buckets:

```
Original Array: [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]

Step 1: Create 5 empty buckets
Bucket 0: [] (range 0.0-0.2)
Bucket 1: [] (range 0.2-0.4)
Bucket 2: [] (range 0.4-0.6)
Bucket 3: [] (range 0.6-0.8)
Bucket 4: [] (range 0.8-1.0)

Step 2: Distribute elements into buckets (bucket_index = floor(value * num_buckets))
Bucket 0: [0.17, 0.12]
Bucket 1: [0.39, 0.26, 0.21, 0.23]
Bucket 2: []
Bucket 3: [0.78, 0.72, 0.68]
Bucket 4: [0.94]

Step 3: Sort each bucket individually (using insertion sort)
Bucket 0: [0.12, 0.17]
Bucket 1: [0.21, 0.23, 0.26, 0.39]
Bucket 2: []
Bucket 3: [0.68, 0.72, 0.78]
Bucket 4: [0.94]

Step 4: Concatenate all buckets
Final Sorted Array: [0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94]
```

### Implementation(s)

**Python:**
```python
def bucket_sort(arr):
    """
    Sorts an array using bucket sort algorithm.
    Works best for uniformly distributed floating-point numbers.
    """
    if len(arr) == 0:
        return arr

    # Determine the number of buckets
    num_buckets = len(arr)

    # Find min and max values to normalize the range
    min_val = min(arr)
    max_val = max(arr)

    # Handle edge case where all elements are the same
    if min_val == max_val:
        return arr

    # Create empty buckets
    buckets = [[] for _ in range(num_buckets)]

    # Distribute elements into buckets
    range_val = max_val - min_val
    for num in arr:
        # Calculate bucket index (normalize to 0-1 range, then scale)
        index = int((num - min_val) / range_val * (num_buckets - 1))
        buckets[index].append(num)

    # Sort individual buckets using insertion sort
    for bucket in buckets:
        insertion_sort(bucket)

    # Concatenate all buckets
    result = []
    for bucket in buckets:
        result.extend(bucket)

    return result


def insertion_sort(arr):
    """Helper function to sort individual buckets."""
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


# Example usage
if __name__ == "__main__":
    data = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
    print("Original array:", data)
    sorted_data = bucket_sort(data)
    print("Sorted array:", sorted_data)
```

### External Links
- [GeeksforGeeks - Bucket Sort](https://www.geeksforgeeks.org/bucket-sort-2/)
- [Wikipedia - Bucket Sort](https://en.wikipedia.org/wiki/Bucket_sort)
- [Brilliant.org - Bucket Sort](https://brilliant.org/wiki/bucket-sort/)

---

[Up](./README.md)
