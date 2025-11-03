## `for` Loop Parts

`for` loops are useful for iteration because of the structure inside the parentheses.
* The parentheses of a `for` loop contain three expressions, separated by two semicolons, `;`.
* None of the expressions is required.
  * Both `;` are required.

### `for` Loop Expressions

**initialization** - declaring and initializing any variables that might be used in the for loop.
* This is executed _once_.
* Only declaration or assignment is allowed here.

**termination condition** - a condition (which must result in a boolean) to decide whether to end this loop.
* This is evaluated _before every iteration_-even the first one, which means the loop body might not execute at all.
* Only a boolean expression is allowed here.

**increment** - for changing variables.
* This is executed _after each full iteration_.  

```
for (initialization; termination condition; increment)
      loop body
```

### Steps in a `for` Loop

1. `initialization` statement executes.
2. `termination condition` checked. If true, execute the loop.
3. Loop body executes.
4. `increment` executes.
5. Go to step 2.

<hr>

[Prev](for-diagram.md) | [Up](README.md) | [Next](for-body.md)

