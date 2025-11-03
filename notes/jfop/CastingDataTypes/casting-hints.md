---
layout: default
title: Casting Hint
---

## Casting Hints

### Precedence

One thing to beware of is casting a value vs. casting an entire expression.

The cast operator `( type )` has high precedence and will cast whatever is next to it.

The expression below will not compile.

```java
int i1 = 3;
int i2 = 12;
short result = (short)i1 + i2;
```
* The problem is that only `i1` is being cast to a `short`; the result of addition is still an `int`.

What about this?

```java
short result = (short)i1 + (short)i2;
```
* This is the same issue; both operands are cast to `(short)`, but then promoted to `int` for addition.

We need to cast the entire expression.

```java
short result = (short)(i1 + i2);
```

### Strings and Casting

To convert to a `String`, do not use the cast operator.

Any type can be converted to a `String` implicitly using the `+` operator where the other operand is a String.

```java
double d = 12.5;
String s = "" + d;
```

<hr>

[Prev](casting.md) -- [Up](README.md) -- [Next](labs.md)

