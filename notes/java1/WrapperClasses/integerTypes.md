---
layout: default
title: Integer-type Wrapper
---

## Integer-type Wrappers

`Byte`, `Short`, `Integer`, and `Long` all encapsulate integer-type values.

The <code>parse<i>Type</i></code> for these classes require the passed string to consist only of valid digit characters, with an optional sign character (`+` or `-`) at the beginning.

* Whitespace is not ignored and causes `NumberFormatException` to be thrown.

* They have an overloaded  <code>parse<i>Type</i></code> that takes a _radix_ (base) argument allowing you to parse strings representing numbers other than decimal (base-10).

  ```java
  System.out.println( Integer.parseInt("2a", 16) );     // parse hexadecimal String: 42
  System.out.println( Integer.parseInt("2a", 12) );     // parse base-12 String: 34
  System.out.println( Integer.parseInt("1101101", 2) ); // parse binary String: 109
  ```
For values within the range of an `int`, the `hashCode` for objects of these types will return the value itself.

* For values outside the `int` range, a `Long` object's `hashCode` returns a more arbitrary value.

### Constants

|Wrapper Type|`MIN_VALUE`|`MAX_VALUE`|
|------------|-----------|-----------|
|`Byte`      |-128| 127|
|`Short`     | -32768| 32767|
|`Integer`   | -2147483648| 2147483647|
|`Long`      | -9223372036854775808L| 9223372036854775807L |

  ```java
  int findLargestInt(int[] array) {
    int largestFound = Integer.MIN_VALUE; // Start with smallest possible int.
    for (int i = 0; i < array.length; i++) {
      if ( array[i] > largestFound ) {
        largestFound = array[i];
      }
    }
    return largestFound;
  }
  ```

### Integer Caching

Small numbers are very common in programs: loop counters, menu option numbers, etc.

To avoid creating a lot of temporary objects, each of the integer-type wrappers maintains its own internal _cache_ of pre-constructed wrapper objects, one for each value from `-128` through `127`.

* The first time your program references one of these wrapper classes, its cache is initialized with 256 wrapper objects.

* This is conceptually similar to the String Pool, but is implemented internally by each class.

Each class's `valueOf` method, when given a number - or string representing a number - that's in this range, will return the pre-constructed, cached, wrapper object.

* Explicitly calling `new` to create a wrapper object for a value in this range bypasses the cache and creates a new object on the heap.

  ```java
  Integer i1 = Integer.valueOf(127);
  Integer i2 = Integer.valueOf(127);
  System.out.println( i1 == i2 ); // true: both are references to a cached object.
  Integer i3 = new Integer(127);
  System.out.println( i1 == i3 ); // false: i3 references a new object on the heap
  ```
* For a value outside this range `valueOf` creates a new object on the heap.

  ```java
  i1 = Integer.valueOf(128); // Outside cache range
  i2 = Integer.valueOf(128); // Outside cache range
  System.out.println( i1 == i2 ); // false: not cached.
  ```

* Note that autoboxing uses a wrapper's `valueOf` method, so autoboxing uses the cache for values in range.

  ```java
  Integer i4 = 127;  // Autobox
  Integer i5 = 127;  // Autobox
  System.out.println("Autoboxed: "+(i4 == i5));  // true: cached
  ```

Since autoboxing uses `valueOf`, autoboxed values within the range are cached.

`Float` and `Double` do not cache anything.

### Drill
* Given the following code, what will each of the `println` statements print, and why?
```java
Integer i = Integer.valueOf(127);
Integer j = i; // Reference to same Integer object
i++;
i--;
System.out.println( i.equals(j) ); // true or false?
System.out.println( i == j );      // true or false?
```

<hr>

[Prev](floatDouble.md) -- [Up](README.md) -- [Next](Character.md)

