## Compiling Inner Classes

The Java compiler compiles inner classes as normal classes, changing their names to ensure uniqueness and indicate scope, and usually adding some code to them to make them work as described.

If you have a `.java` file with top-level class and an inner class, it will be compiled into two classes.

_Outer.java_
```java
public class Outer {
  class Inner {

  }
}
```

_OtherOuter.java_
```java
public class OtherOuter {
  class Inner {

  }
}
```

This is compiled to the files:

```
Outer.class
Outer$Inner.class

OtherOuter.class
OtherOuter$Inner.class
```
* This is why we can have inner classes with the same names.

We don't use the name `Outer$Inner` in our code.

<hr>

[Prev](InstanceInitializers.md) | [Up](README.md) | [Next](labs.md)

