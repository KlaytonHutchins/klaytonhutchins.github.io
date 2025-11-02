---
layout: default
title: Stack
---

### Overview
A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the same end called the "top". Like a stack of plates, the last item placed on top is the first one to be removed.

### Structure
A stack organizes elements in a sequential order with access restricted to one end. The "top" of the stack is where all insertions (push) and deletions (pop) occur. The LIFO principle ensures that the most recently added element is always the first to be removed. Internally, stacks can be implemented using arrays (with a top pointer) or linked lists (where the head serves as the top). The bottom element is the oldest item in the stack and can only be accessed after all elements above it are removed.

### Operations

**Access:**
Only the top element can be directly accessed in O(1) time using the peek/top operation. Accessing elements below the top requires popping all elements above them, making arbitrary access inefficient at O(n).

**Search:**
Searching for an element requires iterating through the stack from top to bottom, which takes O(n) time. This often involves popping elements temporarily to check each one, then restoring the stack.

**Insert:**
Elements are inserted using the push operation, which adds a new element to the top of the stack in O(1) time. No other position allows direct insertion in a standard stack.

**Delete:**
Elements are removed using the pop operation, which removes and returns the top element in O(1) time. Only the top element can be directly deleted.

**Stack-Specific Operations:**
- **Push:** Add an element to the top of the stack
- **Pop:** Remove and return the top element from the stack
- **Peek/Top:** View the top element without removing it
- **isEmpty:** Check if the stack contains no elements
- **Size:** Return the number of elements in the stack

### Complexities
Access    Ave - O(n)    Worst - O(n)
Search    Ave - O(n)    Worst - O(n)
Insert    Ave - O(1)    Worst - O(1)
Delete    Ave - O(1)    Worst - O(1)
Space - O(n)

### When to Use
**Advantages:**
- Simple and easy to implement with minimal overhead
- Constant time O(1) push and pop operations
- Efficient memory usage with dynamic sizing
- Natural fit for problems involving reversal or backtracking
- Supports function call management and recursion

**Disadvantages:**
- Limited access - only the top element is directly accessible
- No random access to elements in the middle
- Searching requires O(n) time and may require temporary storage
- Fixed size in array-based implementations (though dynamic arrays solve this)
- Not suitable when you need to access elements in arbitrary order

**Common use cases:**
- Function call stack and recursion management
- Undo/redo functionality in applications
- Expression evaluation and syntax parsing (infix to postfix conversion)
- Backtracking algorithms (maze solving, DFS)
- Browser history navigation (back button)
- Balanced parentheses and bracket matching
- Reversing sequences (strings, arrays)

### Visual Representation
```
Stack Operations:

    push(5)              push(2)              pop()
    -------              -------              -----

                            |2|    <-- top
       |5|    <-- top       |5|                |5|    <-- top
       |3|                  |3|                |3|
       |7|                  |7|                |7|
       |1|                  |1|                |1|
      ------               ------              ------

Stack Structure:

       |   |    <-- top (index n-1)
       |---|
       | 8 |    <-- can be accessed via peek()
       |---|
       | 3 |
       |---|
       | 6 |
       |---|
       | 1 |    <-- bottom (index 0)
       ------

Operations only occur at the top!
```

### Implementation(s)

**Python:**
```python
class Stack:
    def __init__(self):
        """Initialize an empty stack."""
        self.items = []

    def push(self, item):
        """Add an item to the top of the stack."""
        self.items.append(item)

    def pop(self):
        """Remove and return the top item from the stack.
        Raises IndexError if stack is empty."""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self.items.pop()

    def peek(self):
        """Return the top item without removing it.
        Raises IndexError if stack is empty."""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self.items[-1]

    def is_empty(self):
        """Return True if the stack is empty."""
        return len(self.items) == 0

    def size(self):
        """Return the number of items in the stack."""
        return len(self.items)

    def __str__(self):
        """String representation of the stack."""
        return str(self.items)


# Usage example
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(f"Stack: {stack}")        # Stack: [1, 2, 3]
print(f"Top: {stack.peek()}")   # Top: 3
print(f"Pop: {stack.pop()}")    # Pop: 3
print(f"Size: {stack.size()}")  # Size: 2
```

### External Links
- [Stack Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/stack-data-structure/)
- [Stack (abstract data type) - Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Stack Implementation - Programiz](https://www.programiz.com/dsa/stack)

---

[Up](./README.md)
