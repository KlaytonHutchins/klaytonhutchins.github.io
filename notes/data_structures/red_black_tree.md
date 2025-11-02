---
layout: default
title: Red-Black Tree
---

### Overview
A Red-Black Tree is a self-balancing binary search tree where each node contains an extra bit for color (red or black), used to ensure the tree remains approximately balanced during insertions and deletions. The balancing properties guarantee that the path from the root to the farthest leaf is no more than twice as long as the path from the root to the nearest leaf, ensuring O(log n) time complexity for all basic operations.

### Structure
A Red-Black Tree is organized as a binary search tree with an additional color property for each node. Every node contains:
- A key value
- A color (red or black)
- Left and right child pointers
- A parent pointer (optional but commonly used)

The tree must satisfy these five critical properties:
1. **Node Color Property**: Every node is either red or black
2. **Root Property**: The root is always black
3. **Leaf Property**: All leaves (NIL nodes) are black
4. **Red Property**: If a node is red, then both its children must be black (no two red nodes can be adjacent)
5. **Black Height Property**: Every path from a node to any of its descendant NIL nodes contains the same number of black nodes (this is called the black-height)

These properties ensure that the tree remains approximately balanced, with the longest path being at most twice the length of the shortest path.

### Operations

**Access:**
Accessing a specific node by index is not a standard operation in Red-Black Trees (unlike arrays). The tree is typically accessed through search operations or tree traversals (in-order, pre-order, post-order).

**Search:**
Search operates identically to a standard binary search tree:
1. Start at the root node
2. Compare the search key with the current node's key
3. If equal, the element is found
4. If less, recurse to the left subtree
5. If greater, recurse to the right subtree
6. If you reach a NIL node, the element doesn't exist

The color properties are ignored during search, making it a standard BST search with O(log n) complexity due to the balanced structure.

**Insert:**
Insertion is a two-phase process:

*Phase 1 - Standard BST Insert:*
1. Insert the new node as in a regular BST (find the correct leaf position)
2. Color the new node RED
3. Set both children to NIL (black leaves)

*Phase 2 - Fix-Up (Rebalancing):*
After insertion, the tree may violate the red-black properties (specifically the "red property"). The fix-up process resolves violations through a series of cases:

- **Case 1**: Uncle is RED - Recolor parent, uncle, and grandparent
- **Case 2**: Uncle is BLACK (triangle configuration) - Rotate to transform into Case 3
- **Case 3**: Uncle is BLACK (line configuration) - Rotate and recolor

The fix-up process involves **recoloring** and **rotations** (left and right) to restore the red-black properties, propagating up the tree until all properties are satisfied.

**Delete:**
Deletion is the most complex operation:

*Phase 1 - Standard BST Delete:*
1. Find the node to delete
2. If it has two children, replace with in-order successor/predecessor
3. Remove the node

*Phase 2 - Fix-Up (Rebalancing):*
If the deleted node was BLACK, the black-height property may be violated. The fix-up process handles several cases:

- **Case 1**: Sibling is RED - Rotate and recolor to transform into other cases
- **Case 2**: Sibling is BLACK with BLACK children - Recolor sibling and propagate problem upward
- **Case 3**: Sibling is BLACK with RED left child (triangle) - Rotate to transform into Case 4
- **Case 4**: Sibling is BLACK with RED right child (line) - Rotate and recolor to finish

The fix-up may require multiple rotations and recoloring operations but still completes in O(log n) time.

**Rotations:**
Left and right rotations are fundamental operations that restructure the tree while maintaining BST properties:
- **Left Rotation**: Pivot node's right child becomes its parent
- **Right Rotation**: Pivot node's left child becomes its parent

Rotations are used extensively during insertion and deletion fix-ups to restore balance.

### Complexities
Access    Ave - O(log n)    Worst - O(log n)
Search    Ave - O(log n)    Worst - O(log n)
Insert    Ave - O(log n)    Worst - O(log n)
Delete    Ave - O(log n)    Worst - O(log n)
Space - O(n)

**Key Performance Notes:**
- The guaranteed O(log n) worst-case performance is the main advantage over regular BSTs
- The self-balancing properties ensure no operation degrades to O(n) as can happen with unbalanced BSTs
- Space overhead is minimal: only one extra bit per node for color storage
- Rotations and recoloring during insert/delete are O(log n) bounded operations

### When to Use
**Advantages:**
- Guaranteed O(log n) worst-case time complexity for search, insert, and delete operations
- More efficient than AVL trees for insert and delete operations (fewer rotations required)
- Simple color bit storage adds minimal memory overhead
- Excellent for applications requiring frequent insertions and deletions with predictable performance
- Well-tested and proven in production systems (Linux kernel, Java libraries, etc.)

**Disadvantages:**
- More complex to implement than basic BSTs or even AVL trees
- Slightly slower search operations compared to AVL trees (AVL trees are more rigidly balanced)
- Debugging and visualization can be challenging due to the color properties
- Not as space-efficient as hash tables for simple key-value lookups
- Overkill for small datasets where simpler structures would suffice

