---
layout: default
title: Local Classe
---


```java
public class OuterWithLocal {
  public static void staticMethod() {
    class LocalClass {    // local class

    }
  }

  public int instanceMethod() {
    class LocalClass {    // local class

    }

    return -1;
  }
}
```
> #### local class
> A class defined in a method or constructor.

Local classes are defined inside methods or constructors, like _local variables_.

### Local Class Rules
A local class has some interesting features:

* It is visible only within the code block in which it is defined, just like a local variable.

* It can only use `final` or _effectively final_ method parameters or local variables that are within the same scope.

> #### effectively final
> Parameters and variables which are not declared `final` but whose values never change after initialization.

* A local class has access to fields and methods of the enclosing class, just like a member class does.

  * When declared in a `static` block, local inner classes can access only the `static` fields and methods of the enclosing class.

* Local classes cannot be declared `public`, `protected`, or `private`, since they are not members of a class.

### Practice Exercise
> Local classes are commonly used to implement event listeners and other interfaces.
>
> The use of the class can be written right after the definition of the class, making the code more readable.


### Local Class Example

```java
package com.example.innerclasses.examples;

// Local Inner Class
public class Outer2 {
  private int outerField;

  public void aMethod() {
    final int localVar = 0;

    class Inner {
      private int innerField; // Can have fields, like
                              // top-level or member class

      public String toString() {
        return "o: " + outerField + " i: " + innerField
            + " l: " + localVar;
      }
    }

    Inner in = new Inner();   // Class used after declared
    System.out.println(in);
  }

  public static void main(String[] args) {
    Outer2 out = new Outer2();
    out.aMethod();
  }
}
```

### Drill
> `InnerClasses/com.example.innerclasses.drills.PrintSortedPlanetsLocal`
>
> * Change this class to use a local class, rather than a member class.
>
> (Solution: _PrintSortedPlanetsLocal.java_)

<hr>

[Prev](MemberClasses.md) -- [Up](README.md) -- [Next](AnonymousClasses.md)

