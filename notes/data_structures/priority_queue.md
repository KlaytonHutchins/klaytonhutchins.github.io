---
layout: default
title: Priority Queue
---

### Overview
A priority queue is an abstract data type similar to a regular queue, but where each element has an associated priority, and elements are served in order of their priority rather than insertion order. Unlike standard queues that follow FIFO (First In First Out), priority queues always dequeue the element with the highest (or lowest) priority first.

### Structure
Priority queues are typically implemented using a binary heap data structure, which maintains the heap property: in a max-heap, each parent node has a value greater than or equal to its children; in a min-heap, each parent is less than or equal to its children. The binary heap is stored as an array where for element at index i, the left child is at 2i+1 and the right child is at 2i+2. Alternative implementations include Fibonacci heaps (offering better amortized complexity for some operations), binomial heaps, and simple sorted/unsorted arrays (less efficient for most cases).

### Operations

**Peek/Find-Min/Find-Max:**
Returns the highest-priority element without removing it. In a min-heap implementation, this is the minimum element (at the root); in a max-heap, it's the maximum. This operation simply returns the element at index 0 of the underlying array.

**Enqueue/Insert:**
Adds a new element with its associated priority to the queue. The element is initially placed at the end of the heap (array), then "bubbled up" or "sifted up" by repeatedly swapping with its parent until the heap property is restored. This ensures the element reaches its correct position based on its priority.

**Dequeue/Extract-Min/Extract-Max:**
Removes and returns the highest-priority element (the root of the heap). The last element in the heap is moved to the root position, then "bubbled down" or "sifted down" by repeatedly swapping with the higher-priority child until the heap property is restored.

**Heapify:**
Converts an arbitrary array into a valid heap structure. This can be done bottom-up in O(n) time, which is more efficient than inserting n elements individually.

**Decrease-Key/Increase-Key:**
Changes the priority of an existing element. After changing the priority, the element is bubbled up or down as needed to restore the heap property.

### Complexities
Peek      Ave - O(1)      Worst - O(1)
Search    Ave - O(n)      Worst - O(n)
Insert    Ave - O(log n)  Worst - O(log n)
Delete    Ave - O(log n)  Worst - O(log n)
Heapify   Ave - O(n)      Worst - O(n)
Space - O(n)

### When to Use
**Advantages:**
- Efficient access to the highest-priority element in O(1) time
- Efficient insertion and deletion operations in O(log n) time
- Automatically maintains ordering by priority without manual sorting
- Space-efficient implementation using arrays (no pointer overhead)
- Well-suited for streaming data where priorities matter

**Disadvantages:**
- Searching for arbitrary elements is slow (O(n) time)
- No efficient way to access elements by index
- Not suitable when you need to access elements in any order other than by priority
- Heap property must be maintained after every modification

**Common use cases:**
- Task scheduling and job queuing systems (operating systems, print queues)
- Dijkstra's shortest path algorithm and A* pathfinding
- Huffman coding for data compression
- Event-driven simulation systems
- Merge k sorted lists or streams
- Finding k largest or smallest elements in a dataset
- Median maintenance in streaming data

### Visual Representation
```
Min-Heap Priority Queue (lower values = higher priority):

Tree Representation:
         1
       /   \
      3     2
     / \   / \
    7   5 4   6
   / \
  9   8

Array Representation:
Index:  0  1  2  3  4  5  6  7  8
Value: [1, 3, 2, 7, 5, 4, 6, 9, 8]

Parent-Child Relationships:
- Element at index i
- Left child at index 2*i + 1
- Right child at index 2*i + 2
- Parent at index (i-1) // 2

Operations:
Insert 0: Add to end, bubble up
         0           <- New minimum becomes root
       /   \
      1     2
     / \   / \
    7   3 4   6
   / \ /
  9  8 5

Extract-Min: Remove root (1), move last element to root, bubble down
         2           <- 8 moved to root, then bubbled down
       /   \
      3     4
     / \   / \
    7   5 6
   / \
  9   8
```

### Implementation(s)

**Python (Using heapq module):**
```python
import heapq

class PriorityQueue:
    def __init__(self):
        self.heap = []

    def push(self, item, priority):
        """Insert item with given priority (lower number = higher priority)"""
        heapq.heappush(self.heap, (priority, item))

    def pop(self):
        """Remove and return the highest priority item"""
        if self.is_empty():
            raise IndexError("pop from empty priority queue")
        return heapq.heappop(self.heap)[1]

    def peek(self):
        """Return the highest priority item without removing it"""
        if self.is_empty():
            raise IndexError("peek from empty priority queue")
        return self.heap[0][1]

    def is_empty(self):
        return len(self.heap) == 0

    def size(self):
        return len(self.heap)

# Usage example
pq = PriorityQueue()
pq.push("low priority task", 5)
pq.push("high priority task", 1)
pq.push("medium priority task", 3)

print(pq.pop())  # "high priority task"
print(pq.pop())  # "medium priority task"
```

**Python (Custom Min-Heap Implementation):**
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

    def insert(self, key):
        """Insert a new key into the heap"""
        self.heap.append(key)
        self._bubble_up(len(self.heap) - 1)

    def _bubble_up(self, i):
        """Move element up to maintain heap property"""
        while i > 0 and self.heap[self.parent(i)] > self.heap[i]:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def extract_min(self):
        """Remove and return the minimum element"""
        if len(self.heap) == 0:
            raise IndexError("extract_min from empty heap")

        if len(self.heap) == 1:
            return self.heap.pop()

        min_val = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._bubble_down(0)
        return min_val

    def _bubble_down(self, i):
        """Move element down to maintain heap property"""
        min_index = i
        left = self.left_child(i)
        right = self.right_child(i)

        if left < len(self.heap) and self.heap[left] < self.heap[min_index]:
            min_index = left

        if right < len(self.heap) and self.heap[right] < self.heap[min_index]:
            min_index = right

        if i != min_index:
            self.swap(i, min_index)
            self._bubble_down(min_index)

    def peek(self):
        """Return minimum element without removing it"""
        if len(self.heap) == 0:
            raise IndexError("peek from empty heap")
        return self.heap[0]

    def is_empty(self):
        return len(self.heap) == 0

    def size(self):
        return len(self.heap)

# Usage example
heap = MinHeap()
heap.insert(5)
heap.insert(3)
heap.insert(7)
heap.insert(1)

print(heap.extract_min())  # 1
print(heap.peek())         # 3
print(heap.extract_min())  # 3
```

### External Links
- [Python heapq documentation](https://docs.python.org/3/library/heapq.html)
- [Priority Queue - Wikipedia](https://en.wikipedia.org/wiki/Priority_queue)
- [Binary Heap Visualization - VisuAlgo](https://visualgo.net/en/heap)

---

[Up](./README.md)
