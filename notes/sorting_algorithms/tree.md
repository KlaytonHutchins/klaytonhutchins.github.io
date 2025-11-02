---
layout: default
title: Tree Sort
---

### Overview
Tree Sort is a sorting algorithm that builds a Binary Search Tree (BST) from the input elements and then performs an in-order traversal to retrieve the elements in sorted order. It leverages the property of BSTs where the left subtree contains smaller values and the right subtree contains larger values.

### How It Works
1. **Create an empty Binary Search Tree (BST)**: Start with no nodes in the tree.
2. **Insert each element**: For each element in the input array, insert it into the BST following BST insertion rules:
   - If the tree is empty, create the root node
   - If the value is less than the current node, go to the left subtree
   - If the value is greater than or equal to the current node, go to the right subtree
   - Repeat until finding an empty position and insert the new node
3. **Perform in-order traversal**: Traverse the BST in-order (left subtree, root, right subtree) to retrieve elements in sorted ascending order.
4. **Store results**: Collect the visited elements during traversal into the output array.

### Complexities
Best Case - O(n log n) - when the tree is balanced
Average Case - O(n log n) - when insertions create a reasonably balanced tree
Worst Case - O(n²) - when the tree becomes skewed (e.g., inserting already sorted data)
Space - O(n) - for storing the tree nodes

### When to Use
**Advantages:**
- Simple and intuitive implementation using BST properties
- Can be efficient with balanced trees (O(n log n) average case)
- In-place traversal doesn't require additional sorting space beyond the tree structure
- Naturally handles duplicate values

**Disadvantages:**
- Degrades to O(n²) with already sorted or reverse-sorted input (creates skewed tree)
- Requires O(n) extra space for tree nodes
- Slower in practice than optimized algorithms like Quick Sort or Merge Sort
- Not stable - doesn't preserve the relative order of equal elements

**Best suited for:**
- Educational purposes to understand BST properties and tree traversals
- Small datasets where simplicity is valued over performance
- When data is being inserted dynamically and needs to be retrieved in sorted order periodically
- Situations where a self-balancing BST variant (like AVL or Red-Black tree) can be used to guarantee O(n log n)

### Example Walkthrough
Sorting the array [5, 2, 8, 1, 9]:

```
Step 1: Insert 5 (root)
    5

Step 2: Insert 2 (2 < 5, goes left)
    5
   /
  2

Step 3: Insert 8 (8 > 5, goes right)
    5
   / \
  2   8

Step 4: Insert 1 (1 < 5, go left; 1 < 2, goes left of 2)
    5
   / \
  2   8
 /
1

Step 5: Insert 9 (9 > 5, go right; 9 > 8, goes right of 8)
    5
   / \
  2   8
 /     \
1       9

Step 6: In-order traversal (left, root, right)
Visit left subtree of 5:
  Visit left subtree of 2:
    Visit 1 -> [1]
  Visit 2 -> [1, 2]
Visit 5 -> [1, 2, 5]
Visit right subtree of 5:
  Visit 8 -> [1, 2, 5, 8]
  Visit right subtree of 8:
    Visit 9 -> [1, 2, 5, 8, 9]

Final sorted array: [1, 2, 5, 8, 9]
```

### Implementation(s)

**Python:**
```python
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class TreeSort:
    def __init__(self):
        self.root = None

    def insert(self, value):
        """Insert a value into the BST."""
        if self.root is None:
            self.root = TreeNode(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, node, value):
        """Helper method to recursively insert a value."""
        if value < node.value:
            if node.left is None:
                node.left = TreeNode(value)
            else:
                self._insert_recursive(node.left, value)
        else:
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert_recursive(node.right, value)

    def inorder_traversal(self, node, result):
        """Perform in-order traversal and collect values."""
        if node is not None:
            self.inorder_traversal(node.left, result)
            result.append(node.value)
            self.inorder_traversal(node.right, result)

    def sort(self, arr):
        """Main sorting function."""
        # Build the BST
        for value in arr:
            self.insert(value)

        # Perform in-order traversal to get sorted array
        result = []
        self.inorder_traversal(self.root, result)
        return result

# Usage
def tree_sort(arr):
    tree = TreeSort()
    return tree.sort(arr)

# Example
arr = [5, 2, 8, 1, 9]
sorted_arr = tree_sort(arr)
print(sorted_arr)  # Output: [1, 2, 5, 8, 9]
```

### External Links
- [GeeksforGeeks - Tree Sort](https://www.geeksforgeeks.org/tree-sort/)
- [Wikipedia - Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- [Programiz - Tree Sort Algorithm](https://www.programiz.com/dsa/tree-sort)

---

[Up](./README.md)
