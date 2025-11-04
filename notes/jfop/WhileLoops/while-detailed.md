---
layout: default
title: `while` Loops - Detail
---


The basic syntax of a `while` loop looks like

```
while (condition)
  loop body
```

The first statement or the first _code block_ after a `while` statement is considered its body.

> #### code block ####
> Anything in curly braces `{  }`.

For more than one statement to execute as part of the `while` loop, we need curly braces.

```
// Curly braces are required for multiple loop body statements
while (condition) {
  loop body
  more loop body
}
```

Use a code block for your loop body even if it is only a single statement.
* It makes the code not only more readable, but less prone to errors when you modify it later.

```java
// NO
while (condition)
  statement;

// YES
while (condition) {
  statement;
}
```

<hr>

[Prev](while.md) -- [Up](README.md) -- [Next](while-steps.md)

