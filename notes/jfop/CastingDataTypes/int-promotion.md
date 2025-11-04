---
layout: default
title: Promotion in Integer Arithmetic
---


Binary arithmetic operations (`+`, `%`, etc.) using `byte`, `short`, and `char` always promote the operands to `int`s, even if neither of the operands is an `int`.

* For example, this will not compile:
  ```java
  short s1 = 5;
  short s2 = 1;
  
  short s3 = s1 + s2;  // COMPILER ERROR: Type mismatch: cannot convert from int to short
  ```

* Instead, we store the value of `s1 + s2` in an `int` variable.

  ```java
  short s1 = 5;
  short s2 = 1;
  
  int iResult = s1 + s2;
  ```

However, Java is smart enough to use two `int` _constants_ in a binary arithmetic operation without having to promote.

* The code below will compile because the compiler can see the result will fit into a `short`.
  ```java
  short sResult = 5 / 2;
  ```

### Compound Assignment Operators

The compound assignment operators (`+=`, `*=`, etc.) do not promote operands, so they allow us to do arithmetic.

We know this statement would not work.

* We cannot assign the `int` value yielded by `+` to a `byte`.
```java
byte b = 12;
int i = 15;
b = b + i; // DOES NOT COMPILE
```

However, we can add an `int` to a `byte` and assign to that `byte` with the `+=` operator.
```java
byte b = 12;
int i = 15;
b += i;
```

### Drill
`CastingDataTypes/com.example.casting.drills.Division`
* Follow the instructions, adding your expected results where prompted. When you finish, check the solution for explanations.


<hr>

[Prev](promotion.md) -- [Up](README.md) -- [Next](casting.md)

