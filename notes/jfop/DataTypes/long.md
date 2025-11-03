## `long` for Large Numbers

When Java sees a whole number, it assumes it is looking at an `int`.

The max value of an `int` is `2_147_483_647`, so what if we need a number larger than that?

```java
int tooBig = 2_200_000_000; // WILL NOT COMPILE
                            // "The literal 2_200_000_000 of type int is out of range"

```
We can add `L` or `l` to a value to tell Java it is a `long`. (Most developers use `L` because it is more readable.)

We then have to assign it to a `long` variable.

```java
long bigNum = 2_200_000_000L;
```

### Practice Exercise
We _must_ add the `L` to a literal that's outside the range of an `int`:
```java
long num = 2_200_000_000; // WILL NOT COMPILE
```

We can add `L` to a number in the range of an `int`, but then we must assign it to a `long` variable.

Once we add the `L`, the number occupies 8 bytes in memory.

```java
int littleNum = 1L; // WILL NOT COMPILE
                    // long takes 8 bytes, int takes 4.
```

<hr>

[Prev](floating-point.md) -- [Up](README.md) -- [Next](switch.md)

