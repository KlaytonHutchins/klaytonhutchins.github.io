---
layout: default
title: `finally`
---


A `try`/`catch` block optionally can be followed by a `finally` block.

* The `finally` block executes whether or not an exception occurs.

  ```java
  try {
    mayCrash();
    System.out.println("No exception.");
  }
  catch (FileNotFoundException e) {
    System.out.println("Exception occurred.");
    }
  finally {
    System.out.println("mayCrash() was called.");
  }
  ```

The `finally` block **always** executes, unless the JVM itself exits in the `try` or a `catch`.

```java
try {
  mayCrash();
  System.out.println("No exception, returning.");
  return; // Return from method....
}
catch (FileNotFoundException e) {
  System.out.println("Exception occurred, returning.");
  return; // Return from method....
}
finally {
  // ... but execute the finally block on the way out.
  System.out.println("finally block: mayCrash() was called.");
}
```
```
Exception occurred, returning.
finally block: mayCrash() was called.
```

A `finally` block comes after all `catch` blocks.

```java
try {
  mayCrash();
}
finally {
  System.out.println("Hello from finally!");
}
catch (Exception e) {  // WILL NOT COMPILE: Syntax error.
  e.printStackTrace();
}
```

* A `try` can be followed by `finally`, with no `catch` blocks.

  ```java
  try {
    System.out.println("Trying to print, then returning.");
    return;
  }
  finally {
    System.out.println("Hello from finally!");
  }
  ```
  ```
  Trying to print, then returning.
  Hello from finally!
  ```

### Drill
> `Exceptions/com.example.exceptions.drills.FinallyDrill`
> * Run `FinallyDrill` and examine the stack trace.  Does `main` finish executing?
> * In `runMethod` add a `finally` block that uses `System.err` to print a message.  Run `FinallyDrill` again.  Does the new message print?  Does `main` finish executing?
> * In `launch`, surround the call to `runMethod` with a `try`/`catch`. (Tip: in Eclipse, highlight the method call line, right-click, and choose _Surround With_ and _Try/catch block_).  In the `catch` block, use `System.err` to print a message, followed by `return`.  Run and examine the results.
> * Add a `finally` to the `try`/`catch` in `launch`, which uses `System.err` to print a message, followed by `return`.  Does the message print?  Does `main` complete?
> * In the `catch` block in `launch`, change the `return` to `System.exit(1)`.  What happens when you run it?

<hr>

[Prev](exceptionSubclass.md) -- [Up](README.md) -- [Next](labs.md)

