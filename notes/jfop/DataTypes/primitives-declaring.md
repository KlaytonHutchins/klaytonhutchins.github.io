---
layout: default
title: Declaring and Assigning Primitive Value
---

## Declaring and Assigning Primitive Values

When we declare and initialize primitive variables, they have to be in the range of that data type.
* Otherwise we will get a compiler error.

```java
short s = -40_000; // WILL NOT COMPILE. Out of range for a short
```
The same is true when we are comparing variables to literal values.

```java
int x = 150;
if (x > 2_500_000_000) { // WILL NOT COMPILE
                        // "The literal 2_500_000_000 of type int is out of range"
  // ...
}
```

### Drill
`DataTypes/com.example.datatypes.drills.DeclaringPrimitives`
* Declare a `byte` variable and assign the value `128`. What happens? Assign it a valid value.
* Create a `switch` statement for your variable. Have a case for each of the values `127`, `-128`, `0`, `'A'`, `128`, `'\u0000'`. (`A` is in single quotes, as is `\u0000`.) Which values cause compiler errors?
* Declare an `int` variable and assign it a value.
* Again create a `switch` statement. Have a case for each of the values `127`, `-128`, `0`, `'A'`, `128`, `'\u0000'`. Does it compile?

<hr>

[Prev](types-matter.md) -- [Up](README.md) -- [Next](floating-point.md)

