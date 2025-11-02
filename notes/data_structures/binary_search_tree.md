---
layout: default
title: Binary Search Tree
---

### Overview
A Binary Search Tree (BST) is a node-based binary tree data structure where each node has at most two children, and for every node, all values in its left subtree are less than the node's value, and all values in its right subtree are greater than the node's value. This ordering property enables efficient searching, insertion, and deletion operations.

### Structure
A BST consists of nodes, where each node contains:
- A value (or key)
- A pointer to the left child (containing smaller values)
- A pointer to the right child (containing larger values)
- Optionally, a pointer to the parent node

The BST property states that for any node N:
- All nodes in the left subtree have values < N.value
- All nodes in the right subtree have values > N.value
- Both left and right subtrees are also BSTs

The tree has a root node (topmost node), and nodes with no children are called leaves. The height of the tree is the longest path from root to any leaf, which determines the efficiency of operations.

### Operations

**Access:**
Accessing a specific element requires searching from the root. At each node, compare the target value with the current node's value and traverse left (if smaller) or right (if larger) until found or reaching a null pointer.

**Search:**
Start at the root and compare the search value with the current node. If equal, return the node. If the search value is less, recursively search the left subtree; if greater, search the right subtree. Return null if a leaf is reached without finding the value.

**Insert:**
Start at the root and compare the new value with each node. Traverse left if the value is smaller, right if larger, until finding an empty spot (null pointer). Create a new node and attach it at that position, maintaining the BST property.

**Delete:**
Three cases exist:
1. Node has no children (leaf): Simply remove it
2. Node has one child: Replace the node with its child
3. Node has two children: Find the in-order successor (smallest node in right subtree) or predecessor (largest in left subtree), replace the node's value with it, then delete the successor/predecessor

**Traversals:**
- **In-order** (Left, Root, Right): Visits nodes in ascending sorted order
- **Pre-order** (Root, Left, Right): Useful for copying the tree
- **Post-order** (Left, Right, Root): Useful for deleting the tree
- **Level-order**: Breadth-first traversal using a queue

### Complexities
Access    Ave - O(log n)    Worst - O(n)
Search    Ave - O(log n)    Worst - O(n)
Insert    Ave - O(log n)    Worst - O(n)
Delete    Ave - O(log n)    Worst - O(n)
Space - O(n)

Note: Average case assumes a balanced tree. Worst case occurs when the tree degenerates into a linked list (e.g., inserting sorted data without balancing).

### When to Use
**Advantages:**
- Efficient searching, insertion, and deletion in O(log n) average time
- Elements are naturally maintained in sorted order
- No need for resizing like arrays or hash tables
- In-order traversal yields sorted sequence
- Flexible structure that grows dynamically

**Disadvantages:**
- No guaranteed O(log n) operations - degenerates to O(n) if unbalanced
- More memory overhead than arrays (storing pointers)
- Not cache-friendly due to non-contiguous memory
- More complex to implement than linear structures
- Requires balancing strategies (like AVL or Red-Black trees) for guaranteed performance

**Common use cases:**
- Database indexing and searching
- Implementing associative arrays/maps
- Expression parsing and syntax trees in compilers
- File system organization
- Autocomplete and dictionary implementations
- Priority queue implementation (though heaps are more common)
- Range queries and finding closest values

### Visual Representation
```
Example BST with values: 50, 30, 70, 20, 40, 60, 80

           50
          /  \
        30    70
       / \    / \
      20  40 60  80

BST Property illustrated:
- All left descendants of 50 (20, 30, 40) are less than 50
- All right descendants of 50 (60, 70, 80) are greater than 50
- Same property holds for every subtree

Unbalanced (degenerate) BST - inserting sorted data:
    10
      \
       20
         \
          30
            \
             40
               \
                50
This degrades to O(n) performance, acting like a linked list.
```

### Implementation(s)

**Python:**
```python
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        """Insert a value into the BST"""
        if self.root is None:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = Node(value)
            else:
                self._insert_recursive(node.left, value)
        else:  # value >= node.value (allow duplicates on right)
            if node.right is None:
                node.right = Node(value)
            else:
                self._insert_recursive(node.right, value)

    def search(self, value):
        """Search for a value in the BST"""
        return self._search_recursive(self.root, value)

    def _search_recursive(self, node, value):
        if node is None:
            return False
        if value == node.value:
            return True
        elif value < node.value:
            return self._search_recursive(node.left, value)
        else:
            return self._search_recursive(node.right, value)

    def delete(self, value):
        """Delete a value from the BST"""
        self.root = self._delete_recursive(self.root, value)

    def _delete_recursive(self, node, value):
        if node is None:
            return None

        if value < node.value:
            node.left = self._delete_recursive(node.left, value)
        elif value > node.value:
            node.right = self._delete_recursive(node.right, value)
        else:
            # Node to delete found
            # Case 1: No children (leaf)
            if node.left is None and node.right is None:
                return None
            # Case 2: One child
            elif node.left is None:
                return node.right
            elif node.right is None:
                return node.left
            # Case 3: Two children
            else:
                # Find in-order successor (minimum in right subtree)
                successor = self._find_min(node.right)
                node.value = successor.value
                node.right = self._delete_recursive(node.right, successor.value)

        return node

    def _find_min(self, node):
        """Find the node with minimum value"""
        current = node
        while current.left is not None:
            current = current.left
        return current

    def inorder_traversal(self):
        """Return list of values in sorted order"""
        result = []
        self._inorder_recursive(self.root, result)
        return result

    def _inorder_recursive(self, node, result):
        if node is not None:
            self._inorder_recursive(node.left, result)
            result.append(node.value)
            self._inorder_recursive(node.right, result)

# Example usage:
bst = BinarySearchTree()
values = [50, 30, 70, 20, 40, 60, 80]
for val in values:
    bst.insert(val)

print(bst.search(40))  # True
print(bst.search(25))  # False
print(bst.inorder_traversal())  # [20, 30, 40, 50, 60, 70, 80]
```

### External Links
- [Visualgo - Binary Search Tree Visualizer](https://visualgo.net/en/bst) - Interactive visualization of BST operations
- [GeeksforGeeks - Binary Search Tree](https://www.geeksforgeeks.org/binary-search-tree-data-structure/) - Comprehensive tutorial with examples
- [Wikipedia - Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree) - Detailed theoretical background

---

[Up](./README.md)
