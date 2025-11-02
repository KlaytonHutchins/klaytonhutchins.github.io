---
layout: default
title: AVL Tree
---

### Overview
An AVL tree is a self-balancing binary search tree named after inventors Adelson-Velsky and Landis. It maintains a strict height balance property where the heights of the two child subtrees of any node differ by at most one, guaranteeing O(log n) time complexity for all operations.

### Structure
An AVL tree is organized as a binary search tree where each node contains:
- A key (and optional value)
- Pointers to left and right children
- A height or balance factor

The **balance factor** of a node is calculated as: `height(left subtree) - height(right subtree)`. In a valid AVL tree, every node's balance factor must be -1, 0, or +1.

**Balance Property:** For every node N, the height difference between its left and right subtrees is at most 1: `|height(N.left) - height(N.right)| <= 1`

When insertions or deletions violate this property, the tree performs rotations to restore balance. The tree uses four types of rotations:
- **Left Rotation (LL):** Used when right subtree is too tall
- **Right Rotation (RR):** Used when left subtree is too tall
- **Left-Right Rotation (LR):** Used for left-heavy then right-heavy imbalance
- **Right-Left Rotation (RL):** Used for right-heavy then left-heavy imbalance

### Operations

**Access:**
Accessing elements by index is not directly supported. To access the nth smallest element, you would need to perform an in-order traversal, which takes O(n) time. AVL trees are optimized for key-based operations, not index-based access.

**Search:**
Search follows the standard BST algorithm:
1. Start at the root
2. Compare the search key with the current node's key
3. If equal, return the node
4. If less, search the left subtree
5. If greater, search the right subtree
6. If null is reached, the key is not in the tree

Time complexity: O(log n) due to guaranteed balance

**Insert:**
Insertion follows BST insertion, then rebalances:
1. Perform standard BST insert (find correct leaf position)
2. Update heights of all ancestor nodes
3. Find the first unbalanced node (if any) on the path from inserted node to root
4. Determine which of the four rotation cases applies:
   - **Left-Left (LL):** New node in left subtree of left child -> Right rotation
   - **Right-Right (RR):** New node in right subtree of right child -> Left rotation
   - **Left-Right (LR):** New node in right subtree of left child -> Left rotation on child, then right rotation on parent
   - **Right-Left (RL):** New node in left subtree of right child -> Right rotation on child, then left rotation on parent
5. Perform the appropriate rotation(s) to restore balance

**Delete:**
Deletion combines BST deletion with rebalancing:
1. Perform standard BST deletion (three cases: no child, one child, two children)
2. Update heights of all ancestor nodes
3. Starting from the deleted node's parent, check balance at each ancestor
4. If any node is unbalanced, perform appropriate rotation(s)
5. Continue checking up to the root (multiple rotations may be needed)

Note: Unlike insertion, deletion may require O(log n) rotations in the worst case.

**Traversal:**
AVL trees support all standard tree traversals (in-order, pre-order, post-order, level-order) with the same time complexities as regular BSTs.

### Complexities
Access    Ave - O(log n)    Worst - O(log n)
Search    Ave - O(log n)    Worst - O(log n)
Insert    Ave - O(log n)    Worst - O(log n)
Delete    Ave - O(log n)    Worst - O(log n)
Space - O(n)

### When to Use
**Advantages:**
- Guaranteed O(log n) time complexity for search, insert, and delete operations
- More strictly balanced than Red-Black trees, resulting in faster lookups
- Predictable performance - no worst-case degradation to O(n) like unbalanced BSTs
- Efficient for read-heavy workloads where searches outnumber insertions/deletions
- Maintains sorted order, allowing efficient in-order traversal

**Disadvantages:**
- More complex implementation than basic BST due to rotation logic
- Slower insertions and deletions compared to Red-Black trees (more rotations required)
- Each node requires extra storage for height/balance factor
- Rebalancing overhead makes it less suitable for write-heavy workloads
- Not cache-friendly due to pointer-based structure

**Common use cases:**
- Database indexing where read operations dominate
- In-memory lookups that require guaranteed performance
- Implementing ordered sets and maps when balance guarantees are critical
- File systems and memory management (when combined with other structures)
- Network routing tables where fast lookups are essential
- Auto-complete and spell-checker dictionaries

