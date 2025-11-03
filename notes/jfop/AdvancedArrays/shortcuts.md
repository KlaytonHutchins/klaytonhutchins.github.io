---
layout: default
title: Multidimensional Array Shortcut
---

## Multidimensional Array Shortcuts

We know how to declare and instantiate a single array.

```java
String[] lz = {"Robert", "Jimmy", "John", "John Paul"};
```
We can do the same with 2-d arrays.
```java
String[] lz = {"Robert", "Jimmy", "John", "John Paul"};
String[] im = {"Bruce", "Nicko", "Janick", "Adrian", "Dave", "Steve"};
String[] gnr = {"Axl", "Slash", "Izzy", "Steven", "Duff"};

String [][] bands = {lz, im, gnr};
```
We have taken our three arrays and used the array shortcut `{ }` to put them in a 2-d array.

We could do the same thing in a single statement.
```java
String [][] legends = {
    {"Robert", "Jimmy", "John", "John Paul"} ,  // same as lz
    {"Bruce", "Nicko", "Janick", "Adrian", "Dave", "Steve"} ,  // same as im
    {"Axl", "Slash", "Izzy", "Steven", "Duff"}  // same as gnr
};
```

This simply uses the `{ }` array shortcut around arrays of `String`s created with the `{ }` shortcut (note the comma between each array of `String`s.)

### Drill
This is a pen and paper or whiteboard drill.
* Draw a graphical representation of the `legends` array.
* Declare a variable and assign "Nicko" to it from the `legends` array.
* Declare a variable and assign "Duff" to it from the `legends` array.

(Solution: _AdvancedArrays/com.example.advancedarrays.solutions/legendsSkillPP.png_

<hr>

[Prev](foreach.md) -- [Up](README.md) -- [Next](varargs.md)

