## Autoboxing

Java will automatically convert a primitive type to a wrapper object.

* This is called _autoboxing_.

  ```java
  Integer intObject;            // Integer reference variable
  intObject = Integer.valueOf(500); // explicit constructor call.
  intObject = 500;              // int literal value autoboxed to Integer object.
  ```

* Autoboxing happens when:

  * You assign a primitive to a variable of its corresponding wrapper type.

  * You pass a primitive to a method that expects a parameter of the corresponding wrapper type.

When a primitive is needed, Java will  _unbox_ a wrapped value.

```java
int iVar = intObject * 2;   // value unboxed for use in expression.
long lVar = Long.valueOf(1234); // Long object created, then unboxed.
```

This allows us to treat a wrapper object almost as though it were the corresponding primitive type variable.

```java
for (Integer k=0; k<10; k++) {
  System.out.println(k);
}
```

Behind the scenes, autoboxing uses the wrapper class's `valueOf` method to create the wrapper object.

* Java calls <code><i>type</i>Value()</code> to unbox.

### Practice Exercise
Java will either autobox or type-promote, not both.

```java
    // Long longObject = 1000;  // WILL NOT COMPILE:
                                // Java will not both promote the int to long, then autobox to Long.
    Long longObject = 1000L; // long literal autoboxed to Long.
```

While we can treat wrappers like primitives, we are still dealing in object references.

```java
Long otherLongObject = longObject;                   // Reference to Long object in memory
System.out.println( longObject == otherLongObject ); // true: Same reference.
longObject++; // unbox, increment, then autobox to new Long object.
System.out.println( longObject == otherLongObject ); // false: different references now.
System.out.println(longObject);      // 1001
System.out.println(otherLongObject); // 1000
```

### Drill
* Given the following code, what will each of the `println` statements print, and why?

```java
Integer i = Integer.valueOf(1234);
Integer j = i;                     // Reference to same Integer object
i++;
i--;
System.out.println( i.equals(j) ); // true or false?
System.out.println( i == j );      // true or false?
```

<hr>

[Prev](comparingWrappers.md) | [Up](README.md) | [Next](floatDouble.md)

