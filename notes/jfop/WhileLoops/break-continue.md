## `break` and `continue` Statements

We can change how a loop iterates.

* Sometimes we may want a single iteration, or the entire loop itself, to end early.

Two keywords inside a loop can change how it iterates.

### break

Adding a `break;` statement in a loop will cause the program to exit the loop and continue executing after the loop.

```java
//This loop exits when i is equal to 5
int i = 0;
while (true) {  // this loop never ends on its own
  i = i + 1;
  if (i == 5) {
    break;
  }
  System.out.println(i);
}
```

Most "infinite" loops aren't actually infinite - there is code inside the loop body which will cause it to exit, perhaps in response to user input.

* The loop statement itself however doesn't include an exit condition.

### Practice Exercise
The Java compiler can tell if an "infinite" loop actually has a way to terminate.
```java
while (true) {
  // ... code to execute forever
  if ( /* some condition */ ) break;
}
int x = 0; // reachable, because it's possible the loop will exit.
```

### `continue`

The statement `continue;` causes the loop to skip the rest of the current iteration.

* The loop then checks its condition to see if it should execute again.

```java
//Go to the next iteration when i is equal to 5
int j = 0;
while (j <= 10) {
  j = j + 1;
  if (j == 5) {
    continue;
  }
  System.out.println(j);
}
```

### Drill
`WhileLoops/src/drills/WhileLoopBreakContinue.java`
* Try the loops in the examples above in code.
* Write a `do-while` loop that accepts an `int` from a user, and exits when the user types `0`.
* Write an infinite loop that accepts String values from the user. Exit when the user types `quit`. If the user types a different word, output it to the screen. Hint: check if the user's input equals "quit" by using the statement
  ```java
  if ("quit".equals(YOUR_INPUT_VARIABLE))
  ```

<hr>

[Prev](infinite.md) | [Up](README.md) | [Next](labs.md)

