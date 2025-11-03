---
layout: default
title: Labs - Declaring and Using Interface
---

## Labs - Declaring and Using Interfaces

Classes for these labs are in  `com.example.interfaces.labs.shapes`. We will create and use an interface to give classes a common type and behavior.

1. Create an interface named `Drawable` with the void method `draw` declared inside of it.

   (Solution: _Drawable.java_)

1. Retrofit `Shape` to implement `Drawable`, putting the actual implementation code in `Rectangle` and `Circle`. Don't worry about doing any graphics for drawing, just print out a simple message indicating the type and area of each shape you are "drawing."

   (Solutions: _Shape.java_, _Circle.java_, _Rectangle.java_)

1. Create a tester program to store an array of `Drawable` objects, adding some `Circle` and `Rectangle` objects to it. Call the `draw` method on each.

   (Solution: _DrawableTester.java_)

1. Create a class named `Text` that implements `Drawable` and has a `String` field called `value`. Add getters and setters, as well as an appropriate constructor. Have `Text`'s `draw` method print the value field. Modify your tester program so that a `Text` object is added into the array in addition to the `Shape` objects.

   (Solutions: _Text.java_, _DrawableTester2.java_)

<hr>

[Prev](usingInterfaces.md) -- [Up](README.md)

