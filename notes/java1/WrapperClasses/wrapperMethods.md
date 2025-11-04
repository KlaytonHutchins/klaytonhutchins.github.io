---
layout: default
title: Important Wrapper Class Method
---


The wrapper classes provide three important methods for converting data:

* <code>static <i>type</i> parse<i>Type</i>(String)</code>
* <code>static <i>Type</i> valueOf(<i>type</i>)</code>
* <code><i>type</i> <i>type</i>Value()</code>

#### <code>static <i>type</i> parse<i>Type</i>(String)</code>

Attempt to convert a `String` to a value of the wrapper class's corresponding _primitive_ type.

* `Character` is the only wrapper without this method.

* <code>parse<i>Type</i></code> is a `static` method, usually called in a static manner:

  ```java
  int countArg = 0;
  if ( args.length > 0 ) {
    countArg = Integer.parseInt(args[0]);
  }
  ```

* If the string can't be parsed to the given type, a `NumberFormatException` will be thrown.

### Drill
`WrapperClasses/com.example.wrapperclasses.drills.ParseDrill`
* Use `println` statements to test the parseability and results for each string.

#### <code>static <i>Type</i> valueOf(<i>type</i>)</code>

Convert the passed _primitive_ type (or `String`) to a wrapper-class object.

```java
Integer iObject = Integer.valueOf(500);
Double dObject = Double.valueOf(2.718);
Boolean bObject = Boolean.valueOf(false);
```
* Except for `Character` all the wrappers have a `String` version of `valueOf`, which behaves like <code>parse<i>Type</i></code> but returns a wrapper-class object instead of a primitive.

  ```java
  Byte byteObject = Byte.valueOf("-128");
  Long longObject = Long.valueOf("2147483648");
  ```

Note that these methods take a parameter of the corresponding primitive type.

```java
Short shortObject = Short.valueOf(123);
```

will not compile, because `123` is an `int` literal; you must cast it to `short` to match the signature of `.Short.valueOf()`.

```java
Short shortObject = Short.valueOf((short)123);
```

#### <code><i>type</i> <i>type</i>Value()</code>

Return the primitive-type value encapsulated by this wrapper object.

```java
byte b = byteObject.byteValue();
double d = dObject.doubleValue();
boolean bool = bObject.booleanValue();
```

* The wrappers that extend `Number` each have the following methods for yielding their value as a different data type:

  * `byteValue`
  * `doubleValue`
  * `floatValue`
  * `intValue`
  * `longValue`
  * `shortValue`

### `toString`

As with all objects, each wrapper object has a `toString`.

In addition, the wrapper classes have a `static toString` that takes the primitive type as an argument.

```java
System.out.println(Double.toString(2414e-3)); // 2.414
```

The numeric wrappers have variants for converting a number to a string representing binary, octal, etc.

```java
System.out.println(Integer.toBinaryString(32766)); // 111111111111110
System.out.println(Integer.toHexString(32766));    // 7ffe
```


### Practice Exercise
### Wrapper Constructors

While the wrapper classes have constructors, these are deprecated starting in Java version 9.  Instead, always use the appropriate `valueOf()` method to convert a primitive type to a wrapper object, and the appropriate `parseValue()` method to convert a `String` to a wrapper.


<hr>

[Prev](wrapperClasses.md) -- [Up](README.md) -- [Next](comparingWrappers.md)

