---
layout: default
title: Field and Method Visibility
---

## Field and Method Visibility

Recall how access modifiers determine which fields and methods a class can use.

| Modifier | Class Access |
| -------- | ------ |
| public | Any class |
| protected | Same package and subclasses |
| (default) | Same package |
| private | Same class only |

`protected` fields are available to any subclasses.

For example, `Boat`, `Automobile`, and `Truck` can access `Vehicle`'s `purchasePrice` because the field is `protected`.

```java
public class Vehicle {

  protected double purchasePrice;
  // ...
}
```

```java
public class Boat extends Vehicle {
  protected String name;
  protected double speedInKnots;
  protected int lengthInFeet;

  public Boat(double purchasePrice, String name, double speedInKnots, int lengthInFeet) {
    this.purchasePrice = purchasePrice;  // Field inherited from Vehicle

    this.name = name;
    this.speedInKnots = speedInKnots;
    this.lengthInFeet = lengthInFeet;
  }

  public String toString() {
    return "Boat [purchasePrice=" + purchasePrice   // Field inherited from Vehicle
    + ", name=" + name
    + ", speedInKnots=" + speedInKnots
    + ", lengthInFeet=" + lengthInFeet + "]";
  }
  // ...
}
```

### Inheritance and Encapsulation
`protected` allows subclasses to access fields, but also allows _any_ class in the package to access these fields.
* This is poor encapsulation.
* The strongest level of encapsulation is to make fields `private`.

If we make fields `private`, subclasses can no longer access them.


### `private` Members Are Not Inherited

`private` members (fields and methods) are not inherited from a superclass.
* These fields and methods are not directly accessible to the subclass, so they cannot be considered inherited.

A subclass cannot see a `private` field or call a `private` method.

<br >

### Drill
`Inheritance/com.example.inheritance.drills`
* Create a class `DataAnalyst` which extends `Employee`.
* Add a field `private String securityClearance`, with a getter and setter.
* Add a one-arg constructor to set the `private` field.
* Add a method `public String getInfo()`
  * Return a `String` containing the `firstName`, `lastName`, `age`, `title`, `salary`, and `securityClearance`.
    * Remember that `firstName` and `lastName` are accessible with `getName()` in `Person`. Use this method.
    * You should see errors for the `private` fields `title` and `salary`, inherited from `Employee`.
    * Remove `title` and `salary` from your method. We will add them in later.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](getters-setters.md)

