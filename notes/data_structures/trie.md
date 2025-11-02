---
layout: default
title: Trie
---

### Overview
A Trie (pronounced "try"), also known as a prefix tree or digital tree, is a tree-based data structure specialized for storing and retrieving strings efficiently, where each node represents a single character and paths from root to leaf form complete words. It excels at prefix-based operations, making it ideal for autocomplete systems, spell checkers, and dictionary implementations.

### Structure
A Trie is organized as a tree where:
- The root node is typically empty and serves as the starting point
- Each node contains a mapping (usually a hashmap or array) from characters to child nodes
- Each node has a boolean flag indicating whether it marks the end of a valid word
- Paths from the root to nodes with the end-of-word flag represent complete strings stored in the trie
- Common prefixes are shared among words, reducing redundant storage
- For example, storing "cat", "car", and "card" creates a shared path "ca" with branches for "t" and "r"

### Operations

**Search:**
To search for a word, traverse from the root following the character path. Start at the root and for each character in the word, move to the corresponding child node. If at any point the path doesn't exist, the word is not in the trie. If you successfully traverse all characters, check if the final node is marked as end-of-word.

**Insert:**
To insert a word, traverse the trie character by character. For each character, if a child node exists, move to it; otherwise, create a new node and add it as a child. After processing all characters, mark the final node as end-of-word.

**Delete:**
To delete a word, first verify it exists in the trie. Then remove the end-of-word marker from the final node. Optionally, prune nodes that are no longer part of any word by recursively removing childless nodes that don't mark word endings, working backwards from the deleted word's end.

**Prefix Operations:**
- **startsWith(prefix):** Similar to search, but only check if the path exists without requiring an end-of-word marker
- **autocomplete(prefix):** Find all words with a given prefix by first navigating to the prefix node, then performing DFS/BFS to collect all words in that subtree
- **longestCommonPrefix():** Find the longest shared prefix among all words by traversing down the trie while each node has exactly one child

### Complexities
Search    Ave - O(m)    Worst - O(m)
Insert    Ave - O(m)    Worst - O(m)
Delete    Ave - O(m)    Worst - O(m)
Space - O(ALPHABET_SIZE * N * M)

Where:
- m = length of the string being operated on
- N = number of strings stored
- M = average length of strings
- ALPHABET_SIZE = size of character set (e.g., 26 for lowercase English letters)

### When to Use
**Advantages:**
- Extremely fast prefix-based searches - O(m) where m is string length, independent of number of stored strings
- Efficient storage of strings with common prefixes through shared nodes
- No hash collisions unlike hash tables
- Alphabetically ordered traversal through in-order tree traversal
- Predictable performance - no worst-case hash collisions or rebalancing like other structures

**Disadvantages:**
- High memory overhead - each node may store an array/map for all possible characters
- Cache-unfriendly due to pointer chasing across non-contiguous memory
- Slower than hash tables for simple exact-match lookups
- More complex to implement than basic data structures
- Requires more space than alternatives when strings don't share prefixes

**Common use cases:**
- Autocomplete and search suggestions in search engines and IDEs
- Spell checkers and word validation in text editors
- IP routing tables (longest prefix matching)
- Dictionary implementations with prefix queries
- T9 predictive text on old mobile phones
- Solving word game problems (Boggle, Scrabble validation)
- DNA sequence analysis and genome research

### Visual Representation
```
Example Trie containing words: "cat", "cats", "car", "card", "dog", "dodge"

                    (root)
                   /      \
                  c        d
                  |        |
                  a        o
                 / \       |
                t   r      g
               /    |      |
              s     d     (e)
             (*)    |      *
                   (*)
                    *

Legend:
- Each letter is a node
- Nodes marked with (*) indicate end of a valid word
- Paths from root spell out words:
  * root -> c -> a -> t (*)         = "cat"
  * root -> c -> a -> t -> s (*)    = "cats"
  * root -> c -> a -> r (*)         = "car"
  * root -> c -> a -> r -> d (*)    = "card"
  * root -> d -> o -> g (*)         = "dog"
  * root -> d -> o -> d -> g -> e (*) = "dodge"

Note: "ca" is a shared prefix for "cat", "cats", "car", "card"
      "do" is a shared prefix for "dog", "dodge"
```

### Implementation(s)

**Python:**
```python
class TrieNode:
    def __init__(self):
        self.children = {}  # Map from character to TrieNode
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """Insert a word into the trie. O(m) time where m is word length."""
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """Search for exact word match. O(m) time."""
        node = self._find_node(word)
        return node is not None and node.is_end_of_word

    def starts_with(self, prefix: str) -> bool:
        """Check if any word starts with given prefix. O(m) time."""
        return self._find_node(prefix) is not None

    def _find_node(self, prefix: str) -> TrieNode:
        """Helper to navigate to the node at end of prefix."""
        node = self.root
        for char in prefix:
            if char not in node.children:
                return None
            node = node.children[char]
        return node

    def delete(self, word: str) -> bool:
        """Delete a word from the trie. Returns True if deleted."""
        def _delete_helper(node: TrieNode, word: str, index: int) -> bool:
            if index == len(word):
                if not node.is_end_of_word:
                    return False  # Word doesn't exist
                node.is_end_of_word = False
                return len(node.children) == 0  # Can delete if no children

            char = word[index]
            if char not in node.children:
                return False

            child = node.children[char]
            should_delete = _delete_helper(child, word, index + 1)

            if should_delete:
                del node.children[char]
                return len(node.children) == 0 and not node.is_end_of_word

            return False

        return _delete_helper(self.root, word, 0)

    def autocomplete(self, prefix: str) -> list:
        """Find all words with given prefix."""
        node = self._find_node(prefix)
        if not node:
            return []

        results = []
        self._collect_words(node, prefix, results)
        return results

    def _collect_words(self, node: TrieNode, current_word: str, results: list):
        """DFS to collect all words from a given node."""
        if node.is_end_of_word:
            results.append(current_word)

        for char, child in node.children.items():
            self._collect_words(child, current_word + char, results)

# Usage example
trie = Trie()
trie.insert("cat")
trie.insert("cats")
trie.insert("car")
trie.insert("card")

print(trie.search("cat"))        # True
print(trie.search("ca"))         # False (not a complete word)
print(trie.starts_with("ca"))    # True
print(trie.autocomplete("ca"))   # ['cat', 'cats', 'car', 'card']
```

### External Links
- [Wikipedia - Trie](https://en.wikipedia.org/wiki/Trie)
- [LeetCode - Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [GeeksforGeeks - Trie Data Structure](https://www.geeksforgeeks.org/trie-insert-and-search/)

---

[Up](./README.md)
