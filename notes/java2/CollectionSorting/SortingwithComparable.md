---
layout: default
title: Sorting with Comparable
---


We sort things by comparing one to one another and deciding which comes before the next.

The `java.util` package defines two classes that allow you to create sorted collections.

* `TreeSet` implements a sorted `Set` in which values are placed in order as they are added.

  * A `TreeSet` object has to know how to compare a newly-added object to the objects already in the set.

* `TreeMap` implements a `Map` in which the _keys_ are placed in order as values are put into the map.

  * A `TreeMap` has to know how a new key being added compares (greater than? less than? equivalent?) to the existing keys, so it can add it in the right place.

Both `TreeSet` and `TreeMap` can only sort objects that implement the `java.lang.Comparable` interface.

```java
public interface Comparable<T> {
    public int compareTo(T o);
}
```

```java
public class Planet implements Comparable<Planet> { /*...*/ }
```

A `Comparable` object's `compareTo` method determines if the object is greater than, less than, or equal to a passed-in object of the same class.

```java
public int compareTo(Planet o) { /*...*/ }
```

* `compareTo` returns a positive integer for greater than, a negative integer for less than, and zero for equal.

Each time an object is added to it, a `TreeSet` casts it to `Comparable` to call its `compareTo` method, passing references to existing set members until it determines where to store the new object.

* A `TreeMap` uses the _key_ object's `compareTo` to find the new key's correct position relative to the existing keys.

Many of the Java SE library classes implement `Comparable`, including `String` and the primitive wrapper classes.

* A class's implementation of `compareTo` determines the _natural sort order_ for objects of that class.

### Drill
> `CollectionSorting/com.example.sorting.drills`
> * Run `PlanetSortingApp` and look at the order the planets are printed.
> * What happens when you change the `HashSet` to `TreeSet` and run the program?
> * Modify `Planet` so it declares it implements `Comparable<Planet>`; have Eclipse stub out the `compareTo` method.
>   * In `compareTo`, use an `if`-`else if`-`else` to return:
>     * `-1` if this planet's orbit is less than that of the planet that was passed to `compareTo`.
>     * `1` if this planet's orbit is greater than the other's
>     * `0` otherwise.
> * Run `PlanetSortingApp` again.
>
> (Solutions: _Planet.java_, _PlanetSortingApp.java_)

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](SortingwithComparator.md)

