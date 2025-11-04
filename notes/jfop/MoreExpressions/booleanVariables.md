---
layout: default
title: Using Boolean Variable
---


A variable of the `boolean` primitive type has one of only two possible values: `true` or `false`.

```java
int a = 5, b = 3;
boolean isGreater = a > b;
System.out.println(isGreater);  // true
```

* Use a boolean directly in a conditional instead of comparing it to `true` or `false`:

  ```java
  if (isGreater == true) {        // Redundant
    System.out.println("a is greater than b.");
  }    
  if (isGreater) {                // Better style
    System.out.println("a is greater than b.");
  }
  ```


<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](booleanExpressions.md)

