---
layout: default
title: Short-Circuit Operator
---

## Short-Circuit Operators
Both `&&` and `& ` evaluate to true only when both operands are _true_.

`||` and `|` evaluate to true if either is _true_.

The major difference is that the double-character operators, `&&` and `||`, will _short-circuit_ if the left side of the expression decides the outcome. This means the right side of expression will not evaluate.

> #### short-circuit
> Do not even evaluate the right side of a logical expression if the left side already determines the result.

In a `&&` expression, if the left side is false, the whole expression will be false (since it can only be true when both operands are true).

```java
int age = 68;
char gender = 'F';
boolean isMaleAndUnder65 = gender == 'M' && age < 65; //gender is 'F' so age doesn't matter
```

For a `||` expression, if the left side is true, the expression will be true, so there is no reason to evaluate the right side, as it will not change the result of the `||`.
```java
boolean isRegistered = true;
int age = 25;
boolean isRegisteredOr18AndUp = isRegistered || age >= 18;
```

The `&` and `|` operators will _always_ evaluate both sides of the expression.

### Practice Exercise
We almost always use the short-circuit operators `&&` and `||` in logical expressions, because short-circuiting makes the code more efficient. To other developers, using `&` and `|` would probably look like a bug.

<hr>

[Prev](logical.md) -- [Up](README.md) -- [Next](associativity.md)

