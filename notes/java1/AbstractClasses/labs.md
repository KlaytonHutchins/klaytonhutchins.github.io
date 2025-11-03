---
layout: default
title: Lab
---

## Labs
We will explore abstract classes, and create a class hierarchy where common fields are encapsulated in an abstract parent class. 

1. `AbstractClasses/com.example.abstractclasses.labs.vehicles`
   * Make both the `Vehicle` and `FlyingVehicle` classes `abstract`.  Do you have to change any other application code?

   (Solution: _VehicleApp.java_)

1. Create an abstract class named `Shape`. Provide private `int` fields for x and y coordinates of the shape. Add getters and setters as well as appropriate constructors (including no-arg constructor). Add an `abstract` method called `getArea`.

   (Solution: _Shape.java_)

1. Develop two child classes of `Shape`: `Rectangle` and `Circle`. A `Rectangle` has fields of type `double` for `width` and `height`; a `Circle` has a `radius`. Provide getters and setters for each field and appropriate constructors.

   Implement the `getArea` method in each subclass. (Hint: Find `java.lang.Math` in the Java API documentation for usage information on `Math.PI` and the `Math.pow()` method for calculating the circle's area from its radius.)

   (Solutions: _Rectangle.java_, _Circle.java_)

1. Write a program that contains a `main` method that creates an array of three `Shapes`.  Store two `Rectangle`s and a `Circle` in the array. Pass this `Shape` array to a method that loops through the array, printing out the area of each shape.

   (Solution: _ShapeApp.java_)

<hr>

[Prev](usingAbstractClasses.md) -- [Up](README.md)

