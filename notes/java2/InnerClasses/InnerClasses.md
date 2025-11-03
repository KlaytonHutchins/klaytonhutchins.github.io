---
layout: default
title: Inner Classe
---

## Inner Classes

Inner classes were established in Java 1.1 as **classes defined within other classes**.

Inner classes allow for quick and easy creation of classes for specific purposes.

```java
// A top-level class
public class OuterClass {

}
```

```java
// A top-level enclosing class
public class OuterWithInner {
  // An inner class
  class InnerClass {

  }
}

```

> #### enclosing class
> The class that contains the inner class.
>
> This may be called _enclosing instance_ depending on the type of inner class.


The enclosing class provides a namespace for its inner classes.

  * This means two enclosing classes can each have an inner class with exactly the same name.

### Inner Class Rules
Inner classes have some restrictions.

  * They cannot contain any `static` declarations.

  * They cannot have the same name as any enclosing class (unlike fields and constructors).

  * When visibility is allowed, they can have any visibility (unlike top-level classes, which are only _default_ or `public`).


### Inner Class Example
The `PrintSortedPlanets` program uses a `private` inner `Comparator<Planet>` to sort `Planet`s.

```java
// Enclosing class:
public class PrintSortedPlanets {

  public void printPlanets() {
    // Give the TreeSet a Comparator<Planet> so it can sort
    Set<Planet> planets = new TreeSet<>(new PlanetComparator());
    planets.add(new Planet("Mercury", 57_910_000, 4_880));
    planets.add(new Planet("Venus", 108_200_000, 12_103));
    planets.add(new Planet("Earth", 149_600_000, 12_756));
    // ...
    for (Planet planet : planets) {
      System.out.println(planet);
    }
  }

  // Inner class:
  private class PlanetComparator implements Comparator<Planet> {
    public int compare(Planet a, Planet b) {
      if (a.getDiameter() < b.getDiameter())
        return -1;
      else if (a.getDiameter() > b.getDiameter())
        return 1;
      else
        return a.getName().compareTo(b.getName());
    }
  }

  public static void main(String[] args) {
    PrintSortedPlanets p = new PrintSortedPlanets();
    p.printPlanets();
  }

}
```

### Types of Inner Classes

  * _Member_ classes.
  * _Local_ classes.
  * _Anonymous_ classes.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](MemberClasses.md)

