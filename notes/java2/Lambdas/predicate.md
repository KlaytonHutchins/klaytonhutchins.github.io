---
layout: default
title: `Predicate<T>` Functional Interface
---

## `Predicate<T>` Functional Interface
Java 8 provides a number of functional interfaces as part of the `java.util.function` package.

One interface is `Predicate<T>`, named for the mathematical concept of a function that returns a boolean value.
* It is generic, so we tell it what kind of object to test.
* Its one method takes the parameterized type as an argument, and returns a `boolean`.


```java
@FunctionalInterface
public interface Predicate <T> {
  public boolean test(T t);
}
```


### Drill
> `Lambdas/com.example.lambdas.drills.UsingPredicate`
> * Declare and define a Predicate<String> that tests whether an input String ends with "!!"
> * Declare and define a Predicate<String> that tests whether an input String is all uppercase.
> * Test your two Predicates by calling their `test` methods with some Strings.

<br />

### Drill
> `Lambdas/com.example.lambdas.drills.PlanetUtilities`
>
> * Refactor your `filterPlanets` method to take a `Predicate<Planet>` instead of a `PlanetTester`.
>   * The body of `filterPlanets` will not change because `Predicate` and `PlanetTester` both have the method `boolean test(Planet)`.
>
> `Lambdas/com.example.lambdas.drills.FilterPlanets`
>
> * Run `FilterPlanets` again.
>   * Notice that your `FilterPlanets` class is unchanged because the lambda expression is based on the function descriptor (parameter and return types) rather than on names.
>
> (Solution: _PlanetUtilities2.java_, _FilterPlanets2.java_)

<hr>

[Prev](lambdaSelection.md) -- [Up](README.md) -- [Next](StandardFunctionalInterfaces.md)

