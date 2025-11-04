---
layout: default
title: The Exception Cla
---


An exception is a Java object whose type and state describe the problem that caused it to be thrown.

* The object is passed to a `catch` block much the same way an argument is passed to a method parameter.

* An exception provides information a developer can use to debug and improve their code.

Its main property is a `String` _message_, accessible via `getMessage`.

```java
int x = 1, y = 0;
try {
  System.out.println(x / y);
}
catch (Exception e) {
  System.out.println(e.getMessage());
  // "/ by zero"
}
```

An exception's `toString` prints out its fully-qualified class name, and its message.

```java
try {
  System.out.println(x / y);
}
catch (Exception e) {
  System.out.println(e);
  // "java.lang.ArithmeticException: / by zero"
}
```

An exception can be thrown by a method that was called by another method that was called by another method, etc.

* From the original (throwing) method the exception propagates back up the stack of calling methods, causing each one's execution to fail at the point of the method call.

* An exception object keeps track of the call stack that led up to it, including the source code line where each method failed.

  * `printStackTrace` prints this valuable diagnostic information to the screen, using `System.err` by default.

    ```java
    public class SomeClass {

      public static void main(String[] args) {
        System.err.println("main start.");
        SomeClass obj = new SomeClass();
        try {
          obj.firstMethod();
        }
        catch (Exception e) {
          e.printStackTrace();
        }
        System.err.println("main done.");
      }

      private void firstMethod() {
        System.err.println("firstMethod start.");
        this.secondMethod();
        System.err.println("firstMethod done.");
      }

      private void secondMethod() {
        System.err.println("secondMethod start.");
        this.thirdMethod();
        System.err.println("secondMethod done.");
      }

      private void thirdMethod() {
        System.err.println("thirdMethod start.");
        System.out.println( 17 / 0 );
        System.err.println("thirdMethod done.");
      }

    }
    ```

    ```
    main start.
    firstMethod start.
    secondMethod start.
    thirdMethod start.
    java.lang.ArithmeticException: / by zero
	    at SomeClass.thirdMethod(SomeClass.java:29)
	    at SomeClass.secondMethod(SomeClass.java:23)
	    at SomeClass.firstMethod(SomeClass.java:17)
	    at SomeClass.main(SomeClass.java:7)
    main done.
    ```

  * The first line is the exception's `toString`, the next refers to the original exception.

### Practice Exercise
> As a programmer you are often in a hurry.  When an exception occurs while you're testing your code, it's tempting to just go back to the source code and start looking for problems.  Instead, always take the time to use the information the exception is giving you.  Interpreting exception messages, types, and stack traces is a primary skill for a Java developer.
>
> In Eclipse you can click on a line number in the stack trace to go directly to the relevant source code.

If an unhandled exception propagates all the way to `main`, the JVM will print the stack trace and exit.

  ```java
  public class SomeClass2 {

    public static void main(String[] args) {
      System.err.println("main start.");
      SomeClass2 obj = new SomeClass2();
      obj.firstMethod();
      System.err.println("main done.");
    }

    private void firstMethod() {
      this.secondMethod();
    }

    private void secondMethod() {
      this.thirdMethod();
    }

    private void thirdMethod() {
      System.out.println(17 / 0);
    }

  }
  ```

  ```
  main start.
  Exception in thread "main" java.lang.ArithmeticException: / by zero
	  at SomeClass2.thirdMethod(SomeClass2.java:19)
	  at SomeClass2.secondMethod(SomeClass2.java:15)
	  at SomeClass2.firstMethod(SomeClass2.java:11)
	  at SomeClass2.main(SomeClass2.java:6)
  ```


### Practice Exercise
> `System.err`
>
> At runtime the operating system provides three standard data streams to each program:
>
> 0: Standard Input (or STDIN), represented in Java by `System.in`.  By default this reads from the terminal keyboard.
>
> 1: Standard Output (STDOUT), represented by `System.out`.  By default this outputs to the terminal screen.  For efficiency, the operating system _buffers_ this stream, waiting until the program has output a certain number of characters before actually sending it to the terminal.  STDOUT is intended for output of a program's results: data.
>
> 2: Standard Error (STDERR), represented by `System.err`.  By default this also outputs to the terminal screen, but the operating system doesn't buffer data a program writes to STDERR, instead sending each character to the terminal as the program prints it.  STDERR is intended for a program's diagnostic information: errors, warnings, status messages, etc., so it can be separated by the user from the program's data output. (Eclipse renders STDERR output in red text by default.)
>
> Because STDOUT is buffered and STDERR isn't, output produced by `System.err` can appear on the screen before, or even intermingled with, output produced earlier in the code by `System.out`.
>

### Drill
> `Exceptions/com.example.exceptions.drills.TryCatchDrill`
> * In the `catch` block, what happens if you print your error message using `System.err` instead of `System.out`?
>
> (Solution: _TryCatchDrill2.java_)

<hr>

[Prev](exceptionsIntro.md) -- [Up](README.md) -- [Next](checkedExceptions.md)

