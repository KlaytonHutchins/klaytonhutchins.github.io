---
layout: default
title: Classe
---


So far, all of our classes have been a collection of methods - self-contained programs that do some type of processing, which Java can run because there is a `public static void main(String[] args)` method.

### `class` as a Program

This class prompts a user to enter a radius, which it will use to calculate the volume of a sphere, and prints the result.

```java
public class SphereVolume {
  public static void main(String[] args) {
    double radius = getRadius();

    double volume = calculateVolume(radius);

    printVolumeForRadius(radius, volume);
  }

  public static double getRadius() {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    double radius = 0.0;
    System.out.print("Enter the radius of the sphere: ");
    radius = scanner.nextDouble();
    scanner.close();
    return radius;
  }

  public static double calculateVolume(double radius) {
    double vol = 4.0 / 3.0 * 3.14159 * radius * radius * radius;
    return vol;
  }

  public static void printVolumeForRadius(double radius, double volume) {
    System.out.print("A sphere of radius " + radius);
    System.out.println(" has a volume of " + volume);
  }
}
```

We have only had to think about what our code _does_.

Going forward, we will think about what things in our code _represent_.

### `class` as a Blueprint

This class _models_ a sphere, which has a `radius` and a method we can call to ask for its volume.

```java
public class Sphere {
  public double radius;

  public double getVolume() {
    double vol = 4.0 / 3.0 * 3.14159 * radius * radius * radius;
    return vol;
  }
}
```

> #### model
> Create a representation of something in a program. In Java, this is a class.

The `Sphere` class is a blueprint we can use to create `Sphere` _objects_ in a program.

```java
public class SphereObjectProgram {

  public static void main(String[] args) {
    double rad = getRadius();

    // create a Sphere object
    Sphere s = new Sphere();
    s.radius = rad;

    // get the object's volume
    double volume = s.getVolume();

    // print the radius using this object's data
    printVolumeForRadius(s.radius, volume);
  }

  public static double getRadius() {
    java.util.Scanner scanner = new java.util.Scanner(System.in);
    double radius = 0.0;
    System.out.print("Enter the radius of the sphere: ");
    radius = scanner.nextDouble();
    scanner.close();
    return radius;
  }

  public static void printVolumeForRadius(double radius, double volume) {
    System.out.print("A sphere of radius " + radius);
    System.out.println(" has a volume of " + volume);
  }
}
```

Using the `Sphere` class as a blueprint, we can create several `Sphere` objects.

### Drill
`IntroToObjects/src/drills/SphereCreation.java`
* Create three Sphere "objects."
  1. A baseball, radius 3.7
  2. A basketball, radius 12.0
  3. Mercury, radius 244 million centimeters. (Try writing this value as `244_000_000.0` or `244e5`.)
* Print each object's volume to the screen using System.out.println.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](object-creation.md)

