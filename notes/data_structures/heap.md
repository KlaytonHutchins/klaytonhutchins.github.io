---
layout: default
title: Heaps
---

### Overview
A heap is a specialized tree-based data structure that satisfies the heap property: in a max-heap, each parent node is greater than or equal to its children, while in a min-heap, each parent is less than or equal to its children. Heaps are complete binary trees, meaning all levels are fully filled except possibly the last level, which is filled from left to right.

### Structure
Heaps are typically implemented using arrays for efficient storage and access. For a node at index `i`:
- Left child is at index `2i + 1`
- Right child is at index `2i + 2`
- Parent is at index `(i - 1) // 2`

**Max-Heap Property:** Every parent node has a value greater than or equal to its children. The maximum element is always at the root.

**Min-Heap Property:** Every parent node has a value less than or equal to its children. The minimum element is always at the root.

The complete binary tree property ensures there are no gaps in the array representation, making heaps space-efficient with no wasted array slots.

### Operations

**Access:**
Direct access to the root element (max or min) is O(1) by accessing index 0. Accessing arbitrary elements requires knowing their index, but heaps don't maintain any ordering beyond the heap property, so finding a specific element requires a search.

**Search:**
Searching for an arbitrary element requires O(n) time as you must potentially examine all elements. Heaps are not optimized for search operations. However, checking if an element exists at the root is O(1).

**Insert:**
1. Add the new element at the end of the array (maintaining complete tree property)
2. "Bubble up" (heapify-up): Compare with parent and swap if heap property is violated
3. Repeat until heap property is restored or element reaches root
This takes O(log n) time as the height of a complete binary tree is log n.

**Delete (Extract-Max/Min):**
1. Remove and return the root element (max or min)
2. Move the last element to the root position
3. "Bubble down" (heapify-down): Compare with children and swap with the larger child (max-heap) or smaller child (min-heap)
4. Repeat until heap property is restored or element reaches a leaf
This takes O(log n) time.

**Heapify:**
Convert an arbitrary array into a heap. Start from the last non-leaf node and heapify-down each node working backwards to the root. This builds a heap in O(n) time (not O(n log n) as might be expected).

### Complexities
Access    Ave - O(1)      Worst - O(1)       [root element only]
Search    Ave - O(n)      Worst - O(n)       [arbitrary element]
Insert    Ave - O(log n)  Worst - O(log n)
Delete    Ave - O(log n)  Worst - O(log n)   [extract root]
Heapify   Ave - O(n)      Worst - O(n)       [build heap from array]
Space - O(n)

### When to Use
**Advantages:**
- O(1) access to maximum or minimum element
- O(log n) insertion and deletion operations
- Efficient O(n) heap construction from an array
- Space-efficient array implementation with no overhead
- Excellent for implementing priority queues

**Disadvantages:**
- No efficient search for arbitrary elements (O(n))
- Not suitable when you need sorted order of all elements
- No efficient access to elements other than the root
- Cannot efficiently find kth largest/smallest without extracting elements

**Common use cases:**
- Priority queues (task scheduling, event-driven simulation)
- Heap sort algorithm
- Finding k largest or smallest elements
- Median maintenance in streaming data
- Dijkstra's shortest path algorithm
- Huffman coding for data compression
- Merging k sorted arrays or lists

### Visual Representation
```
Max-Heap Example:
Tree representation:
           50
         /    \
       30      40
      /  \    /  \
    10   20  35  15
   /  \
  5    8

Array representation:
Index:  0   1   2   3   4   5   6   7   8
Value: [50, 30, 40, 10, 20, 35, 15, 5,  8]

Parent-child relationships:
- Node 50 (index 0): children at indices 1 and 2 (30, 40)
- Node 30 (index 1): children at indices 3 and 4 (10, 20)
- Node 40 (index 2): children at indices 5 and 6 (35, 15)
- Node 10 (index 3): children at indices 7 and 8 (5, 8)

Min-Heap Example:
           5
         /   \
       10     15
      /  \   /  \
    30   20 35  40
   /  \
  50  8

Array: [5, 10, 15, 30, 20, 35, 40, 50, 8]
```

### Implementation(s)

**Python:**
```python
class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1) // 2

    def left_child(self, i):
        return 2 * i + 1

    def right_child(self, i):
        return 2 * i + 2

    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def insert(self, value):
        """Insert a value into the heap - O(log n)"""
        self.heap.append(value)
        self._heapify_up(len(self.heap) - 1)

    def _heapify_up(self, i):
        """Bubble up the element at index i"""
        while i > 0 and self.heap[i] < self.heap[self.parent(i)]:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def extract_min(self):
        """Remove and return the minimum element - O(log n)"""
        if not self.heap:
            return None

        if len(self.heap) == 1:
            return self.heap.pop()

        min_val = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return min_val

    def _heapify_down(self, i):
        """Bubble down the element at index i"""
        min_index = i
        left = self.left_child(i)
        right = self.right_child(i)

        if left < len(self.heap) and self.heap[left] < self.heap[min_index]:
            min_index = left

        if right < len(self.heap) and self.heap[right] < self.heap[min_index]:
            min_index = right

        if min_index != i:
            self.swap(i, min_index)
            self._heapify_down(min_index)

    def peek(self):
        """Get the minimum element without removing it - O(1)"""
        return self.heap[0] if self.heap else None

    def size(self):
        return len(self.heap)

    @staticmethod
    def heapify(arr):
        """Build a heap from an array - O(n)"""
        heap = MinHeap()
        heap.heap = arr[:]

        # Start from last non-leaf node and heapify down
        for i in range(len(arr) // 2 - 1, -1, -1):
            heap._heapify_down(i)

        return heap

# Usage example:
heap = MinHeap()
for value in [5, 3, 7, 1, 9, 4]:
    heap.insert(value)

print(heap.extract_min())  # 1
print(heap.extract_min())  # 3
print(heap.peek())         # 4

# Build heap from array
heap2 = MinHeap.heapify([9, 5, 6, 2, 3])
print(heap2.extract_min())  # 2
```

### External Links
- [Heap Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/heap-data-structure/)
- [Heap (data structure) - Wikipedia](https://en.wikipedia.org/wiki/Heap_(data_structure))
- [Priority Queue and Heap - VisuAlgo](https://visualgo.net/en/heap)

---

[Up](./README.md)
