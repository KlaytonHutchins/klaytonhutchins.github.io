---
layout: default
title: Static Interface Method
---

## Static Interface Methods

Starting with Java 8, it's possible for an `interface` to provide an implemented `static` method.

```java
public interface Fillable {
  double LITERS_PER_GALLON = 3.78541; // public static final field
  void fill(int amount);

  static double litersFromGallons(double gallons) {
    return gallons * LITERS_PER_GALLON;
  }
}
```

* A `static` interface method _must_ have a method body; in an interface a method can't be both `abstract` and `static`.

* Remember that `static` methods can only access `static` fields; all interface fields are `static` (and `public` and `final`.)

Since they are not `abstract`, `static` methods don't change the interface's contract.


<hr>

[Prev](interfaceInheritance.md) -- [Up](README.md) -- [Next](defaultMethods.md)

