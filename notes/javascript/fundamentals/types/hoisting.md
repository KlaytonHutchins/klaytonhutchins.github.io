---
layout: default
title: Variable Hoisting
---

JavaScript has a very unique behavior regarding variables declared with `var`.

By default all such declarations, regardless of their position in the `.js` file, are moved to the top of the scope.

The following examples would behave in the exact same way. Declaring a variable `num`, assigning it the value of 5 `num = 5`, logging the variable `console.log(num)`.

```javascript
num = 5;
console.log(num); // 5
var num;
```

```javascript
var num;
num = 5;
console.log(num); // 5
```

The second code snippet is essentially what the JS interpreter is doing. Every time it sees a statement with the `var` keyword, it moves that variable declaration to the top of the current scope.

#### Initialization is not hoisted

This example demonstrates that only declarations are hoisted, not their subsequent initialization.

```javascript
var num = 5;
var name = "Andrew"
console.log(num); // 5
console.log(name); // Andrew
```

```javascript
var num = 5;
console.log(num); //5
console.log(name);  // undefined
var name = "Andrew"
```

The second statement after the interpreter has hoisted the variables would look like this

```javascript
var num, name;

num = 5;
console.log(num); //5
console.log(name);  // undefined
name = "Andrew"
```


<hr>

[Prev](arrays.md) -- [Up](README.md) -- [Next](scope.md)

