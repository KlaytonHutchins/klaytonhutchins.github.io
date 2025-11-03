## Sorting with Comparator

A class implementing `Comparable` has only one _natural sort order_: that which is defined by its `compareTo`.

```java
TreeSet<String> animals = new TreeSet<>(); // Natural sort order
```

To sort objects by you own criteria, create a `Comparator` for the object's class.

```java
public class StringIgnoreCaseComparator implements Comparator<String> { }
```

The class that implements the `Comparator` interface must define the `compare` method.

```java
public int compare(String o1, String o2) { 
  // Use String's own compareTo:
  return o1.toUpperCase().compareTo(o2.toUpperCase());
}
```

* `compare` takes references to two objects to be compared, and returns an `int`.

* `compare` typically calls property getters to determine how the first object compares with the second.

  * It returns a positive integer for greater than, a negative integer for less than, and zero for equal.

Both `TreeSet` and `TreeMap` have constructors allowing you to provide your own `Comparator` to perform the sorting.

```java
Comparator<String> comp = new StringIgnoreCaseComparator();
Set<String> animals = new TreeSet<>(comp);
```

### Drill
> Run `StringComparingApp` to see the names sorted in "ASCIIbetical" order, in which lowercase letters sort after uppercase letters. Comment out the first `Set` declaration, and uncomment the `Comparator` and the second `Set` declaration to see how the `TreeSet` uses the custom `Comparator`.


<hr>

[Prev](SortingwithComparable.md) -- [Up](README.md) -- [Next](SortingLists.md)

