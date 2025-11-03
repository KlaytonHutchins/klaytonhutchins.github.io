---
layout: default
title: Checked Exception
---

## Checked Exceptions

### Unchecked Exceptions

Exceptions like `ArithmeticException` and `NullPointerException` are _runtime exceptions_: they occur because the programmer allowed an expression inside the program to result in a potentially invalid result for the JVM.

* The compiler does not check to see if this kind of exception is possible.

* Well-written code can and should anticipate the possible input of `0` for an integer used as a divisor, or of a `null` value being passed as a reference parameter to a method.

* With a `try`/`catch` block a program can recover from such an exception and continue running.

### Checked Exceptions

When a method interacts with resources outside the JVM, conditions out of its control can leave it unable to continue.

* Using the `throws` clause, the **method** can tell the compiler, and any other method that might call it, that such a situation can occur, specifying the exception class that will result.

  ```java
  private static void mayCrash() throws FileNotFoundException {
    //...
  }
  ```

The compiler will _check_ the **calling method** and require that it either:

* Handle that exception with a `try`/`catch` block, or

  ```java
  private static void callingMethod1() {
    try {
      mayCrash();
    }
    catch (FileNotFoundException e) {
    }
  }
  ```

* Declare that it also throws that exception.

  ```java
  private static void callingMethod2() throws FileNotFoundException {
    mayCrash();
  }
  ```

  * Any caller of this method must also now either surround it with a `try`/`catch`, or declare it throws that checked exception.


### Practice Exercise
> We often call this the "handle or declare" rule for checked exceptions.
> * A method must _handle_ a checked exception itself (with a `try/catch` block), or _declare_ (with `throws`) that it might throw a checked exception.

<hr>

[Prev](Exception.md) -- [Up](README.md) -- [Next](handlingExceptions-labs.md)

