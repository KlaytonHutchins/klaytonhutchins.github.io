## Labs
In these labs we will use the functional interface `Predicate` and lambda-related methods.

1. `com.example.lambdas.labs.PlanetFilteringLab`

   Call `PlanetUtilities.filterPlanets`, filtering for planets with `"a"` or `"A"` in the name.

   (Solution: _PlanetFilteringLab.java_)

1. `com.example.lambdas.labs.PlanetUtilities`

   Change `filterPlanets` to use the `removeIf` method.
   * Do not operate on the input `List`. Instead, create a copy by passing the input `List` into a new `ArrayList`'s constructor.
   * `filterPlanets` used to add to a `List`, but `removeIf` removes from a `List`. How can you get the opposite of the input `Predicate`?

   (Solution: _PlanetUtilities3.java_, _PlanetFilteringLab2.java_)

1. Create an overloaded `filterPlanets` that takes two `Predicate`s, and filters for `Planet`s that match either `Predicate`.

   * Call the new `filterPlanets`, searching for `Planet`s with `"a"` or `"y"` in the name.

   (Solution: _PlanetUtilities4.java_, _PlanetFilteringLab3.java_)

<hr>

[Prev](StandardFunctionalInterfaces.md) -- [Up](README.md)

