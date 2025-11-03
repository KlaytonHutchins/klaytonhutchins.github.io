---
layout: default
title: Method Overloading
---

## Method Overloading

We cannot have two methods in the same class with the same signature.

However, we can have methods with the same name, but different parameter lists.
* These methods are said to be _overloaded_.

> #### method overloading
> Creating a method with the same name as another method, but a different parameter list (types or number of parameters).

The methods below are overloaded. One `addCharacter` method has two parameters while the other has three.

```java
public static String addCharacter(String input, int numExc) {
  String output = input;
  int counter = 0;
  while (counter < numExc) {
    output = output + "!";
    counter = counter + 1;
  }
  return output;
}

public static String addCharacter(String input, int numExc, String charToAdd) {
  String output = input;
  int counter = 0;
  while (counter < numExc) {
    output = output + charToAdd;
    counter = counter + 1;
  }
  return output;
}
```

These methods are nearly the same. When this happens we can call the overloaded version and pass an additional argument.

```java
public static String addCharacter(String input, int numExc) {
  return addCharacter(input, numExc, "!"); //add "!" and let overloaded method do the logic
}

public static String addCharacter(String input, int numExc, String charToAdd) {
  String output = input;
  int counter = 0;
  while (counter < numExc) {
    output = output + charToAdd;
    counter = counter + 1;
  }
  return output;
}
```

### Drill
`Methods/src/examples/StringManipulationWithDefault.java`

Run the program and follow the method calls.

<hr>

[Prev](pass-by-value.md) -- [Up](README.md) -- [Next](labs.md)

