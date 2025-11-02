---
layout: default
title: Linked Lists
---

### Overview
A linked list is a linear data structure where elements (nodes) are stored non-contiguously in memory, with each node containing data and a reference (pointer) to the next node in the sequence. Unlike arrays, linked lists allow efficient insertion and deletion at any position without requiring memory reallocation or element shifting.

### Structure
A linked list consists of nodes where each node contains:
- **Data**: The value stored in the node
- **Next pointer**: A reference to the next node in the list

**Types of Linked Lists:**
- **Singly Linked List**: Each node points only to the next node; traversal is unidirectional
- **Doubly Linked List**: Each node has pointers to both next and previous nodes; allows bidirectional traversal
- **Circular Linked List**: The last node points back to the first node, forming a circle

The list maintains a reference to the head (first node), and optionally a tail (last node) for efficient append operations.

### Operations

**Access:**
To access an element at index i, start from the head and traverse through i nodes by following the next pointers. There is no direct indexing, so you must traverse sequentially.

**Search:**
Start from the head and traverse the list, comparing each node's data with the target value until found or the end is reached.

**Insert:**
- **At beginning**: Create new node, set its next to current head, update head to new node
- **At end**: Traverse to last node, set its next to new node
- **At position**: Traverse to position-1, set new node's next to current node's next, update current node's next to new node

**Delete:**
- **At beginning**: Update head to head.next
- **At end**: Traverse to second-to-last node, set its next to None
- **At position**: Traverse to position-1, update its next to skip over the target node

**Other Operations:**
- **Reverse**: Reverse the direction of all next pointers
- **Detect cycle**: Use Floyd's cycle detection algorithm (slow and fast pointers)
- **Find middle**: Use two-pointer technique (slow and fast runners)

### Complexities
Access    Ave - O(n)    Worst - O(n)
Search    Ave - O(n)    Worst - O(n)
Insert    Ave - O(1)    Worst - O(1)    [O(n) if position unknown and must traverse]
Delete    Ave - O(1)    Worst - O(1)    [O(n) if position unknown and must traverse]
Space - O(n)

### When to Use
**Advantages:**
- Dynamic size: Can grow or shrink without pre-allocation or reallocation
- Efficient insertion/deletion: O(1) when position is known, no shifting required
- Memory efficiency: Only allocates memory for existing elements
- Easy to implement stacks, queues, and other abstract data types

**Disadvantages:**
- No random access: Must traverse from head to reach any position (O(n))
- Extra memory overhead: Each node requires additional space for pointer(s)
- Poor cache locality: Nodes scattered in memory reduce CPU cache effectiveness
- Reverse traversal difficult: Requires doubly linked list or O(n) reversal

**Common use cases:**
- Implementing stacks and queues
- Managing memory in operating systems (free block lists)
- Undo functionality in applications
- Browser history navigation (doubly linked list)
- Music/video playlist management
- Hash table collision handling (chaining)
- Adjacency lists for graphs

### Visual Representation
```
Singly Linked List:
HEAD
 |
 v
[3|*]-->[7|*]-->[1|*]-->[5|NULL]
 ^       ^       ^       ^
 |       |       |       |
data   data    data    data
next   next    next    next


Doubly Linked List:
HEAD                              TAIL
 |                                 |
 v                                 v
[NULL|3|*]<-->[*|7|*]<-->[*|1|*]<-->[*|5|NULL]
  ^     ^       ^  ^       ^  ^       ^     ^
  |     |       |  |       |  |       |     |
 prev  next   prev next  prev next  prev  next
      data         data       data       data


Circular Linked List:
        HEAD
         |
         v
    +--[3|*]
    |    |
    |    v
    |  [7|*]
    |    |
    |    v
    +<-[1|*]
```

### Implementation(s)

**Python:**
```python
class Node:
    """Node class for singly linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    """Singly linked list implementation."""
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        """Insert node at the beginning. O(1)"""
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        """Insert node at the end. O(n)"""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return

        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def insert_at_position(self, data, position):
        """Insert node at specific position. O(n)"""
        if position == 0:
            self.insert_at_beginning(data)
            return

        new_node = Node(data)
        current = self.head
        for _ in range(position - 1):
            if not current:
                raise IndexError("Position out of bounds")
            current = current.next

        new_node.next = current.next
        current.next = new_node

    def delete_at_beginning(self):
        """Delete first node. O(1)"""
        if not self.head:
            return
        self.head = self.head.next

    def delete_at_end(self):
        """Delete last node. O(n)"""
        if not self.head:
            return

        if not self.head.next:
            self.head = None
            return

        current = self.head
        while current.next.next:
            current = current.next
        current.next = None

    def delete_by_value(self, value):
        """Delete first node with given value. O(n)"""
        if not self.head:
            return

        if self.head.data == value:
            self.head = self.head.next
            return

        current = self.head
        while current.next and current.next.data != value:
            current = current.next

        if current.next:
            current.next = current.next.next

    def search(self, value):
        """Search for value in list. O(n)"""
        current = self.head
        position = 0
        while current:
            if current.data == value:
                return position
            current = current.next
            position += 1
        return -1

    def reverse(self):
        """Reverse the linked list in-place. O(n)"""
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def display(self):
        """Display all elements in the list."""
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        return " -> ".join(elements) + " -> NULL"


# Example usage:
ll = LinkedList()
ll.insert_at_end(3)
ll.insert_at_end(7)
ll.insert_at_beginning(1)
ll.insert_at_position(5, 2)
print(ll.display())  # 1 -> 3 -> 5 -> 7 -> NULL
ll.reverse()
print(ll.display())  # 7 -> 5 -> 3 -> 1 -> NULL
```

### External Links
- [Linked List - Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
- [Linked Lists (GeeksforGeeks)](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Visualgo - Linked List Visualizations](https://visualgo.net/en/list)

---

[Up](./README.md)
