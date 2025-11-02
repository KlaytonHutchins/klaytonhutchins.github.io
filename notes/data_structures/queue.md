---
layout: default
title: Queue
---

### Overview
A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle, where elements are added at the rear (enqueue) and removed from the front (dequeue). It models real-world queues like lines at a store, where the first person to arrive is the first person to be served.

### Structure
A queue maintains two pointers: a **front** pointer indicating where elements are removed and a **rear** (or back) pointer indicating where elements are added. The FIFO principle ensures that elements are processed in the exact order they arrive, maintaining temporal sequence. Queues can be implemented using arrays (with circular buffering to optimize space) or linked lists (allowing dynamic growth without pre-allocated space).

### Operations

**Access:**
Direct access to arbitrary elements is not supported in a standard queue. You can only access the front element using the `front()` or `peek()` operation, which returns the element that would be dequeued next without removing it.

**Search:**
Searching requires dequeuing elements until the target is found, which is inefficient (O(n)) and destructive to the queue structure. Queues are not designed for search operations.

**Insert:**
Elements are inserted using **enqueue** (or `push`), which adds an element to the rear of the queue. This operation maintains the FIFO ordering.

**Delete:**
Elements are removed using **dequeue** (or `pop`), which removes and returns the element at the front of the queue.

**Other Queue-Specific Operations:**
- **Front/Peek:** View the front element without removing it
- **isEmpty:** Check if the queue contains any elements
- **isFull:** (For bounded queues) Check if the queue has reached capacity
- **Size:** Return the number of elements currently in the queue

### Complexities
Access    Ave - O(1)    Worst - O(1)    [Only front element]
Search    Ave - O(n)    Worst - O(n)    [Not recommended]
Insert    Ave - O(1)    Worst - O(1)    [Enqueue at rear]
Delete    Ave - O(1)    Worst - O(1)    [Dequeue from front]
Space - O(n)                            [n = number of elements]

### When to Use
**Advantages:**
- Guarantees FIFO ordering, ensuring fairness in processing
- O(1) time complexity for enqueue and dequeue operations
- Simple and intuitive interface with clear semantics
- Naturally models many real-world scenarios (task scheduling, buffering, etc.)
- Efficient memory usage with linked list implementation

**Disadvantages:**
- No direct access to elements in the middle of the queue
- Not suitable for priority-based processing (use priority queue instead)
- Array-based implementations have fixed capacity or require resizing
- Cannot efficiently search for specific elements
- Limited flexibility compared to more general data structures

**Common use cases:**
- Breadth-First Search (BFS) algorithms in graphs and trees
- Task scheduling in operating systems and thread pools
- Print job spooling and printer queues
- Buffering in I/O operations (keyboard buffers, network packets)
- Asynchronous data transfer between processes
- Message queues in distributed systems
- Request handling in web servers
- Playlist management in media players

### Visual Representation
```
Queue (FIFO - First In, First Out)

    DEQUEUE (remove)              ENQUEUE (add)
           ↓                             ↑
    ┌─────────────────────────────────────┐
    │  FRONT                        REAR  │
    │                                     │
    │  ┌───┐  ┌───┐  ┌───┐  ┌───┐       │
    │  │ 5 │→ │ 3 │→ │ 7 │→ │ 9 │       │
    │  └───┘  └───┘  └───┘  └───┘       │
    │   ↑                          ↑     │
    │  First                      Last   │
    │  Out                         In    │
    └─────────────────────────────────────┘

Example operations:
1. enqueue(9) → Add 9 to the rear
2. dequeue()  → Remove and return 5 from the front
3. front()    → Return 5 without removing it

After enqueue(2) and dequeue():
    ┌───┐  ┌───┐  ┌───┐  ┌───┐
    │ 3 │→ │ 7 │→ │ 9 │→ │ 2 │
    └───┘  └───┘  └───┘  └───┘
     ↑                      ↑
   FRONT                  REAR
```

### Implementation(s)

**Python (Using List - Simple but inefficient dequeue):**
```python
class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        """Add item to the rear of the queue - O(1)"""
        self.items.append(item)

    def dequeue(self):
        """Remove and return item from front - O(n) due to list shifting"""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        return self.items.pop(0)

    def front(self):
        """Return front item without removing - O(1)"""
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self.items[0]

    def is_empty(self):
        """Check if queue is empty - O(1)"""
        return len(self.items) == 0

    def size(self):
        """Return number of items in queue - O(1)"""
        return len(self.items)
```

**Python (Using collections.deque - Efficient O(1) operations):**
```python
from collections import deque

class Queue:
    def __init__(self):
        self.items = deque()

    def enqueue(self, item):
        """Add item to the rear of the queue - O(1)"""
        self.items.append(item)

    def dequeue(self):
        """Remove and return item from front - O(1)"""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        return self.items.popleft()

    def front(self):
        """Return front item without removing - O(1)"""
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self.items[0]

    def is_empty(self):
        """Check if queue is empty - O(1)"""
        return len(self.items) == 0

    def size(self):
        """Return number of items in queue - O(1)"""
        return len(self.items)

# Example usage
q = Queue()
q.enqueue(5)
q.enqueue(3)
q.enqueue(7)
print(q.front())    # Output: 5
print(q.dequeue())  # Output: 5
print(q.dequeue())  # Output: 3
print(q.size())     # Output: 1
```

**Python (Linked List Implementation):**
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front_node = None
        self.rear_node = None
        self._size = 0

    def enqueue(self, item):
        """Add item to the rear of the queue - O(1)"""
        new_node = Node(item)
        if self.rear_node is None:
            self.front_node = self.rear_node = new_node
        else:
            self.rear_node.next = new_node
            self.rear_node = new_node
        self._size += 1

    def dequeue(self):
        """Remove and return item from front - O(1)"""
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        item = self.front_node.data
        self.front_node = self.front_node.next
        if self.front_node is None:
            self.rear_node = None
        self._size -= 1
        return item

    def front(self):
        """Return front item without removing - O(1)"""
        if self.is_empty():
            raise IndexError("front from empty queue")
        return self.front_node.data

    def is_empty(self):
        """Check if queue is empty - O(1)"""
        return self.front_node is None

    def size(self):
        """Return number of items in queue - O(1)"""
        return self._size
```

### External Links
- [Queue Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/queue-data-structure/)
- [Queue (abstract data type) - Wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))
- [Python Queue Documentation - collections.deque](https://docs.python.org/3/library/collections.html#collections.deque)

---

[Up](./README.md)
