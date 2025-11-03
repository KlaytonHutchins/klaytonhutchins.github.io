## Lab - Improving Encapsulation

In this lab we will improve the encapsulation of our `com.example.inheritance.labs.vehicles.Vehicle` hierarchy.

1. Change `Vehicle`, `Automobile`, `Truck`, and `Boat` so that all fields are `private`.

   * There will be compilation errors. Do not accept any Eclipse suggestions to fix them.

2. Add getters and setters in each class for all fields that do not have them.

   * You can do this in Eclipse by choosing a class and selecting _Source->Generate Getters and Setters_.

     ![Generate getters and setters](images/gettersAndSetters-2.png)

   * Then select fields, and eclipse will generate the methods.

     ![Generate getters and setters](images/generateGettersAndSetters.png)

   * Generating getters and setters will only show fields that are visible and do not already have getters and setters defined.

3. Fix compilation errors by using getters and setters instead of directly accessing fields.

4. Run `VehicleTestApp` and make sure it still works.

(Solution: _Vehicle2.java_, _Automobile2.java_, _Truck2.java_, _Boat2.java_, _VehicleTestApp2.java_)

<hr>

[Prev](getters-setters.md) | [Up](README.md)

