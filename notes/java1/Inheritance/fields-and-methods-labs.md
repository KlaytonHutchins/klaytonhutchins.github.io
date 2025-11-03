## Lab - Creating a Class Hierarchy

This is an extended drill that we will use for the rest of the chapter.

We will create a class hierarchy for Vehicles.

1. Create the package  `com.example.inheritance.labs.vehicles`.
2. Create a `Vehicle` class
   * Fields
     * `protected double purchasePrice`
   * Add a no-arg constructor.
   * Add a one-arg constructor for the field.
   * Add a method `public String toString()` to return a String containing the class name, and field names and values.
3. Create a `Automobile` class which extends `Vehicle`
   * Fields
     * `protected String make`
     * `protected String model`
     * `protected int year`
     * `protected int numberOfWheels`
     * `protected double speedInMph`
   * Add a no-arg constructor.
   * Add a six-arg constructor for the fields of this class and `Vehicle`. Set each field in the constructor.
   * Add a method `public String toString()` to return a String containing the class name, and all six fields and values, starting with the field in `Vehicle`.
4. Create a `Boat` class which extends `Vehicle`
   * Fields
     * `protected String name`
     * `protected double speedInKnots`
     * `protected int lengthInFeet`
   * Add a no-arg constructor.
   * Add a four-arg constructor.
   * Add a method `public String toString()` to return a String containing the class name, and all field names and values.
5. Create a `Truck` class which extends `Automobile`.
   * Fields
     * `protected int bedSizeInCubicFeet`
   * Add a no-arg constructor.
   * Add an seven-arg constructor for fields of this class, `Automobile`, and `Vehicle`.
6. Create a `VehicleTestApp` class that you can run to test Vehicles.
   * Create one `Automobile`, `Boat`, and `Truck` using the multi-arg constructors.
   * Call each object's `toString()` method, and print the `String` to the screen. Verify the classes work as expected.

Check your class structure against this UML diagram.

![Vehicles UML](images/VehiclesUML.png)

(Solution: _Vehicle.java_, _Automobile.java_, _Truck.java_, _Boat.java_, _VehicleTestApp.java_)

<hr>

[Prev](methods.md) -- [Up](README.md)

