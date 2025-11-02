---
layout: default
title: B-Tree
---

### Overview
A B-Tree is a self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time, optimized for systems that read and write large blocks of data such as databases and file systems. Unlike binary search trees, B-Trees can have multiple keys per node and more than two children, which minimizes disk I/O operations by reducing tree height.

### Structure
A B-Tree of order (degree) **m** has the following properties:

- **Multiple keys per node:** Each node can contain between ⌈m/2⌉-1 and m-1 keys (except the root)
- **Sorted keys:** Keys within a node are stored in sorted order
- **Children pointers:** A node with k keys has k+1 children
- **Root constraints:** The root has at least 2 children (unless it's a leaf) and at least 1 key
- **Internal node constraints:** All internal nodes have at least ⌈m/2⌉ children and at least ⌈m/2⌉-1 keys
- **Leaf nodes:** All leaf nodes appear at the same level, maintaining perfect balance
- **Key separation:** For a node with keys k₁, k₂, ..., kₙ, all keys in the i-th child subtree are between kᵢ₋₁ and kᵢ

Each node typically contains:
- An array of keys (sorted)
- An array of child pointers
- A flag indicating whether the node is a leaf
- The current number of keys in the node

### Operations

**Access:**
Accessing an element by index is not typically supported efficiently in B-Trees, as they are optimized for key-based searches rather than positional access. However, range queries and sequential access through traversal are supported efficiently.

**Search:**
1. Start at the root node
2. Within the current node, perform binary search to find the key or determine which child subtree to explore
3. If the key is found, return success
4. If the current node is a leaf and the key is not found, return failure
5. Otherwise, follow the appropriate child pointer and repeat from step 2

**Insert:**
1. Search for the appropriate leaf node where the key should be inserted
2. If the leaf has space (fewer than m-1 keys), insert the key in sorted order
3. If the leaf is full, perform a **split operation:**
   - Create a new node
   - Move the median key up to the parent node
   - Distribute remaining keys between the original and new node
   - If the parent is also full, recursively split upward
   - If the root splits, create a new root (increases tree height by 1)

**Delete:**
Deletion is the most complex operation, with several cases:

1. **Key in a leaf node:**
   - Simply remove the key
   - If the node becomes underfull (fewer than ⌈m/2⌉-1 keys), rebalance by borrowing from a sibling or merging with a sibling

2. **Key in an internal node:**
   - Replace the key with its predecessor (maximum key from left subtree) or successor (minimum key from right subtree)
   - Delete the predecessor/successor from the leaf node
   - Rebalance if necessary

3. **Rebalancing operations:**
   - **Borrow from sibling:** If a sibling has more than the minimum keys, move a key from parent down and a key from sibling up
   - **Merge with sibling:** If siblings have minimum keys, merge the node with a sibling and pull down a key from the parent
   - If merging causes the parent to become underfull, recursively rebalance upward

**Traversal:**
In-order traversal visits all keys in sorted order by recursively visiting left subtrees, processing keys, and visiting right subtrees.

### Complexities
Access    Ave - O(log n)    Worst - O(log n)
Search    Ave - O(log n)    Worst - O(log n)
Insert    Ave - O(log n)    Worst - O(log n)
Delete    Ave - O(log n)    Worst - O(log n)
Space - O(n)

Note: The logarithm base depends on the tree order (m). Higher order means shorter, wider trees with fewer disk accesses.

### When to Use
**Advantages:**
- Optimized for disk-based storage systems with excellent cache performance
- Minimizes expensive disk I/O operations by storing multiple keys per node
- Guarantees logarithmic time for all operations with very shallow tree height
- Maintains perfect balance automatically without rotations like AVL trees
- Excellent for range queries and sequential access patterns
- High fanout reduces the number of nodes to traverse

**Disadvantages:**
- More complex implementation than binary search trees
- Higher memory overhead per node due to arrays of keys and children
- Overkill for in-memory data structures (simpler structures often perform better)
- Deletion operation is particularly complex with multiple cases
- Requires careful tuning of the order/degree parameter for optimal performance

**Common use cases:**
- Database indexing systems (B-Trees and B+ Trees are fundamental to most databases)
- File system implementations (NTFS, HFS+, ext4, Btrfs)
- Storage systems that need to minimize disk seeks
- Any application requiring sorted data with frequent insertions and deletions
- Multilevel indexing in large datasets

### Visual Representation
```
Example: B-Tree of order 5 (max 4 keys per node, max 5 children)

                    [30|60]
                   /   |   \
                  /    |    \
                 /     |     \
          [10|20]  [40|50]  [70|80|90]
          /  |  \   / | \    / | | \
         /   |   \ /  |  \  /  | |  \
       [5] [15] [25][35][45][55][65][75][85][95]

Properties illustrated:
- Root has 2 keys (30, 60) and 3 children
- Internal nodes have 2-4 keys
- All leaf nodes are at the same level (depth 2)
- Keys are sorted within each node
- For node [30|60]: left child has keys < 30, middle has 30 < keys < 60, right has keys > 60


Insert 27 into the tree above:
1. Search finds position in node [25]
2. Node [25] has space, but after insert would be [25|27]
3. Node [10|20] would get [10|20|25|27] - still fits (4 keys max)

Result after inserting 27:
                    [30|60]
                   /   |   \
                  /    |    \
                 /     |     \
       [10|20|25]  [40|50]  [70|80|90]
          /  |  |  \ / | \    / | | \
         /   |  |   X  |  \  /  | |  \
       [5] [15][27][35][45][55][65][75][85][95]
```

### Implementation(s)

**Python:**
```python
class BTreeNode:
    def __init__(self, leaf=True):
        self.keys = []
        self.children = []
        self.leaf = leaf

    def split(self):
        """Split this node and return the median key and new right node"""
        mid = len(self.keys) // 2
        median_key = self.keys[mid]

        # Create new right node
        right_node = BTreeNode(leaf=self.leaf)
        right_node.keys = self.keys[mid + 1:]
        self.keys = self.keys[:mid]

        # Split children if not a leaf
        if not self.leaf:
            right_node.children = self.children[mid + 1:]
            self.children = self.children[:mid + 1]

        return median_key, right_node

    def insert_non_full(self, key):
        """Insert key into node that is not full"""
        i = len(self.keys) - 1

        if self.leaf:
            # Insert into sorted position
            self.keys.append(None)
            while i >= 0 and key < self.keys[i]:
                self.keys[i + 1] = self.keys[i]
                i -= 1
            self.keys[i + 1] = key
        else:
            # Find child to insert into
            while i >= 0 and key < self.keys[i]:
                i -= 1
            i += 1

            # Split child if full
            if len(self.children[i].keys) == (2 * t - 1):
                median, new_child = self.children[i].split()
                self.keys.insert(i, median)
                self.children.insert(i + 1, new_child)

                if key > median:
                    i += 1

            self.children[i].insert_non_full(key)

    def search(self, key):
        """Search for a key in the subtree rooted at this node"""
        i = 0
        while i < len(self.keys) and key > self.keys[i]:
            i += 1

        if i < len(self.keys) and key == self.keys[i]:
            return True
        elif self.leaf:
            return False
        else:
            return self.children[i].search(key)


class BTree:
    def __init__(self, degree=3):
        """Initialize B-Tree with minimum degree t (order = 2*t)"""
        global t
        t = degree
        self.root = BTreeNode()

    def search(self, key):
        """Search for a key in the B-Tree"""
        return self.root.search(key) if self.root else False

    def insert(self, key):
        """Insert a key into the B-Tree"""
        root = self.root

        # If root is full, split it
        if len(root.keys) == (2 * t - 1):
            new_root = BTreeNode(leaf=False)
            new_root.children.append(self.root)
            median, new_child = root.split()
            new_root.keys.append(median)
            new_root.children.append(new_child)
            self.root = new_root
            new_root.insert_non_full(key)
        else:
            root.insert_non_full(key)

    def traverse(self):
        """In-order traversal of the B-Tree"""
        def _traverse(node):
            result = []
            i = 0
            for i in range(len(node.keys)):
                if not node.leaf:
                    result.extend(_traverse(node.children[i]))
                result.append(node.keys[i])

            if not node.leaf:
                result.extend(_traverse(node.children[i + 1]))

            return result

        return _traverse(self.root) if self.root else []


# Example usage:
btree = BTree(degree=3)  # Order 6 B-Tree (max 5 keys per node)
for key in [10, 20, 5, 6, 12, 30, 7, 17]:
    btree.insert(key)

print(btree.search(6))   # True
print(btree.search(15))  # False
print(btree.traverse())  # [5, 6, 7, 10, 12, 17, 20, 30]
```

Note: This is a simplified implementation. A complete implementation would include deletion with all rebalancing cases, which is significantly more complex.

### External Links
- [B-Tree Visualization Tool - University of San Francisco](https://www.cs.usfca.edu/~galles/visualization/BTree.html)
- [GeeksforGeeks - Introduction to B-Tree](https://www.geeksforgeeks.org/introduction-of-b-tree-2/)
- [Wikipedia - B-Tree](https://en.wikipedia.org/wiki/B-tree)

---

[Up](./README.md)
