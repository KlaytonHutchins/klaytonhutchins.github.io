## Labs

We will be adding to the `vehicles.Vehicle` hierarchy in this lab. If you did not finish the `Vehicle`, `Automobile`, `Truck`, or `Boat` classes, use the classes in `...solutions.vehicles`.

1. Create a subclass of `Vehicle` called `FlyingVehicle` that contains fields for
   * Air speed
   * Range (which is how far it can fly before running out of fuel).

   Generate a constructor to set all fields, and getters for the fields.

   (Solution: _FlyingVehicle.java_)

2. Create a subclass of `FlyingVehicle` called `Plane` that has fields for
   * Name
   * Passenger capacity

   Generate one constructor to set all `Plane`, `FlyingVehicle`, and `Vehicle` fields; a getter for each new field; and a `toString()` method.

   (Solution: _Plane.java_)

3. Create a class called `TravelingTest` with a static `main` method.
   1. Add a field for an array of  `Vehicle` objects to `TravelingTest`.
   2. In the `TravelingTest` constructor, initialize the array to hold `8` vehicles.
     * Create one `Automobile` object, and add it to the array.
     * Create three `Plane` objects, with passenger capacities of `5`, `75`, and `144`. Add them to the array.
   3. Add a `run` method. Create an instance of the class in `main` and call `run` to start the program.

`TravelingTest` functionality is below. Note that it is better to have more methods than fewer.
1. Prompt a user for the number of passengers who will be flying.
2. If the number of passengers is `4` or fewer, the user will travel in the `Automobile`. Print its information to the screen using `toString()`.
3. If there are `5` or more passengers, choose the appropriate `Plane` to accommodate all passengers. (Note that you will have to use casting).
4. If the number of passengers is larger than any available plane, print a message to the screen.
5. Test your program using small and large numbers.

(Solution: _TravelingTest.java_)

<hr>

[Prev](instance-hiding.md) | [Up](README.md)

