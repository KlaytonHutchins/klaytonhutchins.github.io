---
layout: default
title: `while` Loop
---


The `while` loop allows us to repeat a section of code as long as a condition is true.

```java
int num = 0;
while (num < 5) {
  System.out.println("num is " + num);
  num = num + 1;
}    
```
1. The program checks the condition `num < 5` to see if it should run the loop.

2. If so, it executes the statements in the `{ }`
   * We call these statements the _loop body_.

3. The program then "loops" back to the `while` statement to check the condition again.

> #### loop body
> The simple statement or block that's controlled by a loop statement.

As long as `num` is less than 5, this loop will keep executing.

This loop will print the values 0 through 4.

* When `num` is finally 5, the loop will no longer execute (because 5 is not less than 5).

### Drill
`WhileLoops/src/drills/WhileLoop.java`
This class has two methods which are called from main. Write the code in the methods.
* `printNumbers()` - Write a `while` loop to print the numbers 1 to 10 to the screen.
* `mathRandomWhile()` - Use Math.random() to write a `while` loop that will execute as long as a random number is less than 0.7. Print the number inside the loop.  Example: `double d = Math.random();` Make sure to reassign d to a new Math.random() value in the loop body.  After the loop, add a statement to print the final value of d.  (You may have to run it a few times to see output.)

<hr>

[Prev](looping.md) -- [Up](README.md) -- [Next](while-detailed.md)

