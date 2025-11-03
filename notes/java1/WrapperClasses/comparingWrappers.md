---
layout: default
title: Comparing Wrapper Object
---

## Comparing Wrapper Objects

We can use `==` to compare primitives of compatible types.

```java
int i1 = 500;
int i2 = 500;
System.out.println( i1 == i2 ); // true
```
With wrapper objects, `==` compares _references_, not contents.

```java
Integer iw1 = Integer.valueOf(500);
Integer iw2 = Integer.valueOf(500);
System.out.println( iw1 == iw2 );     // false - references to different objects
```

* Just as with `String`, use `equals` to compare wrapper object _contents_.

  ```java
  System.out.println( iw1.equals(iw2) ); // true
  ```

Remember that we can only use `==` to compare references of compatible types - same class or class hierarchy.

* None of the wrappers extends another wrapper.

  ```java
  Long lw1 = Long.valueOf(500);
  System.out.println( iw1 == lw1 ); // WILL NOT COMPILE: Incompatible operand types Integer and Long
  ```

NOTE: the wrapper class `equals` methods will only return true if both objects are of the exact same type.

```java
int intVar = 500;
long longVar = 500;
System.out.println( intVar == longVar );          // true - int promoted to long and compared

Integer integerObj = Integer.valueOf(500);
Long longObj = Long.valueOf(500);
System.out.println( integerObj.equals(longObj) ); // false, even though both have value 500!
```

<hr>

[Prev](wrapperMethods.md) -- [Up](README.md) -- [Next](autoboxing.md)

