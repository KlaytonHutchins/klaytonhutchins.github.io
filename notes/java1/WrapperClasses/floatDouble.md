## `Float` and `Double`

The `valueOf` method for these two wrappers ignores leading and trailing whitespace.

The `Float` and `Double` classes provide constants related to floating-point values as defined by the IEEE 754 standard.

### Practice Exercise

IEEE - the Institute of Electrical and Electronics Engineers - manages a number of standards related to computing, networking, and other technology.  IEEE 754 defines the representation and behavior of floating-point values in hardware and software - rounding, bit formats, arithmetic operations, etc.  Most modern hardware and software follows this standard for floating-point numbers.

* `NaN` - Not a Number: `0 / 0`

* `NEGATIVE_INFINITY`: `-1 / 0`

* `POSITIVE_INFINITY`: `1 / 0`

* `MIN_VALUE`:
  * `Float`: 2<sup>-149</sup>, `1.4e-45`
  * `Double`: 2<sup>-1074</sup>, `4.9e-324`

* `MAX_VALUE`:
  * `Float`: (2-2<sup>-23</sup>)&middot;2<sup>127</sup>, `3.4028235e38`
  * `Double`: (2-2<sup>-52</sup>)&middot;2<sup>1023</sup>, `1.7976931348623157e308`

Each of these is a pre-defined `static` field of its class:

```java
public final class Float extends Number implements Comparable<Float> {
    //...
    public static final float POSITIVE_INFINITY = 1.0f / 0.0f;
    public static final float NEGATIVE_INFINITY = -1.0f / 0.0f;
    public static final float NaN = 0.0f / 0.0f;
    //...
}
```

<hr>

[Prev](autoboxing.md) | [Up](README.md) | [Next](integerTypes.md)

