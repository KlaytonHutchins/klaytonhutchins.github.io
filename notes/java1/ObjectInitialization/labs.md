---
layout: default
title: Lab
---


We will be changing `ParkingLot` to improve encapsulation and implement some best practices we have learned here.

1. Copy the `Car` and `ParkingLot` classes from `com.example.objs2.reference` into `com.example.objs2.labs`; you must create this package if you have not already.
   * One of the fields in `ParkingLot` should be constant. Change it.
   * Add a four-parameter `Car` constructor to the `Car` class that includes all fields but `purchasePrice`. It should call the five-parameter constructor and pass `0.0` as the extra parameter.
   * Remove the no-arg constructor from `Car`.
2. Build a `CarDealership` class. This class will have to interact with a `ParkingLot` instance, so it will have a field for one of these. Use an instance initializer to assign this field a `ParkingLot` object.

   Its _public interface_ is as follows.
   * `void addCarToInventory(Car car)` - adds a car to the car inventory (the parking lot) using the parking lot's method.
   * `Car[] findCarsByModel(String model)` - returns an array of cars whose model matches the input model. It must look at each of the parking lot's cars.

     This method must return an array of the correct size, so you may want to determine the number of cars with the matching model first.
   * `Car[] getAllCars()` - return an array of all cars in the inventory (from the `ParkingLot`).


   (Should this class return references to the `ParkingLot`'s array, or a different array?)

3. (Optional) Write a `CarDealershipTester` class. It will test all the methods to see that they work as expected.

   For example, it would add several Cars, then get all cars to see if they were added correctly. Then it could find cars by model and compare the resulting array to what was expected.

   * Note that this is **not** a JUnit test. It is a class with a `main` method.

<hr>

[Prev](private-methods.md) -- [Up](README.md)

