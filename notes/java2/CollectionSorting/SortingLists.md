---
layout: default
title: Sorting List
---

## Sorting Lists

To sort a `List`, pass it to the `sort` method of the `java.util.Collections` class.

```java
Collections.sort(planets);
```
* `Collections.sort` modifies the actual object you pass, without creating and returning a new `List`.

* This version of `sort` requires a list of `Comparables` and uses their natural sort order.

For a list of non-`Comparable` objects, or to customize the sort, use a `Comparator` with `Collections.sort`.

```java
public class PlanetDiameterComparator implements Comparator<Planet> {
  public int compare(Planet a, Planet b) {
    if (a.getDiameter() < b.getDiameter())
      return -1;
    else if (a.getDiameter() > b.getDiameter())
      return 1;
    else
      return a.getName().compareTo(b.getName());
  }
}
```
```java
PlanetDiameterComparator comp = new PlanetDiameterComparator();
Collections.sort(planets, comp);
```

Java 8 introduced the ability for a `List` to sort itself, using a `Comparator`.

```java
planets.sort(new PlanetReverseDiameterComparator());
```

### Practice Exercise
> The `List` interface was first published in Java 1.2.  The `sort` method was added in version 1.8.  Adding a new `abstract` method to `List` would have broken the contract used by all the many existing implementing classes.  However there were compelling reasons for `sort` and other new methods.
>
> This need to add methods to an interface without breaking existing implementors is the reason Java 8 introduced `default` methods.  Because the Java 8 `List` provides a `default` implementation of `sort`, no existing implementors had to be modified.

<hr>

[Prev](SortingwithComparator.md) -- [Up](README.md) -- [Next](SortingMaps.md)

