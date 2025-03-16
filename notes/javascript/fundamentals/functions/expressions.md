---
layout: default
title: Function Expressions
---

JavaScript functions can be stored as values.

This is important: **JAVASCRIPT FUNCTIONS CAN BE STORED AS VALUES**.

* They can be stored in variables.

* They can be passed as arguments to other functions.

Below is an example of how this can be accomplished with a declared function:

```javascript
function square(num) {
  return num*num;
}

let exponential = square;

square(5); // 25
exponential(5); // 25

```

A function can be referenced by name and stored within a variable. 

This will pass the entire function declaration as a value.

**NOTE**: invoking the function will store the return value of the function in the variable, not the function itself.

```javascript
function sayHello() {
  return 'Hello!';
}

let greet = sayHello(); // 'Hello!'

let greetFunc = sayHello; // function sayHello() { return 'Hello!' }

greetFunc(); // 'Hello!'
```

The advantage to storing a function into a variable (or "creating a function expression") is that it explicitly assigns the function to a variable in the current scope. 

This prevents the function definition from polluting the namespace of a higher scope.

### Assigning a Function Expression an Anonymous Function

Functions without names are called *Anonymous Functions*.

```js
function (x,y) {
  // implementation
}
```

On their own, *Anonymous Functions* are not very useful as they cannot be invoked.

*Anonymous Functions* can be assigned to variables, in which case they become function expressions and can be invoked by the variable name.

```js
let doMultiplyValues = function(x,y) {
  return x * y;
}

doMultiplyValues(1,2); // 2
```

<hr>

[Prev](parameters.md) -- [Up](README.md) -- [Next](scope.md)

