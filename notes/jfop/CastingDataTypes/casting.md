## The Cast Operator

Conversions that will not happen implicitly can be forced by _casting_ a value or expression to a new data type.

```java
float f = 6.5F;
float g = 7.7F;
int total = (int)(f + g);
```

> #### type casting
> Explicitly requesting the compiler to allow conversion from one datatype to another, usually of types that are not implicitly convertible.

The cast operator is a data type in parentheses, followed by a value or expression.

`(int) value`

### Casting Can Lead to Inaccuracy

When we cast primitives, we can lose bits.

In the example below, the remainder is lost because Java rounds toward zero when casting from a floating-point value.

```java
float f = 6.6F;
float g = 7.7F;
float fTotal = f + g; // 14.299999
int iTotal = (int)(f + g); // 14
```

#### Maintaining Sign and Magnitude

Java will maintain sign and magnitude when casting to certain types.
* `double` -> `float`
* `long` -> `int`
* `double` or `float` -> `long` or `int`

When the original value is too big to fit into the target type, Java will use the maximum or minimum value for that data type.
```java
float f = 6666666666.6F;
float g = 7777777777.7F;
float fTotal = f + g; // 1.44444436E10
int iTotal = (int)(f + g); // 2147483647
```

#### Truncation

For numbers smaller than `int`, Java will _truncate_ (chop off) the beginning bits.

Casting from a `short` to a `byte` removes the first 8 bits.

```java
short s = 0b00101011_10000000; // 11136
System.out.println(s);
byte b = (byte) s;
System.out.println(b);         // -128
```


<hr>

[Prev](int-promotion.md) -- [Up](README.md) -- [Next](casting-hints.md)

