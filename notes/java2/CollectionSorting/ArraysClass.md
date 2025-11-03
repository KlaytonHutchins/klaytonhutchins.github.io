---
layout: default
title: Sorting Array
---

## Sorting Arrays

Arrays don't have a `sort` method, and can't be passed to methods like `Collections.sort` because they aren't `List` implementations.


```java
String[] animalArray = { "Cat",
    "catfish",
    "caterpillar",
    "Frog",
    "Dog",
    "fruit bat",
    "Giraffe" };

for (String animal : animalArray) {
  System.out.println(animal);
}
```
```
Cat
catfish
caterpillar
Frog
Dog
fruit bat
Giraffe
```

The `java.util.Arrays` utility class defines `sort` methods that take arrays of any type, including primitives and references.

```java
Arrays.sort(animalArray);
for (String animal : animalArray) {
  System.out.println(animal);
}
```
```
Cat
Dog
Frog
Giraffe
caterpillar
catfish
fruit bat
```

* `Arrays` includes sort methods that take a `Comparator` for custom sorting.

The `Arrays` class provides a number of other methods for convenient array manipulation.

```java
System.out.println(animalArray);
// [Ljava.lang.String;@3d4eac69
System.out.println(Arrays.deepToString(animalArray));
// [Cat, Dog, Frog, Giraffe, caterpillar, catfish, fruit bat]
```

<hr>

[Prev](SortingMaps.md) -- [Up](README.md) -- [Next](CollectionsClass.md)

