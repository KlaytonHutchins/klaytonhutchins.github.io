## Downcasting

Casting down the inheritance tree is known as _downcasting_.

* Downcasting requires the cast operator `()`.

```java
Person p = new Employee();
Employee e = (Employee) p; // this works
```

The compiler lets us cast to any class in the hierarchy.
* If the object in memory isn't actually what we cast its reference to according to the _is-a_ relationship, our program will break at runtime with a `ClassCastException`.

```java
Person p = new Person();   // Person in memory
Employee e = (Employee) p; // Compiles, but fails at runtime
                           // with ClassCastException
```

### `instanceof` Operator
We can use the `instanceof` operator to check if the object in memory could be cast to another type.
* If the test returns `true`, we can safely cast to that type.

```java
Person p = new Employee();

if (p instanceof Employee) {
  Employee e = (Employee) p;
  e.getTitle();
}
```

### Practice Exercise
> `instanceof` can only use operands that are a reference type or `null`. A primitive like `int x` results in a compiler error.
>
> Reference: https://docs.oracle.com/javase/specs/jls/se8/html/jls-15.html#jls-15.20.2

<br >

### Drill
> (If you did not finish `VehicleApp`, use the version provided in the `...solutions.vehicles` package)
>
> `Polymorphism/com.example.polymorphism.labs.vehicles.VehicleApp`
> * Change `calculateVehicleRegistration` to use a `rate` of `0.04` if the vehicle _is-a_ `Automobile` or `Truck`, and `0.065` if the vehicle _is-a_ `Boat`. Otherwise use `0.02`.
>
> (Solution: _VehicleApp2.java_)

<hr>

[Prev](casting.md) | [Up](README.md) | [Next](casting-precedence.md)

