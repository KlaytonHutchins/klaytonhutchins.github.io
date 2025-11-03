## Floating Point Literals

When Java sees a numeric literal with a `.`, such as `0.0`, it assumes it is seeing a `double`, and range is less important.

* A number in scientific notation is considered a `double`: `6.022e23` (6.022 * 10<sup>23</sup>).

* Because of this, the following declarations are illegal:

  ```java
  float f = 0.0; // WILL NOT COMPILE
  float sci = 3e10; // NO, e10 is a double.
  ```

  * The reason is that `0.0` is a `double`, and a `double` (8 bytes) will not fit into a `float` (4 bytes).

We can tell Java a literal is a `float` by adding `F` or `f` after the number (case does not matter.)

```java
float f1 = 0.0f;
float sciF = 3e10F; // This works.
```

We can even assign `int` literals to float or double values.
* This works because `int` and `float` are both 4 bytes, and putting an `int` into a `float` will not lose any precision (like dropping decimal places).

```java
// f after an int literal
float f2 = 1f;
// no F, but it works
float f3 = 1;
```

### Practice Exercise
We can assign many whole number values to floats, and add `F` after most of them - but not binary numbers.
```java
float f4 = 0b10101;  // binary number - an int
float f5 = 0b10101f; // NO, don't use F with binary numbers
float f6 = 0xF16F;   // F doesn't do anything here, it is a hex digit
float f7 = 0761;     // octal number
float f8 = 0761F;    // octal number with F
```

<br >

### Drill
`DataTypes/com.example.datatypes.drills.FloatValues`
* Copy the declarations of `f1` to `f8` into `main` and see the errors for yourself.

<hr>

[Prev](primitives-declaring.md) -- [Up](README.md) -- [Next](long.md)

