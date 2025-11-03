## Labs
We will change the `Car` class to use better encapsulation, and then fix a test class that uses `Car`. Finally, we will create a class that stores `Car` objects.

1. Copy the `Car` class from  `com.example.encapsulation.reference` into `com.example.encapsulation.labs`; you must create the package if you have not already.

   1. Change the `Car` class's fields to have `private` visibility.
   2. Add getters and setters for the fields.
   3. Add a constructor with parameters for all five fields.
   4. Add a no-arg constructor.
   5. Change the name of the method `getCarData` to `toString` (because it is not a getter).

2. Copy `CarTester` from `com.example.encapsulation.reference` into `com.example.encapsulation.labs`.
   *  The class is broken. Change it to use getters and setters.

3. Create a class called `ParkingLot`. Its job is to hold an array of cars. The class will have:
   * A field for a `Car[]`. This field is of course `private`.
   * `private static int MAX_CARS = 100;`.
   * A no-arg constructor. In this constructor, initialize the `Car[]` to have space for 100 `Car` references.
   * Two methods.
     1. `void addCar(Car car)`. This adds a Car to the array. (How will you decide the next available array location? You probably need to keep track of the number of cars in the array.)

        Users outside the package should be able to use this method.

     2. `Car[] getCars()`. This returns a reference to the `Car[]` in `ParkingLot`.

        Users outside the package should be able to use this method.

4. Create a class called `ParkingLotTester`. This class will have a `main` method.

   * Create a `ParkingLot` instance.
   * Call `getCars` and verify that an array of the correct length is returned (by printing its `length` to the screen).
   * Iterate through the array to verify that it contains `null` values.
   * Create several `Car` instances and add them to the `ParkingLot`.
   * Call `getCars` to get the array of Cars.
   * Verify that `getCars` still returns an array of the same length.
   * Iterate through the array and have each `Car` display itself. (Be careful of attempting to call a method on a `null` reference.)


### Stretch Goals
`Car[] getCars()`. Return an array containing all Cars in the `ParkingLot`. It _does not_ just return the private reference. It will instead return a different array containing all `Car`s in the `ParkingLot`; the array does not have any `null` elements.

<hr>

[Prev](this.md) | [Up](README.md)

