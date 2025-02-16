---
layout: default
title: Arrow Functions
---

JavaScript has syntax similar to lambda functions in Java.

Arrow functions provide us with a shorter syntax for anonymous functions as well as a non binding `this` variable.

Arrow functions in JS look like this:

```js
(x) => {console.log(x)}
```

  * Argument list: `(x)` the parentheses are optional if there is only one argument
  * Arrow Token: `=>`
  * Expression Body: `{}` the body of the function

They can be passed as anonymous functions

```js
let arr = [1,2,3,4];

// anonymous function expression:
arr.forEach( function(val, idx, arr) {
  console.log(val);
});

// arrow function:
arr.forEach( (val, idx, arr) => {
  console.log(val);
});
```

### `this`

In JS the value of `this` is set when a function is invoked and refers to the function itself. 

Arrow functions do not have their own value of `this`. 

* The `this` variable is inherited from the current scope of the arrow function.

> ### Skill Drill
> 1. Create an array `let arr = ["Apple", "Banana", "Coconut", 45, 12, 2, true];`.
> 1. Use the `.find` method in conjunction with an arrow function to find the element `"Coconut"`. If you do not know how to use the `.find` method take at the documentation [here](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/find).

<hr>

[Prev](higherOrder.md) | [Up](README.md) | [Next](seeingErrors-labs.md)

