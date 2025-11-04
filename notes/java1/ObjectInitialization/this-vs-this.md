---
layout: default
title: `this` vs. `this()`
---


We have seen how to use the reference `this` to allow an object to use its own fields and methods.

```java
public class Car {
  private String make, model, color;
  private int numberOfWheels;
  private double purchasePrice;

  public Car(String make, String model, String color, int numberOfWheels) {
    this.setMake(make);
    this.setModel(model);
    this.setColor(color);
    this.setNumberOfWheels(numberOfWheels);
  }

  public Car(String make, String model, String color, int numberOfWheels, double purchasePrice) {
    this.make = make;
    this.model = model;
    this.color = color;
    this.numberOfWheels = numberOfWheels;
    this.purchasePrice = purchasePrice;
  }
  //...
}
```
There is another way to use `this` to allow an object to access its own code.

### `this()` in a Constructor

A constructor can call another constructor in the same class by using the keyword `this` as a method name.

```java
public class Car2 {
  private String make, model, color;
  private int numberOfWheels;
  private double purchasePrice;

  public Car2(String make, String model, String color, int numberOfWheels) {
    this(make, model, color, numberOfWheels, 0.0);
  }

  public Car2(String make, String model, String color, int numberOfWheels, double purchasePrice) {
    this.make = make;
    this.model = model;
    this.color = color;
    this.numberOfWheels = numberOfWheels;
    this.purchasePrice = purchasePrice;
  }
  //...
}
```

This reduces code duplication.

If you use `this()` in a constructor, it must be the first statement.

* You would not be able to put a `System.out.println` before it, for example.

  ```java
  public Car2(String make, String model, String color, int numberOfWheels) {
    System.out.println("Calling this()");  // WILL NOT COMPILE: Constructor call must be the first statement in a constructor
    this(make, model, color, numberOfWheels, 0.0);
  }
  ```

### Practice Exercise
> We often have methods call their overloaded counterparts and pass default values for fields, like the four-arg `Car2`  constructor is doing. The reason, again, is to avoid code duplication.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](init-static.md)

