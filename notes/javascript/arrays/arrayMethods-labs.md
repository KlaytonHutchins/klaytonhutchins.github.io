---
layout: default
title: Array Functions Lab
---

Resources for this lab: [resources/labs/arrayMethods](resources/labs/arrayMethods)

### Introduction / Goals
This lab will give you experience dealing with JS Array functions,
as well as isolating scope within functions in your application.  

Remember, unlike Java, JavaScript is function scoped, meaning that
anything outside of a function is in the global scope (which is very bad).  

Each of the following exercises will have you perform an operation
within a function (isolating the scope of the operation), and none
of these operations should update the value of the original 'startingArray'.  

### 0 : `startingArray` ...

```js
let startingArray = [
  1,2,3,4,NaN,6,7,8,9,NaN,NaN,12,13,14
];
```

### 1 : Modify `ex1` ...  

Use `splice` and `forEach` to remove all occurrences of `NaN` from the `startingArray`, and replace each with the next number in the sequence (e.g: `[4,NaN]` would become
`[4,5]`).  

Ensure that you do not modify the actual values of `startingArray`, but instead return a new array. (***HINT:*** You will need to create a new array with the values of the one provided as an argument).

```js
let ex1 = function(arr) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

### 2 : Modify `ex2` ...  

Use `map`, return a new array, convert all of the `NaN` values to `0`.

```js
let ex2 = function(arr) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

### 3 : Modify `ex3` ...  

Use array functions to rotate the values of the array input. For example, if the
`spaces` parameter were 5, the array would be rotated 5 spaces:  

```js
let a = [1,2,3,4,NaN,6,7,8,9,NaN,NaN,12,13,14];

ex3(a,5); // => [6,7,8,9,NaN,NaN,12,13,14,1,2,3,4,NaN];
```

```js
let ex3 = function(arr, spaces) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

<hr>

[Prev](forEachMap.md) -- [Up](README.md) -- [Next](shiftUnshift.md)

