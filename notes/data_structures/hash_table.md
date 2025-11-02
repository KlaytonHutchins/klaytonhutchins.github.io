---
layout: default
title: Hash Table
---

### Overview
A hash table is a data structure that maps keys to values using a hash function to compute an index into an array of buckets or slots. It provides O(1) average-case time complexity for insertions, deletions, and lookups, making it one of the most efficient data structures for key-value storage and retrieval.

### Structure
A hash table consists of:
- **Hash Function:** Converts keys into array indices (e.g., `hash(key) % table_size`)
- **Buckets/Slots:** An underlying array that stores key-value pairs
- **Collision Handling:** Mechanism to handle when multiple keys hash to the same index

Common collision resolution strategies:
- **Separate Chaining:** Each bucket contains a linked list of entries with the same hash
- **Open Addressing:** Find the next available slot using probing (linear, quadratic, or double hashing)
- **Load Factor:** Ratio of stored entries to table size; when it exceeds a threshold (typically 0.7), the table is resized and rehashed

### Operations

**Access:**
To access a value by key: compute `index = hash(key) % table_size`, then retrieve the value at that bucket. If using separate chaining, traverse the linked list to find the matching key.

**Search:**
Identical to access - use the hash function to find the bucket, then search within that bucket for the key. Returns the associated value if found, or indicates the key doesn't exist.

**Insert:**
Compute the index using the hash function. If the bucket is empty, insert the key-value pair. If occupied, handle the collision using the chosen strategy (append to chain or probe for next slot). If load factor exceeds threshold, resize and rehash all entries.

**Delete:**
Hash the key to find the bucket, locate the key-value pair, and remove it. For separate chaining, remove from the linked list. For open addressing, mark the slot as deleted (tombstone) to maintain probe sequences.

**Resize:**
When the load factor becomes too high, create a new larger array (typically double the size) and rehash all existing entries into the new table to maintain performance.

### Complexities
Access    Ave - O(1)    Worst - O(n)
Search    Ave - O(1)    Worst - O(n)
Insert    Ave - O(1)    Worst - O(n)
Delete    Ave - O(1)    Worst - O(n)
Space - O(n)

Note: Worst case O(n) occurs when all keys hash to the same bucket (all collisions). With a good hash function and proper load factor management, average case O(1) is achieved.

### When to Use
**Advantages:**
- Extremely fast average-case lookups, insertions, and deletions (O(1))
- Flexible key types (any hashable object can be a key)
- Dynamic sizing - can grow as needed
- Simple conceptual model for key-value associations

**Disadvantages:**
- No ordering of elements (keys are not stored in sorted order)
- Requires extra space for the underlying array and collision handling
- Performance depends heavily on quality of hash function
- Worst-case performance can degrade to O(n) with poor hash function or high collisions
- Not cache-friendly due to random memory access patterns

**Common use cases:**
- Implementing dictionaries, maps, and associative arrays
- Database indexing for fast record lookup
- Caching and memoization (storing computed results)
- Counting frequency of elements (histogram/frequency tables)
- Detecting duplicates in datasets
- Symbol tables in compilers and interpreters
- Implementing sets (hash set)

### Visual Representation
```
Hash Table with Separate Chaining:

Index   Bucket
  0   -> [Empty]
  1   -> ["cat": 5] -> ["dog": 3] -> NULL (collision chain)
  2   -> [Empty]
  3   -> ["bird": 8] -> NULL
  4   -> [Empty]
  5   -> ["fish": 2] -> ["frog": 7] -> NULL (collision chain)
  6   -> ["lion": 1] -> NULL
  7   -> [Empty]

Example:
  hash("cat")  % 8 = 1
  hash("dog")  % 8 = 1  (collision, added to chain at index 1)
  hash("fish") % 8 = 5
  hash("frog") % 8 = 5  (collision, added to chain at index 5)

Load Factor = 6 entries / 8 slots = 0.75 (approaching resize threshold)
```

### Implementation(s)

**Python:**
```python
class HashTable:
    def __init__(self, size=8):
        self.size = size
        self.count = 0
        self.buckets = [[] for _ in range(size)]

    def _hash(self, key):
        """Simple hash function using Python's built-in hash."""
        return hash(key) % self.size

    def _resize(self):
        """Resize and rehash when load factor exceeds 0.7."""
        old_buckets = self.buckets
        self.size *= 2
        self.buckets = [[] for _ in range(self.size)]
        self.count = 0

        for bucket in old_buckets:
            for key, value in bucket:
                self.insert(key, value)

    def insert(self, key, value):
        """Insert or update a key-value pair."""
        index = self._hash(key)
        bucket = self.buckets[index]

        # Update if key exists
        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)
                return

        # Insert new key-value pair
        bucket.append((key, value))
        self.count += 1

        # Resize if load factor > 0.7
        if self.count / self.size > 0.7:
            self._resize()

    def search(self, key):
        """Search for a key and return its value."""
        index = self._hash(key)
        bucket = self.buckets[index]

        for k, v in bucket:
            if k == key:
                return v

        raise KeyError(f"Key '{key}' not found")

    def delete(self, key):
        """Delete a key-value pair."""
        index = self._hash(key)
        bucket = self.buckets[index]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                self.count -= 1
                return v

        raise KeyError(f"Key '{key}' not found")

    def __str__(self):
        """String representation of the hash table."""
        result = []
        for i, bucket in enumerate(self.buckets):
            if bucket:
                items = " -> ".join([f"({k}: {v})" for k, v in bucket])
                result.append(f"  {i}: {items}")
        return "HashTable:\n" + "\n".join(result) if result else "HashTable: (empty)"


# Example usage
ht = HashTable()
ht.insert("name", "Alice")
ht.insert("age", 30)
ht.insert("city", "NYC")
print(ht.search("name"))  # Output: Alice
ht.delete("age")
print(ht)
```

### External Links
- [Hash Table - Wikipedia](https://en.wikipedia.org/wiki/Hash_table)
- [Hash Tables - VisuAlgo](https://visualgo.net/en/hashtable)
- [Hash Table Implementation - GeeksforGeeks](https://www.geeksforgeeks.org/hash-table-data-structure/)

---

[Up](./README.md)
