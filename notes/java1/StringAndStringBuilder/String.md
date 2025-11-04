---
layout: default
title: The `String` Cla
---


You've used `String` objects since your very first "Hello, World!" program.

* A `String` object encapsulates a sequence of `char`s.

Once created, the `char` values stored inside a `String` cannot be changed - that is, each `String` is _immutable_.

> #### immutable
> In Java, an object is considered immutable if its state cannot change after it is constructed.<sup>1</sup>

### `String` is Special

* We can construct a `String` using a _String literal_: double-quoted text.

  ```java
  String firstName = "Barb";
  ```
* We can concatenate `String`s using `+`;

  ```java
  System.out.println(firstName + " Dobbs");
  ```
* Every object can be converted to its `String` representation.

  ```java
  Sphere s = new Sphere(3.0);
  System.out.println(s); // println() converts Sphere object to String and prints result.
  ```

### `String` Constructors

`String` provides many constructors for creating a `String` from...

* Another `String`.

  ```java
  String fullName = new String(firstName + " " + lastName);
  ```

* An array of `char`, `byte`, or `int` in which the array elements are characters.

  ```java
    char[] greet = new char[5];
    greet[0] = 'H'; greet[1] = 'e'; greet[2] = 'l'; greet[3] = 'l'; greet[4] = 'o';
    String greeting = new String(greet);
  ```

* No argument.

  ```java
  String emptyString = new String();
  ```

[1] https://docs.oracle.com/javase/tutorial/essential/concurrency/immutable.html

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](theStringPool.md)

