---
layout: default
title: `enum` Member
---


Since an `enum` is really a class, you are allowed to provide your own methods and fields in the `enum` declaration.

### Fields and Methods

We can give the `enum` fields and methods, including constructors.

* These come after the constant declarations.

This version of `Day` has a field for the name, and a `toString()` to print out that value.

```java
public enum Day2 {
  // ...

  final private String name;

  @Override
  public String toString() {
    return name;
  }

  public String getName() {
    return name;
  }
}
```

### Practice Exercise
> `enum` fields are _not_ implicitly `final`.

### `enum` Constructors
We can initialize the field for each constant by providing a constructor.

Call the constructor when declaring the constant.
* However, the constructor is still declared after the constants.

```java
public enum Day2 {
  // Constants must be first
  SUNDAY("Sunday"),   // calling constructor
  MONDAY("Monday"),
  TUESDAY("Tuesday"),
  WEDNESDAY("Wednesday"),
  THURSDAY("Thursday"),
  FRIDAY("Friday"),
  SATURDAY("Saturday");

  Day2(String d){
    name = d;
  }

  final private String name;

  @Override
  public String toString() {
    return name;
  }

  public String getName() {
    return name;
  }
}
```
The constructor cannot be declared `public` or `protected`.

### Practice Exercise
> In an `enum` declaration, a constructor declaration with no access modifiers is `private`.<sup>1</sup>

<br />

### Drill
> `EnumeratedTypes/com.example.enums.drills.cards`
>
> * Create a `public` `enum` called `Suit` with the constants (in order) `HEARTS, SPADES, CLUBS, DIAMONDS`.
>   * Add a `private name` field to `Suit`.
>   * Add a one-arg constructor to `Suit` and set the `name` fields to `Hearts`, `Spades`, `Clubs`, `Diamonds`.
>   * Override the `toString` method to output this `name`.
> * Create a `public` `enum` called `Rank` with the constants (in order) `TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE`.
>   * Add a `private value` field to `Rank`.
>   * Add a one-arg constructor to `Rank` and set the `value` field to `2-10` for numbers, `10` for `JACK`, `QUEEN`, and `KING`, and `11` for `ACE`.
>   * Add a `getValue()` method to return the `value`.
> * Uncomment the code in `CardTest` to test your enums.

[1] https://docs.oracle.com/javase/specs/jls/se8/html/jls-8.html#jls-8.9.2

<hr>

[Prev](enum-methods.md) -- [Up](README.md) -- [Next](labs.md)

