---
layout: default
title: Steps in a `while` Loop
---

## Steps in a `while` Loop

```
while (condition) {
  loop body
}
```
1. _condition_ is checked. If `true`, execute the loop block.
2. _loop body_ executes.
3. Go to step 1.

The _condition_ in a while loop is always checked.
* This means a `while` loop can execute 0 or more times.
  * That is, if the _condition_ is false when Java first reaches the loop, then the loop never executes at all.

If the _condition_ never becomes false, we end up in an "infinite loop".
* This can be useful, but may be a bug.

### Drill
`WhileLoops/src/drills/WhileLoopSteps.java`
* Write a `while` loop that will accept a number from the user, multiply it by 2, and print the value to the screen. The program should accept data from the user until the user enters zero.

<hr>

[Prev](while-detailed.md) -- [Up](README.md) -- [Next](scope.md)

