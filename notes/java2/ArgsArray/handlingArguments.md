---
layout: default
title: Handling Command-Line Argument
---

## Handling Command-Line Arguments

Remember that an array is an object that must be constructed before use.

* A method that takes an array as an argument must first check that the array itself is not `null` before trying to access its `length` or its elements.

  ```java
    ...
    int[] nums = null;
    methodThatTakesAnArray(nums);
  }
  public static void methodThatTakesAnArray( int[] numbers ) {
    System.out.println(numbers.length); // NullPointerException
  }
  ```

  ```java
    ...
    int[] nums = null;
    betterMethodThatTakesAnArray(nums);
  }
  public static void betterMethodThatTakesAnArray(int[] numbers) {
    if (numbers != null) {
      System.out.println(numbers.length);
    }
    else {
      System.out.println("numbers is null");
    }
  }
  ```

The `args` array is always created and passed to `main`, even if no arguments were passed on the command line.

* So in `main` (and only in `main`) it's safe to just start using `args`.

  ```java
  public static void main(String[] args) {
    if (args.length < 2) {
      System.err.println("I expect to be passed two filenames on the command line.");
      System.exit(1);
    }
    String fileName1 = args[0];
    String fileName2 = args[1];
    //...
  }
  ```

### Practice Exercise
All programs, regardless of the language they're written in, have access to the array of command-line arguments. Some languages include the program name itself at the beginning of the array.  For example, if our program were written in the C language and we ran it as `ShowMe cat dog frog`, `args[0]` would always be `ShowMe`.

Java does not include either the class name or the `java` command itself in `args` - only the words after our class name.


<hr>

[Prev](argsArray.md) -- [Up](README.md) -- [Next](argsInEclipse.md)

