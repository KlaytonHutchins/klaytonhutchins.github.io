---
layout: default
title: `hashCode()`
---


If you override `equals` you also need to override the `hashCode` method.

```java
public int hashCode() { /* ... */ }
```

`hashCode` returns an `int` whose value may not have any real meaning, but which has an important relationship with `equals`:

* If two objects are `.equals()` to each other, then they must both return the same `int` when their `hashCode` methods are called.

This will become more important when you start using collection classes like `HashMap`.

Usually you will implement `equals` and `hashCode` together, and any fields compared in `equals` are also used to calculate the `hashCode` integer.

* This way objects with different state have different hashcodes.

The default `hashCode` inherited from `Object` generally produces a unique integer for each distinct object (usually by deriving it from the memory address of the object.)

As much as possible your `hashCode` implementation should return unique integers for all non-equivalent objects of your class.

A common practice is to start with some arbitrary prime number, then successively multiply it by any numeric instance fields (converting `float` and `double` to `int` first), as well as the hashcodes of any object fields.

```java
public class Product {
  int id;
  String name;

  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + id;
    result = prime * result + ((name == null) ? 0 : name.hashCode());
    return result;
  }
  // ...
}
```

<hr>

[Prev](determiningEquality.md) -- [Up](README.md) -- [Next](labs.md)

