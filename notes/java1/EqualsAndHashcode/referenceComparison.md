---
layout: default
title: Comparing Reference
---

## Comparing References

The `==` operator compares the values in variables.

* With primitives:

  ```java
  int x = 17;
  int y = 17;
  int z = 42;
      
  System.out.println(x == y); // true
  System.out.println(x == z); // false
  ```

* With references:

  ```java
  String c = new String("cat"); // A new object on the heap
  String d = new String("cat"); // Another new String object
  System.out.println(c == d);   // false
                                // The references to the two Strings are different
  ```

We've learned that to compare the actual contents of two `String` objects, we use `equals()`.

```java
System.out.println(c.equals(d)); // true
```

The `String` class provides the `equals()` method to allow comparison of the _contents_ of two `String`s instead of the references in two `String` variables.

### Practice Exercise
> ##### The String Pool
> The `String` class is special, in that we can create a `String` object just by putting a double-quoted literal in our code.
> 
> When we create strings this way, Java first checks to see if there's already a `String` with the exact same content in a special region of memory called the _String Pool_.  If it finds one, then instead of creating a new `String` Java returns the reference to the existing `String` in the String Pool.
> ```java
> String s1 = "cat";
> String s2 = "cat";  // There's already a "cat" in the String Pool
> System.out.println(s1 == s2); // true
> ```
> When we use `new` to create a `String`, then Java ignores the String Pool and creates a new object on the heap.
> ```java
> String c = new String("cat"); // A new object on the heap
> String d = new String("cat"); // Another new String object
> System.out.println(c == d);   // false
>                               // The references to the two Strings are different
> ```

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](objectEquals.md)

