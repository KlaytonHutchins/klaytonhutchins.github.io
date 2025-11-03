---
layout: default
title: `if` and `else`
---

## `if` and `else`

We may want a set of statements to execute when an `if` condition is `false`.
* Place an `else` after the `if` to do this.

```java
if (age >= 16) {
  System.out.println("Can drive a car.");
}
else {
  System.out.println("Stick to a bike.");
}
```

Using an `else` statement means that one set of statements or the other will execute.
  * Think of `else` as the default if some condition is **not** `true`.

### Rules for `else`
* Must be part of an `if` statement.
* Can go after one or more `else if` statements.
* Does not have a condition, so there are no parentheses `( )`.
* Must be the last part of an "if-then-else" statement.

```java
// Will not compile
if (age >= 16) {
  System.out.println("Can drive a car.");
}
else {
  System.out.println("Stick to a bike.");
}
else if (age < 3) { // Error, else must be last
  System.out.println("Too early for training wheels.");
}
```

### Practice Exercise
The `if` and `else` are _mutually exclusive_. This means when one set of statements executes, the other cannot.


### Drill
`IfElse/src/drills/SalaryDecisions3.java`
* Change the code to use an `else` according to the TODO's.
* What salary range causes the `else` block to execute? Add it as a comment in your `else` block.

<hr>

[Prev](elseif.md) -- [Up](README.md) -- [Next](nesting.md)

