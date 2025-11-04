---
layout: default
title: Variable Types Tell Java What to Do
---


If we can treat a `char` like an `int` and add to it, how does Java know to print out a character?

For example, `A` has the numeric value `65`, but Java does not print `65`.

Java uses the data type of the variable.
* It sees that the variable is a `char` and knows to treat it like a character when it prints it to the screen.

```java
char variable = 'A';
System.out.println(variable); // Output: A
```

### Drill
`DataTypes/com.example.datatypes.drills.CharPrinting`
* Add the line ` System.out.println(variable + 1);` to `main`. What is the output? Based on its output, what does the `+` operator appear to do?

<hr>

[Prev](primitives-memory.md) -- [Up](README.md) -- [Next](primitives-declaring.md)

