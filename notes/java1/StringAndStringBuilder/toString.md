---
layout: default
title: Writing `toString()` Method
---


Every object has a `toString` method, which is defined in `java.lang.Object`.

Methods like `println` can count on being able to call `toString` on any object.

* `Object`'s default `toString` returns the object's classname, an `@`, and a number (the object's _hashcode_).

* This provides no information about the object's _state_ - the current values of its fields.

### Drill
`StringAndStringBuilder/com.example.stringstringbuilder.drills.UserCommentDriver`
* Run `UserCommentDriver` and examine the default `toString` output of `UserComment`.

`toString` is important for log messages, debugging, output in character user interfaces (console programs), etc.

* You should always provide a `toString` in classes you create, overriding `Object`'s default, for classes that represent data (as opposed to a driver class with nothing but a `main`.)

Your `toString` should include all interesting state information of your object.

> In general, the `toString` method returns a string that "textually represents" this object. The result should be a concise but informative representation that is easy for a person to read. It is recommended that all subclasses override this method.<sup>1</sup>

```java
public class Sphere {
  private double radius;
  @Override
  public String toString() {
    return "A sphere, with a radius of " + radius;
  }
//...
}
```

As your class definition evolves and you add more instance fields, you must decide which need to be included in your `toString`.

```java
public class Sphere {
  private double radius;
  private String color;
  @Override
  public String toString() {
    return "A " + color + " sphere, with a radius of " + radius;
  }
//...
}
```
* Again, simple `String` concatenation causes unnecessary object creation and garbage collection, so consider using `StringBuilder`.

```java
public class Sphere {
  private double radius;
  private String color;
  @Override
  public String toString() {
    StringBuilder builder = new StringBuilder(100);
    builder.append("A ").append(color).append(" sphere, with a radius of ")
           .append(radius);
    return builder.toString();
  }
//...
}
```

### Practice Exercise
##### Should I always use `StringBuilder`?
In simple cases of building text from a just few literals and variables there may be little difference between using `String` concatenation and using a `StringBuilder`.  For code that runs often, such as inside a loop or a frequently-called method like `toString`, or for text built from many variables and literals, accumulation of temporary `String` objects from concatenation can result in additional garbage collection that impacts performance.  Also, on devices with limited memory and processing power - say, an Android phone or a piece of test equipment - every optimization counts.

Don't feel guilty for using `"Hello" + " World"` in your code, but consider `StringBuilder` anywhere text manipulation is important.

[1] https://docs.oracle.com/javase/8/docs/api/java/lang/Object.html#toString

<hr>

[Prev](StringBuilderMethods.md) -- [Up](README.md) -- [Next](labs.md)

