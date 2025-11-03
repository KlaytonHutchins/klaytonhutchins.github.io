## Lambda Rules and Syntax

The rules for lambdas are similar to inner classes, with some exceptions.

### Local Variable Access

Like inner classes, lambdas can access local variables that are `final` or _effectively final_ (meaning their values do not change).

### Parameter Names

Attempting to shadow a method variable is a compiler error.
* This is different than inner classes.

```java
Planet p = new Planet("Pluto", 5_900_000_000L, 2377);
// COMPILER ERROR - cannot redeclare p
PlanetTester planetTester = p -> p.getDiameter() > 40_000;
```
* We cannot reuse in-scope local variable names in our lambda expressions.


### Simplifying Lambdas

Lambdas were added to remove the overhead of writing inner classes, and there are places we can simplify lambdas.

#### Method Parameters

We can shorten the parameter list by removing all parameter types.

```java
Comparator<Planet> c = (Planet a, Planet b) -> {
  return a.getOrbit() > b.getOrbit() ? 1 : -1;
};
// becomes  
Comparator<Planet> c = (a, b) -> {
  return a.getOrbit() > b.getOrbit() ? 1 : -1;
};
```

* We must leave off _all_ parameter types.
  ```java
  Comparator<Planet> c = (Planet a, b) -> {     // COMPILER ERROR
    return a.getOrbit() > b.getOrbit() ? 1 : -1;
  };
  ```

#### Single Method Parameter

When there is **one method parameter** _and_ we leave off the parameter type, we can leave off parentheses.

```java
PlanetTester planetTester = (Planet p) -> {
  return p.getDiameter() > 40_000;
};
//becomes
PlanetTester planetTester = p -> {
  return p.getDiameter() > 40_000;
};
```

* If we leave in the type, we _do_ need parentheses.
  ```java
  PlanetTester planetTester = Planet p -> { // COMPILER ERROR
    return p.getDiameter() > 40_000;
  };
  ```

#### No Method Parameters

When the method does not have any parameters, we must always use parentheses.
* There is no way to simplify the `()` case.

```java
/*
interface Runnable {
   public void run();
}
*/
Runnable r = () -> { System.out.println("Running..."); };
```

* Leaving out parentheses makes no sense.

  ```java
  Runnable r = -> { System.out.println("Running..."); }; // COMPILER ERROR
  ```

#### Method Body

When a method body is a **single statement**, we can remove

* Curly braces `{}`

* Ending semicolon `;`

* `return` (if the method has a return type)

```java
Runnable r = () -> { System.out.println("Running..."); };
//becomes
Runnable r = () -> System.out.println("Running...")  ;
```

```java
PlanetTester planetTester = p -> {
  return p.getDiameter() > 40_000;
};
//becomes
PlanetTester planetTester = p -> p.getDiameter() > 40_000;
```

* When we include `{}`, `;`, or `return`, the lambda's body becomes a normal method body, so we need all three items.

  ```java
  // COMPILER ERROR - need return and closing ;
  PlanetTester planetTester = p -> {p.getDiameter() > 40_000 };

  // COMPILER ERROR - need return
  PlanetTester planetTester = p -> {p.getDiameter() > 40_000; };

  // COMPILER ERROR - need {} and ;
  PlanetTester planetTester = p -> return p.getDiameter() > 40_000;
  ```

### Drill
> `com.example.lambdas.drills.LambdaShortening`
>
> * Shorten the lambdas as much as possible.
>   * This could include chaining methods.
>   * You have yet to see some of the interfaces used, but you can still apply syntax rules.

<hr>

[Prev](lambdaTranslation.md) | [Up](README.md) | [Next](lambdaSelection.md)

