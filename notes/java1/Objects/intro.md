## Classes and Objects

The main points about classes and objects so far:

* A `class` is a blueprint for creating an _instance_ or _object_.
* Objects have _state_ and _behavior_ - fields and methods.
* A `class` can have `static` or non-`static` (instance) fields and methods.
  * `static` fields and methods belong to the blueprint.
  * Each object gets its own copy of an instance field.
  * We can call instance methods on an object using the `.` operator.
* Create an instance with the `new` operator.
* Use a _reference_ variable to point to an instance.

A class (blueprint) defining state (fields) and behavior (methods) for objects that model a sphere:

```java
public class Sphere3 {
  public static double PI = 3.14159;  // static field

  public double radius;               // instance field

  // instance method
  public double getVolume() {
    double vol = 4.0 / 3.0 * PI  * radius * radius * radius;
    return vol;
  }

  // static method
  public static double calculateCircumference(double r) {
    return PI * 2 * r;
  }
}
```

Below are examples of creating and using a `Sphere3` object, and using the `Sphere3` `static` method.

```java
Sphere3 sphere = new Sphere3();   // reference points to new instance
sphere.radius = 12.0;             // use reference to access fields and methods
double vol = sphere.getVolume();

double circum = Sphere3.calculateCircumference(15.0); // static method call
                                                      // using class name
```

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](constructor.md)

