---
layout: default
title: Introduction to Java Package
---


As our Java applications become more sophisticated and complex, we use more and more classes.

* There might be many developers working on different parts of the same project, leading to the possibility of class _name collisions_.

> #### name collision
> Two developers choosing the same name for completely different classes.

Java _packages_ allow us to organize our classes and minimize name collisions by providing namespaces for classes and other Java types.

Because filesystem directories define namespaces, Java packages are based on them.

* You can have a folder `package1` containing a `Hello.java`, and another folder `package2` containing a completely different `Hello.java`

Each class can specify the package it belongs to.

File _package1/Hello.java_:
```java
package package1;

public class Hello { /*...*/ }
```

File _package2/Hello.java_:
```java
package package2;

public class Hello { /*...*/ }
```

### The "default" Package

If your class has no `package` statement then it belongs to the _default_ package, also known as the _unnamed package_.

* Once you've advanced beyond the "Hello World" stage, using the default package is considered a bad practice.

### Practice Exercise
A class which has no `package` declaration is part of the unnamed package, so every Java class lives in a package.

<hr>

[Prev](namespaces.md) -- [Up](README.md) -- [Next](creatingPackages.md)

