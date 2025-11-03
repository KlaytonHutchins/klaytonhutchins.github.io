---
layout: default
title: The Ternary Conditional Operator
---

## The Ternary Conditional Operator

The _conditional operator_, `?:`, uses a boolean expression to determine which of two values to yield.

```java
booleanExpression ? valueIfTrue : valueIfFalse
```

This is also called the _ternary operator_, since it has three operands.

* A `boolean` condition.
* A value to yield if the condition is `true`.
* A value to yield if the condition is `false`.

```java
char status; // 'a' for adult, 'm' for minor
status = age >= 18 ? 'a' : 'm';
```

* This is similar to, but much more compact than:

  ```java
  if (age >= 18) {
    status = 'a';
  }
  else {
    status = 'm';
  }
  ```
* Formatting can make ternary expressions easier to read.

  ```java
  status = ( age >= 18 ) ? 'a'
                         : 'm';
  ```
  ```java
  status = age >= 18
           ? 'a'
           : 'm';
  ```

`?:` is an operator that must yield a value:

```java
status = age >= 18
         ? System.out.println("Adult")  // WILL NOT COMPILE
         : System.out.println("Minor"); // println() is a void method returning no value
```

* We must do something with the value returned by the `?:` - either pass it to a method or assign it to a variable.

  * The statement below yields `a` or `m`, but we don't do anything with that value.
    ```java
      (age >= 18) ? (status = 'a') : (status = 'm');
      // WILL NOT COMPILE
      // "The left-hand side of an assignment must be a variable"
    ```
    That statement is as illegal as:
    ```java
    'a'; // WILL NOT COMPILE
         // "The left-hand side of an assignment must be a variable"
    ```

Either of the two value expressions can include a ternary:

```java
    status = ( age >= 18 )
             ? ( age >= 65 )
               ? 's'  // Senior
               : 'a'  // Adult
             : 'm';   // Minor
```

<hr>

[Prev](prePostIncrement.md) -- [Up](README.md) -- [Next](labs.md)

