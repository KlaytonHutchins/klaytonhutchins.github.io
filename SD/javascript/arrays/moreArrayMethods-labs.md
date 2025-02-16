---
layout: default
title: Array Functions Lab
---

Resources for this lab: [resources/labs/moreArrayMethods](resources/labs/moreArrayMethods)

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

Use `filter`, return a new array which is a subset of the `startingArray` and
does not contain any NaN values.

```js
let ex1 = function(arr) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

### 2 : Modify `ex2` ...  

Use your solution to `ex1` to return a filtered array without NaN, then `reverse` the order of the array, then use the `reduce` function to subtract all of the values.

```js
let ex2 = function(arr) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

### 3 : Modify `ex3` ...  

Use `sort` to order the `startingArray` such that the numbers are in ascending
order, and the NaN values are the last three elements of the array. (***HINT:***
 Use an 'or' operator). Be sure not to modify the original array.

```js
let ex3 = function(arr) {
/******************* Your Solution *******************/

/*****************************************************/
};
```

<hr>

[Prev](filterReduce.md) | [Up](README.md) | [Next](algorithms-labs.md)

