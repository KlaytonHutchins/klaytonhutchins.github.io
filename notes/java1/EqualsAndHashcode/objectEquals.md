---
layout: default
title: `Object.equals()`
---

## `Object.equals()`

Every class has an `equals()` method, because every class descends from `java.lang.Object`.

```java
package java.lang;
/**
 * Class {@code Object} is the root of the class hierarchy.
 * Every class has {@code Object} as a superclass. All objects,
 * including arrays, implement the methods of this class.
 *
 * @author  unascribed
 * @see     java.lang.Class
 * @since   JDK1.0
 */
public class Object {
//...
    public boolean equals(Object obj) { /* ... */ }
//...
}
```

* This means you can invoke `equals()` on any object reference, and pass it any other object.

When you use `equals` you are asking an object to compare itself to the reference passed to it.

The implementation of `Object.equals` does a simple comparison of the references themselves:

```java
public boolean equals(Object obj) {
    return (this == obj);
}
```

Every class can override `Object`'s implementation of `equals`.

### Drill
> `EqualsAndHashcode/com.example.equalsandhashcode.drills.TestObject`
> * Given the following code, what will each of the `println` statements print?
>   ```java
>   Object o1 = new Object();
>   Object o2 = new Object();
>   Object o3 = o1;
>
>   System.out.println(o1 == o2);      // true or false?
>   System.out.println(o1.equals(o2)); // true or false?
>   System.out.println(o1 == o3);      // true or false?
>   System.out.println(o1.equals(o3)); // true or false?
>   ```
>   Uncomment the statements in `TestObject` and make sure you understand the results.

<hr>

[Prev](referenceComparison.md) -- [Up](README.md) -- [Next](definingEquals.md)

