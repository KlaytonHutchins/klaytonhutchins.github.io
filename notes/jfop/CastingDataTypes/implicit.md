---
layout: default
title: Implicit Type Conversion
---


Java can convert data from one type to another.

There are rules that specify how the conversions occur.

In general, Java will do an _implicit_ conversion to make smaller datatypes (in terms of bytes) into larger datatypes, but there are some exceptions.

> #### implicit
> Done by Java instead of the programmer.

### Allowed Conversions
 * `byte` -> `short`, `int`, `long`, `float`, `double`
 * `short` -> `int`, `long`, `float`, `double`
 * `char` -> `int`, `long`, `float`, `double`
 * `int` -> `long`, `float`, `double`
 * `long` -> `float`, `double`
 * `float` -> `double`

### Practice Exercise
In implicit type conversion, just remember:
* You can't convert a large thing to a small thing, unless it's `long` to `float`.
* You can't lose decimals, like `float` -> `long`
* `byte` will not convert to `char`.
* `char` and `short` will not convert to each other, even though they're the same size.

Study the implicit conversions below to see what is happening.

```java
// byte converted to short;
byte b1 = 16;
short s1 = b1;

// short converted to float
short s2 = 14;
float f2 = s2;

// int converted to float
int i3 = 2105;
float f3 = i3;

// long converted to float
long l4 = 10000L;
float f4 = l4;

// char converted to double
char c5 = 'A';
double d5 = c5;

// converting byte to char does not work
byte b6 = 5;
char c6 = b6;  // DOES NOT COMPILE per JLS 5.1.4

// short and char do not convert because short is signed while char is not
short s7 = 55;
char c7 = s7;  // DOES NOT COMPILE
```

### Practice Exercise
Implicit type conversion is sometimes called _coercion_.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](promotion.md)

