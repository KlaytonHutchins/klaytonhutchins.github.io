## Initializing Instance Fields

We often put code to initialize instance fields in constructors, or when we declare a field.

This class initializes its `Car[]` in both constructors, and sets `numberOfCars` when the field is declared:

```java
public class ParkingLot3 {
  private static int MAX_CARS = 100;

  private Car[] cars;
  private int numberOfCars = 0; // initialize to 0

  // fields for name and location of this parking lot
  private String lotName;
  private String lotLocation;

  public ParkingLot3(String lotName, String lotLocation) {
    cars = new Car[MAX_CARS]; // create array
    this.lotName = lotName;
    this.lotLocation = lotLocation;
  }

  public ParkingLot3(String lotName) {
    cars = new Car[MAX_CARS]; // create array
    this.lotName = lotName;
    this.lotLocation = "DEFAULT_LOCATION";
  }
  // ...
}
```

An alternative is to use _initializer blocks_ (sometimes called _instance initializers_).

* These are like static initializer blocks, but without the `static` keyword.

  ```java
  {
    // initialization code
  }
  ```

The advantage with initializer blocks is they execute regardless of which constructor is used, and execute before any constructor's code.

### Practice Exercise
> Initializer blocks are a great place to do initialization that would otherwise end up in every constructor.

We can make a new version of the `ParkingLot3` class that takes advantage of this.

```java
public class ParkingLot4 {
  private static int MAX_CARS = 100;

  private Car[] cars;
  private int numberOfCars = 0; // initialize to 0

  private String lotName;
  private String lotLocation;

  {
    cars = new Car[MAX_CARS];  // create array in initializer block
  }

  public ParkingLot4(String lotName, String lotLocation) {
    this.lotName = lotName;
    this.lotLocation = lotLocation;
  }

  public ParkingLot4(String lotName) {
    this(lotName, "DEFAULT_LOCATION");
  }
  // ...
}
```

Now every instance will have a `cars` array, even though we don't initialize it in a constructor.

### Practice Exercise
> The Java compiler copies initializer blocks into every constructor, so initializer blocks will always execute before constructor code.<sup>1</sup>  If there are multiple instance initializers, they are copied in the order they appear in the code.

[1] https://docs.oracle.com/javase/tutorial/java/javaOO/initial.html

<hr>

[Prev](init-static.md) | [Up](README.md) | [Next](order-of-init.md)

