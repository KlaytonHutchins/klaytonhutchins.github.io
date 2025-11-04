---
layout: default
title: Boolean Expression
---


You can pass a boolean expression to a method.

```java
System.out.println( x > y );
System.out.println( "Hello".equals("Howdy") );
```

A method can return a boolean.

* You can use a boolean method call anywhere you could use a boolean expression.
  * `if` expression.
  * `while` expression.
  * Middle expression in a `for`.

```java
private static boolean booleanMethod() {
  System.out.println("Hello from booleanMethod, returning true.");
  return true;
}
//...
  if ( booleanMethod() ) {
    System.out.println("booleanMethod returned true.");
  }
//...
```


<hr>

[Prev](booleanVariables.md) -- [Up](README.md) -- [Next](operatorAssign.md)

