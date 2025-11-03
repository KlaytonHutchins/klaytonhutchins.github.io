## Initializing Static Fields

When a program runs and uses a class, Java initializes the class's `static` fields.

* We can accept the default values for fields (`null`, `0.0`, etc.), or initialize them ourselves.

  ```java
  public class ParkingLot {
    private static int MAX_CARS = 100;

    private Car[] cars;
    private int numberOfCars;

    // fields for name and location of this parking lot
    private String lotName;
    private String lotLocation;

    // ...
  }
  ```

The simplest way to initialize a field is to provide an initial value in its declaration.

```java
public class ParkingLot {
  private static int MAX_CARS = 100;
  // ...
}
```

Sometimes initialization might require error checking or logic we cannot do in a simple declaration, so instead we can use a _static initialization block_.

* This is a block of code `{ }` preceded by the `static` keyword.

  ```java
  static {
    // code to do initialization
  }
  ```

Using a static initialization block, our  class would look like:

```java
public class ParkingLot2 {
  private static int MAX_CARS;

  static {
    MAX_CARS = 100;
  }

  private Car[] cars;
  private int numberOfCars;

  // fields for name and location of this parking lot
  private String lotName;
  private String lotLocation;

  // ...
}
```

A class can have many static initialization blocks, and they can appear anywhere in the class body (though we usually put them toward the top).

Note: these are also called static _initializer_ blocks or just _static initializers_.

<hr>

[Prev](this-vs-this.md) -- [Up](README.md) -- [Next](init-instance.md)