### Visual Representation
```
Basic AVL Tree Structure (with balance factors shown):

        50(0)
       /     \
    30(0)    70(-1)
   /   \        \
 20(0) 40(0)   80(0)

Balance Factor = height(left) - height(right)
- 50: BF = 0 (balanced)
- 70: BF = -1 (slightly right-heavy, still valid)
- All others: BF = 0


Right Rotation (used for Left-Left case):

Before:              After:
    z                  y
   /                  / \
  y        ------>   x   z
 /
x

Left Rotation (used for Right-Right case):

Before:              After:
  x                    y
   \                  / \
    y      ------>   x   z
     \
      z


Left-Right Rotation (used for Left-Right case):

Step 1: Left rotate on y     Step 2: Right rotate on z
    z                            z                    y
   /                            /                    / \
  x            ------>         y        ------>     x   z
   \                          /
    y                        x


Right-Left Rotation (used for Right-Left case):

Step 1: Right rotate on y    Step 2: Left rotate on x
  x                            x                      y
   \                            \                    / \
    z          ------>           y      ------>     x   z
   /                              \
  y                                z


Example: Inserting 3, 2, 1 into an empty AVL tree

Insert 3:        Insert 2:        Unbalanced!      After Right Rotation:
    3               3               3(2)                  2(0)
                   /               /                     /   \
                  2               2(1)                 1(0)  3(0)
                                 /
                                1(0)

               Balance Factor > 1, so rotate right on node 3
```

### Implementation(s)

**Python:**
```python
class AVLNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def update_height(self, node):
        if not node:
            return
        node.height = 1 + max(self.get_height(node.left),
                              self.get_height(node.right))

    def rotate_right(self, z):
        """Right rotation for Left-Left case"""
        y = z.left
        T3 = y.right

        # Perform rotation
        y.right = z
        z.left = T3

        # Update heights
        self.update_height(z)
        self.update_height(y)

        return y  # New root

    def rotate_left(self, x):
        """Left rotation for Right-Right case"""
        y = x.right
        T2 = y.left

        # Perform rotation
        y.left = x
        x.right = T2

        # Update heights
        self.update_height(x)
        self.update_height(y)

        return y  # New root

    def insert(self, node, key):
        # 1. Perform normal BST insertion
        if not node:
            return AVLNode(key)

        if key < node.key:
            node.left = self.insert(node.left, key)
        elif key > node.key:
            node.right = self.insert(node.right, key)
        else:
            return node  # Duplicate keys not allowed

        # 2. Update height of current node
        self.update_height(node)

        # 3. Get balance factor
        balance = self.get_balance(node)

        # 4. If unbalanced, perform rotations

        # Left-Left Case
        if balance > 1 and key < node.left.key:
            return self.rotate_right(node)

        # Right-Right Case
        if balance < -1 and key > node.right.key:
            return self.rotate_left(node)

        # Left-Right Case
        if balance > 1 and key > node.left.key:
            node.left = self.rotate_left(node.left)
            return self.rotate_right(node)

        # Right-Left Case
        if balance < -1 and key < node.right.key:
            node.right = self.rotate_right(node.right)
            return self.rotate_left(node)

        return node

    def get_min_value_node(self, node):
        current = node
        while current.left:
            current = current.left
        return current

    def delete(self, node, key):
        # 1. Perform standard BST delete
        if not node:
            return node

        if key < node.key:
            node.left = self.delete(node.left, key)
        elif key > node.key:
            node.right = self.delete(node.right, key)
        else:
            # Node with one child or no child
            if not node.left:
                return node.right
            elif not node.right:
                return node.left

            # Node with two children: get inorder successor
            temp = self.get_min_value_node(node.right)
            node.key = temp.key
            node.right = self.delete(node.right, temp.key)

        if not node:
            return node

        # 2. Update height
        self.update_height(node)

        # 3. Get balance factor
        balance = self.get_balance(node)

        # 4. Balance the tree

        # Left-Left Case
        if balance > 1 and self.get_balance(node.left) >= 0:
            return self.rotate_right(node)

        # Left-Right Case
        if balance > 1 and self.get_balance(node.left) < 0:
            node.left = self.rotate_left(node.left)
            return self.rotate_right(node)

        # Right-Right Case
        if balance < -1 and self.get_balance(node.right) <= 0:
            return self.rotate_left(node)

        # Right-Left Case
        if balance < -1 and self.get_balance(node.right) > 0:
            node.right = self.rotate_right(node.right)
            return self.rotate_left(node)

        return node

    def search(self, node, key):
        if not node or node.key == key:
            return node

        if key < node.key:
            return self.search(node.left, key)

        return self.search(node.right, key)

    def inorder(self, node):
        """In-order traversal: Left -> Root -> Right"""
        if node:
            self.inorder(node.left)
            print(node.key, end=' ')
            self.inorder(node.right)

# Example usage:
# tree = AVLTree()
# root = None
# keys = [10, 20, 30, 40, 50, 25]
# for key in keys:
#     root = tree.insert(root, key)
# tree.inorder(root)  # Prints: 10 20 25 30 40 50
```

### External Links
- [AVL Tree Visualization Tool - VisuAlgo](https://visualgo.net/en/bst) - Interactive visualization showing AVL tree operations and rotations
- [GeeksforGeeks - AVL Tree Guide](https://www.geeksforgeeks.org/introduction-to-avl-tree/) - Comprehensive tutorial with examples and code
- [Wikipedia - AVL Tree](https://en.wikipedia.org/wiki/AVL_tree) - Detailed mathematical analysis and history

---

[Up](./README.md)
