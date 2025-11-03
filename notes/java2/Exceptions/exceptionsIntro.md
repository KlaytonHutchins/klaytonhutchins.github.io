---
layout: default
title: Introduction to Exception
---

## Introduction to Exceptions

When a method encounters a condition in which it can't continue, it will throw an _exception_.

* By now, you've almost certainly seen this happen many times.

  ```java
  String str = null;
  System.out.println(str.charAt(0));
  // Exception in thread "main" java.lang.NullPointerException
  ```

  ```java
  str = "abcdef";
  System.out.println(str.charAt(6));
  // Exception in thread "main" java.lang.StringIndexOutOfBoundsException: String index out of range: 6
  ```

  ```java
  float[] array = new float[5];
  array[6] = 1.23F;
  // Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 6
  ```

  ```java
  int x = 1, y = 0;
  System.out.println( x / y );
  // Exception in thread "main" java.lang.ArithmeticException: / by zero
  ```

  ```java
  Scanner scanner = new Scanner(System.in);
  System.out.print("Please enter a number: ");
  double d = scanner.nextDouble();
  // User enters "Giraffe".
  // Exception in thread "main" java.util.InputMismatchException
  ```

  ```java
  Number iObj = new Integer(42);
  Float fObj = (Float)iObj;
  // Exception in thread "main" java.lang.ClassCastException: java.lang.Integer cannot be cast to java.lang.Float
  ```

  ```java
  String numStr = "Lasagna";
  int iNum = Integer.parseInt(numStr);
  // Exception in thread "main" java.lang.NumberFormatException: For input string: "Lasagna"
  ```

* Any method or constructor can throw an exception.

An unhandled exception causes execution to immediately stop.

We can handle or _catch_ exceptions using a `try`/`catch` block.

* The `try` block surrounds the method call that might throw an exception.

  ```java
  String numStr = "Lasagna";
  try {
    int iNum = Integer.parseInt(numStr); // parseInt() may throw NumberFormatException
  }
  catch (NumberFormatException e) {
    System.err.println(numStr + " is not a valid number");
  }
  ```

When a method throws an exception in the `try` block, execution of the `try` block stops and control jumps to the `catch` for that exception.

```java
Scanner scanner = new Scanner(System.in);
double d;
boolean gotValidInput = false;
while ( ! gotValidInput ) {
  System.out.print("Please enter a number: ");
  try {
    d = scanner.nextDouble(); // nextDouble() may throw InputMismatchException
    gotValidInput = true;     // Only executes if no exception from nextDouble().
  }
  catch (InputMismatchException e) {
    System.out.println("Invalid input.");
    scanner.nextLine();       // Clear input buffer.
  }
}
scanner.close();
```

Like any block, a `try` or a `catch` creates a _scope_.

* Variables that need to be accessed after the `try` or `catch` must be declared outside of it.

  ```java
  try {
    int i=0;
  }
  catch (Exception e) {
    System.out.println(i); // WILL NOT COMPILE: i cannot be resolved to a variable
  }
  ```


### Drill
> `Exceptions/com.example.exceptions.drills.TryCatchDrill`
>
> * Run `TryCatchDrill` and enter some numbers.
> * Try entering text, or a floating-point number.  What happens?
> * Add a `try`/`catch` block at the appropriate location in the code to print an error message and allow the program to continue accepting input and printing results.
>
> (Solution: _TryCatchDrill.java_)

<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](Exception.md)

