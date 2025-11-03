## `break` and `continue` Statements ##

We can change how a loop iterates.
> Sometimes we may want a single iteration, or the entire loop itself, to end early.

Two keywords inside a loop can change how it iterates.

### break ###

Adding a `break;` statement in a loop will cause the program to exit the loop and continue executing after the loop.

```java
// Exit the loop the first time i % 2 == 0
for (int i=1; i <= 10; i+=1){
  if (i % 2 == 0) {
    break;
  }
  System.out.println(i);
}
```

### `continue` ###

The statement `continue;` causes the loop to skip the rest of the current iteration.

The _increment_ portion of part of the loop still executes, and the _termination_ condition is checked to see if the loop body will execute again.

```java
// Go to the next iteration every time i % 2 == 0
for (int i=0; i <= 10; i+=1){
  if (i % 2 == 0) {
    continue;
  }
  System.out.println(i);
}
```

### Drill
`ForLoops/src/drills/ForLoopBreakContinue.java`
* Try the loops in the examples above in code.
* Write a loop that prints the numbers from 1 to 30, skipping multiples of 3 by using the continue statement.

<hr>

[Prev](for-body.md) -- [Up](README.md) -- [Next](for-when.md)

