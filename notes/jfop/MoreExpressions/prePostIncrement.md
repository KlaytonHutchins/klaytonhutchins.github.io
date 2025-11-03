---
layout: default
title: Auto-increment
---

## Auto-increment

A very common case of the _operate-assign_ is to increase or decrease a number by one.

```java
int count = 0;
count = count + 1;
count += 1;        // Same thing
```

Java provides the _increment_ operators for this.

```java
count++;  // Same as "count = count + 1" or "count += 1"
count--;  // Same as "count = count - 1" or "count -= 1"
```

Just like any other expression, the increment operator yields a value.

The value depends on where you place the operator.

* If you put the operator _after_ the variable, then the increment happens after the value is given.

  ```java
  int total = 0;
  count = 0;
  total = count++;  // total == 0, count == 1
  // count was incremented AFTER assigning its value to total.
  ```
  * This is called _post-increment_.

* If you put the operator _before_ the variable, then the increment happens before the value is given.

  ```java
  count = 0;
  total = ++count;  // total == 1, count == 1
  // count was incremented BEFORE assigning its value to total.
  ```
  * This is called _pre-increment_.

### Drill
`AdvancedExpressions/src/drills/PrePostIncrement.java`
Run the program and observe its output.
* Now change the expression `( count = count + 1 )` to `( count += 1 )` and run it again.
* Now change the expression `( count += 1 )` to `count++` and run it again.  What's different?
* Now change the expression `count++` to `++count`.

Pre- vs post-increment only matters when it is part of a larger expression.

```java
count++;  // Pre/post doesn't matter
++count;  // After each statement, count has increased by one
total = ++count; // Pre-increment matters.
```

<hr>

[Prev](operatorAssign.md) -- [Up](README.md) -- [Next](ternaryOperator.md)

