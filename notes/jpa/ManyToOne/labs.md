## Labs
For each of the following labs, update the appropriate JUnit test cases based on the new relationships.

**Note:** To test all of the mappings you are about to create, add to your existing JUnit test classes. When you change a relationship, update a JUnit test.

1. Add the appropriate annotations to describe a uni-directional, many-to-one relationship between *Staff* and *Address*.

   * *Staff* should store a field of type *Address*, but *Address* does not store a collection of *Staff*.

   * Don’t forget to add get and set methods for your field.

1. Create a uni-directional, many-to-one relationship between *Rental* and *Staff*.

   * Use your solution to #1 as a guide.

1. Add the appropriate annotations to describe a bi-directional, many-to-one relationship between *Rental* and *Customer*.

   * Don’t forget to add get/set methods.
   * Create `add` and `remove` methods in the side of the relationship that contains the field of type `List`.

1. Like #3, create a bi-directional, many-to-one relationship between *Customer* and *Store*.
   * Don’t forget to add get/set/add/remove methods.

1. Similar to #3 and #4, add code to describe a bi-directional, many-to-one relationship between *Staff* and *Store*.
   * Don’t forget to add get/set/add/remove methods.

1. Finally, build a uni-directional, one-to-one relationship between *Store* and *Staff* so that the *Store* knows its manager.

<hr>

[Prev](addAndRemove.md) -- [Up](README.md)

