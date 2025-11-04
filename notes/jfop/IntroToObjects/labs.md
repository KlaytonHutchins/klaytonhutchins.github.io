---
layout: default
title: Lab
---


1. We will be creating and testing a class to model a Car.
   1. Create a `Car` class. It will have fields for
      * make
      * model
      * color
      * numberOfWheels
      * purchasePrice

      Add a `getCarData()` method that returns a `String` with all of the car data.

      Add a `displayCar()` method that prints the object's data to the screen. (This will be very similar to `getCarData`. In fact, it is better in terms of design if `displayCar` calls `getCarData` and prints the return value to the screen.)

      (Solution: _Car.java_)

   2. Create a `CarTester` class.
      * In its `main` method, create two `Car` objects (using `new`). Initialize all fields.
      * In `main`, call `displayCar` and visually verify that the output is what you expect.
      * Also call `getCarData` for each `Car` and print its return value to the screen.

      (Solution: _CarTester.java_)

2. Create a `DMVSimulator` class. It will:
   * Prompt the user to enter data for a `Car`.
   * Upon entry of all data, store the data in a new `Car` instance. Then display the `Car`'s information to the screen.
   * Prompt the user to calculate tax (C) or exit (E)
     * If the user types C, calculate tax, where `tax = purchasePrice * 0.01 * numberOfWheels`. Then the program ends.
     * If the user types E, print an exit message to the screen, and end the program with the command `System.exit(0)`.
     * If the user types a different command, prompt the user again. Keep prompting until the user enters C or E.

   (Solution: _DMVSimulator.java_)

3. We will create a thermometer. The formulas for Celsius and Fahrenheit are
   ```
   celsius = (fahrenheit - 32) / 1.8
   fahrenheit = (celsius * 1.8) + 32
   ```

   1. Create a `Thermometer` class which has
      * Fields:

        `char` scale - (C or F).

        `double` currentTemp - the temperature reading.

      * Methods:

        `getTempAsCelsius` - return a temperature based on the thermometer's scale.

        `getTempAsFahrenheit` - return a temperature based on the thermometer's scale.

     (Solution: _Thermometer.java_)

  2. Create a `ThermometerDriver` class. It will prompt a user for a temperature and scale, then print the temperature (in both Celsius and Fahrenheit) to the screen.

     (Hint: Remember that the `String` `"C"` and `char` `'C'` are not the same. Use the `String` method `charAt(0)` to convert the `String` "C" or "F" into a `char`.)

     (Solution: _ThermometerDriver.java_)

     Optional: Place the user interaction in an infinite loop. If the user types `Q` for the scale, exit the program.

<hr>

[Prev](objects-used.md) -- [Up](README.md)

