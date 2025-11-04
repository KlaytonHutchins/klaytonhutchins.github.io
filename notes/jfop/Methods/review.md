---
layout: default
title: Method Review
---


Remember that a method is a section of code in a class that allows us to tell code to do something.

A method has a _name_ and _body_.
* The name is how we _call_ the method (to use it), and the _body_ is the code that is executed.

```java
public class ClassWithMethods {
  public static void main(String[] args) {
    System.out.println("Calling method1()");
    method1();  //call the method named "method1"
    System.out.println("main finishing");
  }

  public static void method1() {
    System.out.println("  method1 executing");
  }
}
```

When `method1()` is called, the program jumps into `method1`'s body and executes its statements.

When the method is finished, the program jumps back to `main` and continues.

### Drill
`Methods/src/drills/ClassWithMethodsLoop.java`
We are going to call a single method several times.
* Change `main` to call `method1` five times.
  * Instead of copying and pasting `method1();`, call the method inside a loop.
  * Use a variable `counter` to keep track of how many times the loop body has executed. Initialize `counter` to `0`. The loop will execute as long as `counter < 5`. Make sure to increment (add 1 to) `counter` at the end of the loop.

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](repeated-code.md)

