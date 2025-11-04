---
layout: default
title: Standard Functional Interface
---


There are other useful interfaces in the `java.util.function` package.


* Use the `BiPredicate` interface when you need to pass in two arguments and get a `boolean` result.

  ```java
  @FunctionalInterface
  public interface BiPredicate<T, U> {
    public boolean test(T t, U u);
  }
  // Pass test a T and U, get back a boolean.
  ```

* Use the `Function` interface when you want to specify the result type as a generic as well.

  ```java
  @FunctionalInterface
  public interface Function<T,R> {
    public R apply(T t);
  }
  // Pass apply a T, get back a R.
  ```

* Avoid the extra overhead of boxing to a wrapper class by using the primitive specific version of each interface.

  ```java
  @FunctionalInterface
  public interface IntFunction<R> {
    public R apply(int value);
  }
  // Pass apply an int, get back a R.
  ```


* See the documentation for the `java.util.function` package for more.


### Functional Interfaces and `default` Methods

A functional interface contains only one `abstract` method, but can define other `default` methods with implementations.

`Predicate` has useful `default` methods:

* `negate()` - returns a `Predicate` that represents the logical negation of this `Predicate`.
  ```java
  // ...
  if (ps.negate().test(planet)) {
    tempList.add(planet);
  }
  // ...
  ```

* `and(Predicate p2)` - returns a composed `Predicate` representing the short-circuiting logical `AND` of this `Predicate` and `p2`.

* `or(Predicate p2)` - returns a composed `Predicate` representing the short-circuiting logical `OR` of this `Predicate` and `p2`.


The method below combines two `Predicates` using `and()`.

```java
public static List<Planet> filterPlanetsAND(List<Planet> list, Predicate<Planet> ps1, Predicate<Planet> ps2 ) {
  List<Planet> tempList = new ArrayList<>();
  for (Planet planet : list) {
    // Combine the two Predicates
    if (ps1.and(ps2).test(planet)) {
      tempList.add(planet);
    }
  }
  return tempList;
}
```

### `Collection Method - boolean removeIf(Predicate)`

Java 8 integrated the `Predicate` interface into `Collection`, allowing us to remove items that match a `Predicate`.
* It returns `true` if any items were removed.

```java
List<String> strings = new ArrayList<>();
strings.add("// This is a comment");
strings.add("public class PlanetUtilities {");
strings.add("\t\t// A comment with tabs...");
strings.add("}");

// Trim the input String for whitespace and see if it starts with an inline comment
Predicate<String> startsWithComment = p -> p.trim().startsWith("//");
boolean removed = strings.removeIf(startsWithComment);

System.out.println(removed);
for (String s : strings) {
  System.out.println(s);
}
// true
// public class PlanetUtilities {
// }
```
* Be careful, as this modifies the `Collection`.

<hr>

[Prev](predicate.md) -- [Up](README.md) -- [Next](labs.md)

