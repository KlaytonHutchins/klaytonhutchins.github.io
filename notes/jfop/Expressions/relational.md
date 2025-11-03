---
layout: default
title: Relational Expression
---

## Relational Expressions

Relational expressions test a relationship between two data items.
* These expressions evaluate to a _boolean_ value: a `true` or `false`.

Relational operators have two operands.
* The "less than" and "less than or equal to" operators:
  ```java
    hoursWorked < 40
    age <= 12
  ```
* The "greater than" and "greater than or equal" operators:
  ```java
    income > 55000
    numPlayers >= 3
  ```
* The "equal to" and "not equal to" operators:
  ```java
    menuItem == choice
    choice != 'q'
  ```

### Practice Exercise
Be careful with the `==` operator. If you use `=`, that results in assignment. `==` tests for equality between two data items.

Relational operators can be used with variables, literals, or combinations of the two.

### Drill
`Expressions/src/drills/Relational.java`
* Run the program.
* Add additional tests with the other logical operators.

<hr>

[Prev](arithmetic.md) -- [Up](README.md) -- [Next](logical.md)

