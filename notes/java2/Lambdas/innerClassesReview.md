---
layout: default
title: Inner Classes Review
---


Recall inner classes, which were classes within a class or method.

Each of the classes below implements `Comparator<Planet>` and its `compare(Planet, Planet)` method.

* Member Class - at field or method level.
  ```java
  public class Outer {
    class OrbitComparator implements Comparator<Planet> {
      @Override
      public int compare(Planet a, Planet b) {
        return a.getOrbit() > b.getOrbit() ? 1 : -1;
      }
    }
  }
  ```

* Local Class - within a method.
  ```java
  public void aMethod() {
    class OrbitComparator implements Comparator<Planet> {
      @Override
      public int compare(Planet a, Planet b) {
        return a.getOrbit() > b.getOrbit() ? 1 : -1;
      }
    };
  }
  ```

* Anonymous Class - definition and instantiation together.
  ```java
  Comparator<Planet> comp = new Comparator<Planet>() {
    @Override
    public int compare(Planet o1, Planet o2) {
      return a.getOrbit() > b.getOrbit() ? 1 : -1;
    }
  };
  ```

### Passing Code with Inner Classes

Before Java 8, if you wanted to pass functionality to a method, you would have to wrap it in an inner class.

```java
class OrbitComparator implements Comparator<Planet> {
  public int compare(Planet a, Planet b) {
    return a.getOrbit() > b.getOrbit() ? 1 : -1;
  }
}

// Use an instance of the inner class
Collections.sort(planets, new OrbitComparator());
```

  * The `Collections.sort()` method, for example, takes an instance of a `Comparator` as an argument to describe the comparison logic.

  * The syntax is clumsy, especially when you use anonymous inner classes.


```java
package com.example.lambdas.examples;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class PrintSortedPlanets {
  public static void main(String[] args) {
    List<Planet> planets = PlanetUtilities.getPlanets();

    // Passing anonymous instance
    Collections.sort(planets, new Comparator<Planet>() {
      public int compare(Planet a, Planet b) {
        return a.getOrbit() > b.getOrbit() ? 1 : -1;
      }
    });
    for (Planet planet : planets) {
      System.out.println(planet);
    }
  }
}
```

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](innerClassesAndLambdas.md)

