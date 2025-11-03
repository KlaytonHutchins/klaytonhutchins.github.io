---
layout: default
title: `for` Loops
---

## `for` Loops ##

Sometimes you need to repeat a section of code, and do so a certain number of times.

The `for` loop is useful for executing statements, the _loop body_, a specific number of times.

```java
int i;
for (i = 0; i < 5; i = i + 1) {
  System.out.print(i);
  System.out.print(" squared is ");
  System.out.println(i * i);
}
```
The program sets the variable `i` to 0.

Then it checks the condition `i < 5` to see if it should execute the statements in the `{ }`.

After executing these statements, this `for` loop adds 1 to `i`.

The program then "loops" back to the `for` statement to check the `i < 5` condition to see if it should execute the loop again.

Our example loop runs 5 times, when `i` has the values `0, 1, 2, 3, 4`.

Each time through the loop is an _iteration_.
* We could say the `for` loop _iterates_ through the code 5 times.

> #### iterate ####
> Do something again and again a certain number of times.

The variable `i` controls the number of time the three `System.out` lines are printed.
* We call it the _loop control variable_.

The previous example declares `i` inside of the loop, but we don't have to.
* `i` could just control the number of times the loop executes.
* Below, we declare variables before the loop so we can use them after the loop finishes.

  ```java
  int mult = 0;
  int multiplier = 2;
  int i;
  // Multiplication is just repeated addition.
  // This loop adds 2 five times.
  for (i = 0; i < 5; i = i + 1) {
    mult = mult + multiplier;
  }
  System.out.println("mult is now " + mult);
  ```

### Drill
`ForLoops/src/drills/ForLoop.java`
* Write a `for` loop to print the numbers 1 to 10 to the screen.
* Write the same loop with the _loop control variable_  starting at 0.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](for-diagram.md)

