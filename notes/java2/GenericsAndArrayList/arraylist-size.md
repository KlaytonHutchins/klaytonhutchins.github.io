---
layout: default
title: `ArrayList` - Size vs. Capacity
---


The `size()` of an `ArrayList` is the number of elements in the list, _not_ the `length` of the internal array.

### `ArrayList` Capacity

The `length` of the internal array is the `ArrayList`'s _capacity_.
* The default capacity in Oracle's `ArrayList` is `10`.

When the internal array is full, the `ArrayList` will grow the capacity by creating a new internal array and copying all references from the old array to the new one.
* The size of the new array in Oracle's implementation is `capacity + capacity/2 + 1`.

### Practice Exercise
> `ArrayList` does not provide a method for reading the capacity.

### Setting an `ArrayList`'s Initial Capacity
`ArrayList` has a one-arg constructor to set the internal capacity.

```java
ArrayList<Character> alphabet = new ArrayList(26);
```

This is useful when we know a minimum for how many elements the `ArrayList` will hold.

### Changing the `ArrayList` Capacity
We can change the capacity of the internal array with two methods.

* `ensureCapacity(int)` - ensure, if necessary, that the array can hold at least the number of elements specified.
  ```java
  alphabet.ensureCapacity(128);
  ```

  This ensures we have at least `128` spaces in the array.
* `trimToSize()` -  shrink the underlying array to the actual size of the `ArrayList`.


### Practice Exercise
> When we say "change the capacity" or "shrink" the underlying array, we mean create a new array of the given size and copy references to the new array.

<hr>

[Prev](array-vs-arraylist.md) -- [Up](README.md) -- [Next](labs.md)

