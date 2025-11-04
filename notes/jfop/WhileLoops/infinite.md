---
layout: default
title: Infinite Loops
---


An _infinite loop_ is one that doesn't know when to stop; it loops forever.

```
while (true) {
  // ... code to execute over and over
}
```
Why? What are the uses?

* If a program presents a menu, you choose an option, and then you are presented with the menu again, you are using an infinite loop.
  * The loop will continue until you break out of it by entering the "quit" option.

Since an infinite loop will make your program run forever, there has to be a way to get out of the loop.

### Practice Exercise
If a program has an infinite loop with no way of exiting the loop, any code after the loop is considered _unreachable_.

Unreachable code is code that has no way of executing.

Unreachable code causes a compiler error.
```java
while (true) {
  // ... code to execute forever
}
int x = 0; // WILL NOT COMPILE, Unreachable code.
```

<hr>

[Prev](do-while.md) -- [Up](README.md) -- [Next](break-continue.md)