**Common use cases:**
- Java's TreeMap and TreeSet collections
- C++ STL map and set implementations
- Linux kernel's Completely Fair Scheduler (CFS)
- Implementation of associative arrays and priority queues
- Database indexing structures
- Memory management in operating systems
- Any scenario requiring ordered data with frequent insertions/deletions and guaranteed performance

### Visual Representation
```
Example Red-Black Tree (B = Black, R = Red):

                    13(B)
                   /      \
                  /        \
               8(R)         17(R)
              /   \         /    \
             /     \       /      \
          1(B)    11(B)  15(B)   25(B)
                          /      /  \
                         /      /    \
                      NIL    22(R)  27(R)

Properties illustrated:
- Root (13) is BLACK
- All NIL nodes are BLACK (not all shown for clarity)
- No RED node has a RED child (Red property satisfied)
- Every path from root to NIL has same number of BLACK nodes:
  * 13 -> 1 -> NIL: 3 black nodes (13, 1, NIL)
  * 13 -> 11 -> NIL: 3 black nodes (13, 11, NIL)
  * 13 -> 15 -> NIL: 3 black nodes (13, 15, NIL)
  * 13 -> 22 -> NIL: 3 black nodes (13, 25, NIL) - 22 is RED
  * 13 -> 27 -> NIL: 3 black nodes (13, 25, NIL) - 27 is RED

Rotation Example (Right Rotation at node y):

    Before:              After:
       y(?)                x(?)
      /   \               /   \
    x(?)  C      -->    A     y(?)
    / \                       / \
   A   B                     B   C

The colors are preserved according to rotation rules.
```

### Implementation(s)

**Python:**
```python
class Color:
    RED = 0
    BLACK = 1

class Node:
    def __init__(self, key, color=Color.RED):
        self.key = key
        self.color = color
        self.left = None
        self.right = None
        self.parent = None

class RedBlackTree:
    def __init__(self):
        # NIL node is always black and serves as all leaf nodes
        self.NIL = Node(key=None, color=Color.BLACK)
        self.root = self.NIL

    def search(self, key):
        """Search for a key in the tree - O(log n)"""
        current = self.root
        while current != self.NIL:
            if key == current.key:
                return current
            elif key < current.key:
                current = current.left
            else:
                current = current.right
        return None

    def left_rotate(self, x):
        """Perform left rotation at node x"""
        y = x.right
        x.right = y.left

        if y.left != self.NIL:
            y.left.parent = x

        y.parent = x.parent

        if x.parent == None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    def right_rotate(self, y):
        """Perform right rotation at node y"""
        x = y.left
        y.left = x.right

        if x.right != self.NIL:
            x.right.parent = y

        x.parent = y.parent

        if y.parent == None:
            self.root = x
        elif y == y.parent.right:
            y.parent.right = x
        else:
            y.parent.left = x

        x.right = y
        y.parent = x

    def insert(self, key):
        """Insert a key into the tree - O(log n)"""
        # Create new node
        node = Node(key)
        node.left = self.NIL
        node.right = self.NIL

        # Standard BST insert
        parent = None
        current = self.root

        while current != self.NIL:
            parent = current
            if node.key < current.key:
                current = current.left
            else:
                current = current.right

        node.parent = parent

        if parent == None:
            self.root = node
        elif node.key < parent.key:
            parent.left = node
        else:
            parent.right = node

        # New node starts as RED
        node.color = Color.RED

        # Fix any violations
        self._insert_fixup(node)

    def _insert_fixup(self, node):
        """Fix red-black tree properties after insertion"""
        while node.parent and node.parent.color == Color.RED:
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right

                # Case 1: Uncle is RED
                if uncle.color == Color.RED:
                    node.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    node = node.parent.parent
                else:
                    # Case 2: Node is right child (triangle)
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)

                    # Case 3: Node is left child (line)
                    node.parent.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    self.right_rotate(node.parent.parent)
            else:
                # Mirror cases for right subtree
                uncle = node.parent.parent.left

                if uncle.color == Color.RED:
                    node.parent.color = Color.BLACK
                    uncle.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)

                    node.parent.color = Color.BLACK
                    node.parent.parent.color = Color.RED
                    self.left_rotate(node.parent.parent)

        # Ensure root is always black
        self.root.color = Color.BLACK

    def inorder_traversal(self, node=None, result=None):
        """In-order traversal of the tree"""
        if result is None:
            result = []
        if node is None:
            node = self.root

        if node != self.NIL:
            self.inorder_traversal(node.left, result)
            color_str = "R" if node.color == Color.RED else "B"
            result.append(f"{node.key}({color_str})")
            self.inorder_traversal(node.right, result)

        return result

# Example usage:
# rbt = RedBlackTree()
# for key in [7, 3, 18, 10, 22, 8, 11, 26]:
#     rbt.insert(key)
# print("In-order traversal:", rbt.inorder_traversal())
```

### External Links
- [Introduction to Algorithms (CLRS) - Red-Black Trees Chapter](https://en.wikipedia.org/wiki/Introduction_to_Algorithms) - Comprehensive coverage in the definitive algorithms textbook
- [Red-Black Tree Visualization Tool](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) - Interactive visualization for understanding insertions and rotations
- [GeeksforGeeks Red-Black Tree Tutorial](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/) - Detailed explanation with examples and implementation guides

---

[Up](./README.md)
