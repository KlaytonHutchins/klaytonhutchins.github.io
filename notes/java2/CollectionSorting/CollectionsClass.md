---
layout: default
title: `Collections` Utility Method
---


In addition to `sort()`, the `Collections` class has many other utility methods defined for working with lists.

* `rotate` — rotates the elements of the passed-in `List` by the specified distance.

  ```java
  // Move three elements from the end of the list to the beginning
  Collections.rotate(planets, 3);
  ```

* `reverse` — reverses the order of the elements of the passed-in `List`.

  ```java
  Collections.reverse(planets);
  ```

* `shuffle` — randomly shuffles the order of the elements of the passed-in `List`.

  ```java
  Collections.shuffle(planets);
  ```

### Binary Search

`binarySearch` — uses a binary search algorithm to locate the given *object* within the `List`.

* The `int` return value represents the index of the first match, if found; otherwise a negative number indicating where the object would have occured in the sorted list (see `java.util.Collections` in the JavaDocs).

* For the algorithm to work properly, you must `sort` the `List` before calling `binarySearch`.


<hr>

[Prev](ArraysClass.md) -- [Up](README.md) -- [Next](labs.md)

