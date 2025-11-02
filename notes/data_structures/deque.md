---
layout: default
title: Deque
---

### Overview
A deque (double-ended queue, pronounced "deck") is a linear data structure that allows insertion and deletion of elements from both the front and rear ends in O(1) time. Unlike standard queues or stacks that restrict operations to one end, deques provide maximum flexibility for both FIFO and LIFO operations.

### Structure
Deques can be implemented using two primary approaches:

1. **Circular Array/Buffer:** Uses a dynamic array with front and rear pointers that wrap around. This provides cache-friendly memory access and efficient operations, but may require occasional resizing.

2. **Doubly Linked List:** Each node contains data and pointers to both previous and next nodes. This allows truly O(1) insertions/deletions without resizing, but uses more memory per element and has less cache locality.

Most modern implementations (like Python's collections.deque) use a hybrid approach with blocks of elements linked together, combining the benefits of both strategies.

### Operations

**Access:**
- `peek_front()` / `peek_back()`: View element at front/rear without removing
- Index-based access (if supported): `deque[i]` - O(n) in general, O(1) for ends

**Search:**
- Linear search from either end: O(n) time complexity
- `contains(value)`: Check if element exists in deque

**Insert:**
- `append_left(value)` / `push_front(value)`: Add element to front - O(1)
- `append_right(value)` / `push_back(value)`: Add element to rear - O(1)
- `insert_at(index, value)`: Insert at arbitrary position - O(n)

**Delete:**
- `pop_left()` / `pop_front()`: Remove and return front element - O(1)
- `pop_right()` / `pop_back()`: Remove and return rear element - O(1)
- `remove(value)`: Remove first occurrence of value - O(n)

**Other Operations:**
- `rotate(n)`: Rotate deque n steps (positive=right, negative=left) - O(n)
- `clear()`: Remove all elements
- `size()` / `is_empty()`: Check size and emptiness
- `extend_left(iterable)` / `extend_right(iterable)`: Add multiple elements

### Complexities
Access    Ave - O(n)    Worst - O(n)    [O(1) for front/back]
Search    Ave - O(n)    Worst - O(n)
Insert    Ave - O(1)    Worst - O(1)    [at ends; O(n) for middle]
Delete    Ave - O(1)    Worst - O(1)    [at ends; O(n) for middle]
Space - O(n)

### When to Use
**Advantages:**
- O(1) insertion and deletion at both ends (more flexible than stacks/queues)
- Efficient for sliding window algorithms
- Can function as both stack and queue
- Thread-safe implementations available (e.g., Python's collections.deque)
- Memory efficient for operations at ends

**Disadvantages:**
- O(n) access time for elements in the middle
- Not cache-friendly for random access compared to arrays
- Slightly higher memory overhead than simple arrays
- Poor performance for arbitrary insertions/deletions in the middle

**Common use cases:**
- Sliding window problems (maximum in window, substring problems)
- Palindrome checking and string reversal algorithms
- Implementing undo/redo functionality
- Browser history navigation (back/forward)
- Task scheduling and work-stealing algorithms
- BFS traversal when you need to add elements from both ends
- Implementing other data structures (e.g., priority deques)

### Visual Representation
```
Deque Operations (Double-Ended Queue):

    append_left/push_front          append_right/push_back
              |                              |
              v                              v
         ┌────────────────────────────────────────┐
         │                                        │
    ┌────┼────┬─────┬─────┬─────┬─────┬─────┬───┼────┐
    │    │  3 │  7  │  1  │  9  │  4  │  2  │   │    │
    └────┼────┴─────┴─────┴─────┴─────┴─────┴───┼────┘
         │                                        │
         └────────────────────────────────────────┘
              ^                              ^
              |                              |
         pop_left/pop_front            pop_right/pop_back
         peek_front()                  peek_back()

Example operations:
deque = [3, 7, 1, 9, 4, 2]
append_left(5)  -> [5, 3, 7, 1, 9, 4, 2]
append_right(8) -> [5, 3, 7, 1, 9, 4, 2, 8]
pop_left()      -> 5,  remaining: [3, 7, 1, 9, 4, 2, 8]
pop_right()     -> 8,  remaining: [3, 7, 1, 9, 4, 2]

Circular Buffer Implementation:
         front                    rear
           ↓                       ↓
    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
    │  1  │  9  │  4  │  2  │     │     │     │  3  │
    └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
      0     1     2     3     4     5     6     7
                                                 ↑
                                            wraps around
```

### Implementation(s)

**Python (Using collections.deque):**
```python
from collections import deque

# Create a deque
dq = deque([1, 2, 3])

# Add elements
dq.append(4)           # Add to right: [1, 2, 3, 4]
dq.appendleft(0)       # Add to left: [0, 1, 2, 3, 4]

# Remove elements
dq.pop()               # Remove from right: returns 4
dq.popleft()           # Remove from left: returns 0

# Peek at elements
front = dq[0]          # First element
back = dq[-1]          # Last element

# Other operations
dq.rotate(2)           # Rotate right by 2
dq.extend([5, 6])      # Add multiple to right
dq.extendleft([0, -1]) # Add multiple to left (reversed)

# Common use case: Sliding window maximum
def sliding_window_max(nums, k):
    dq = deque()  # Store indices
    result = []

    for i in range(len(nums)):
        # Remove elements outside window
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        # Remove smaller elements (not useful)
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            result.append(nums[dq[0]])

    return result
```

**Python (Custom Implementation with Circular Buffer):**
```python
class Deque:
    def __init__(self, capacity=10):
        self.capacity = capacity
        self.buffer = [None] * capacity
        self.front = 0
        self.rear = 0
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.capacity

    def _resize(self):
        old_buffer = self.buffer
        self.capacity *= 2
        self.buffer = [None] * self.capacity

        # Copy elements in order
        for i in range(self.size):
            self.buffer[i] = old_buffer[(self.front + i) % len(old_buffer)]

        self.front = 0
        self.rear = self.size

    def append_left(self, value):
        if self.is_full():
            self._resize()

        self.front = (self.front - 1) % self.capacity
        self.buffer[self.front] = value
        self.size += 1

    def append_right(self, value):
        if self.is_full():
            self._resize()

        self.buffer[self.rear] = value
        self.rear = (self.rear + 1) % self.capacity
        self.size += 1

    def pop_left(self):
        if self.is_empty():
            raise IndexError("Deque is empty")

        value = self.buffer[self.front]
        self.buffer[self.front] = None
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return value

    def pop_right(self):
        if self.is_empty():
            raise IndexError("Deque is empty")

        self.rear = (self.rear - 1) % self.capacity
        value = self.buffer[self.rear]
        self.buffer[self.rear] = None
        self.size -= 1
        return value

    def peek_front(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        return self.buffer[self.front]

    def peek_back(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        return self.buffer[(self.rear - 1) % self.capacity]

    def __len__(self):
        return self.size

    def __str__(self):
        if self.is_empty():
            return "[]"

        elements = []
        for i in range(self.size):
            elements.append(str(self.buffer[(self.front + i) % self.capacity]))

        return "[" + ", ".join(elements) + "]"
```

### External Links
- [Python collections.deque documentation](https://docs.python.org/3/library/collections.html#collections.deque)
- [GeeksforGeeks - Deque Data Structure](https://www.geeksforgeeks.org/deque-set-1-introduction-applications/)
- [Wikipedia - Double-ended queue](https://en.wikipedia.org/wiki/Double-ended_queue)

---

[Up](./README.md)
