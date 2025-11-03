---
layout: default
title: Interface Default Method
---

## Interface Default Methods

Java 8 also introduced _default methods_: non-static, concrete methods defined in interfaces.


* A default method is declared with the keyword `default` and _must_ have a method body.
* A default method is inherently `public` (like all interface methods).


```java
public interface Fillable {
  double LITERS_PER_GALLON = 3.78541; // public static final field
  void fill(int amount);

  static double litersFromGallons(double gallons) {
    return gallons * LITERS_PER_GALLON;
  }

  default int getCapacityLiters() {
    return 0;
  }
}
```

Default methods allow the author of an interface to add new methods without breaking the contract of existing implementor classes and sub-interfaces.

### Drill
>
> Which of these are valid declarations in an interface?
>
> 1. [ ] `default void doStuff1();`
> 2. [ ] `public void doStuff2();`
> 3. [ ] `static void doStuff3();`
> 4. [ ] `default static void doStuff4() { System.out.println("Doing stuff."); }`
> 5. [ ] `static void doStuff5() { System.out.println("Doing stuff"); }`
>
> (Solution: _InterfaceMethodDrill.java_)

<hr>

[Prev](staticMethods.md) -- [Up](README.md) -- [Next](multipleInheritance.md)

