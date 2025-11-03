## Methods

A _method_ is a section of code inside a class that allows us to tell the code to do something.

There are several parts to a method. The ones we will focus on now are the _method name_ and _method body_.

A method has a name, which you use in your program to execute statements.
* A method name is always followed by a pair of parentheses.

The method body is a set of curly braces containing the statements to execute.

```java
public static void methodName() {
  // this is a method body

  // statements to execute...
}
```

All methods are defined inside a class's curly braces.

```java
public class MyClass {
  
  public static void methodName() {
    // this is a method body

    // statements to execute...
  }

  // ...
}
```

The class below _declares_ a method named `printManyAsterisks`.


```java
public class PrintAsterisks {
  public static void printManyAsterisks() {
    System.out.println("****************");
    System.out.println("********");
    System.out.println("***");
  }
}
```

> #### declare
> _Writing_ the method in your class, giving it a name and a method body.


When a program uses, or _calls_ the `printManyAsterisks` method, three lines of `*` are printed to the screen.


> #### call
> _Using_ the method in your class, referring to it by its name.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](calling.md)

