---
layout: default
title: The `extends` Keyword
---


Classes can inherit from other classes by using the `extends` keyword.

```java
public class SuperClass {
  //...
}
```

```java
public class SubClass extends SuperClass {
  //...
}
```

`SubClass` now inherits fields and methods of `SuperClass`.

We can also create another class that extends `SubClass`.

```java
public class SuperClass {
  //...
}
```

```java
public class SubClass extends SuperClass {
  //...
}
```

```java
public class SubSubClass extends SubClass {
  //...
}
```

Now `SubSubClass` inherits from `SubClass` _and_ `SuperClass` (because `SubClass` inherits from `SuperClass`).
* We have created a _class hierarchy_.

> #### class hierarchy
> A group of classes derived from other classes to make what we can picture as a tree-like structure, with parent classes above child classes.
>
> ![Class hierarchy](images/extends.png)

### Single Inheritance
A Java class can directly extend _one and only one_ class using the `extends` keyword.
* This is not the case in some other programming languages.

This class would not compile.

```java
public class Werewolf extends Person, Wolf {

}
```

### Drill
> `Inheritance/com.example.inheritance.drills.Employee`
> * Change the `Employee` class so that it extends `Person`.
>   * Add a `private` `String` field for `title`.
>   * Add a `private` `double` field for `salary`.

<hr>

[Prev](inheritance.md) -- [Up](README.md) -- [Next](final.md)

