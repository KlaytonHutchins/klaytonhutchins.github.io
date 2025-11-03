---
layout: default
title: Using `enum`
---

## Using `enum`

Access an `enum` constant using dot notation.

* Declare variables with the type of the `enum`.

* Assign the variable by referring to one of the constants.

```java
Color c = Color.RED;
```

### `if`
We can use `enum`s in `if` statements with `==`.

```java
if(c == Color.RED) {
  //...
}
```


### `switch`

We can use `enum`s in `switch` statements.

* The `case` values are the constants - they do not need dot notation.

```java
switch (c) {
  case RED:
  // ...
}
```

### Methods

When defining a method that takes an `enum`, use the type of the `enum` for the parameter type.

```java
public void displayRGBValue(Color c) {
  // ...
}
```

Call the method by passing one of the constant values.


```java
Color c = Color.RED;

displayRGBValue(Color.BLUE);
displayRGBValue(c);
```

### Drill
> `EnumeratedTypes/com.example.enums.drills.DayDrills`
>
> * Create a method called `printDay` that takes a `Day` argument and prints it to the screen with `System.out.println`.
>   * If the day is `FRIDAY`, `SATURDAY`, or `SUNDAY`, print the message "Weekend!"
> * Call the method from `run()` with several `Day` values.

<hr>

[Prev](enum-details.md) -- [Up](README.md) -- [Next](enum-methods.md)

