---
layout: default
title: Loops
---

`for`, `do...while` and `while` loop syntax is the same in JS as it is in Java.


```javascript
let intArray = [1, 2, 3, 4];

// for loop
for (let i = 0; i < intArray.length; i++) {
  console.log("for loop: " + intArray[i]);
}

// while loop
let keepLooping = false;
while (keepLooping) {
  console.log("while loop, never executes");
}

// do...while loop
keepLooping = false;
do {
  console.log("do-while loop, executes at least once");
} while (keepLooping);
```

### The `for-of` Loop

Similar to Java's enhanced `for` loop (`for ( int num : arrayOfInts ) {}`), JavaScript's for-of loop traverses the elements of an iterable collection - such as an array - placing each item in a variable.

```javascript
// for-of loop
for (let num of intArray) {
  console.log("for-of loop: " + num);
}
```

* Unless your algorithm needs to use the index, this is the simplest way to iterate over an array.

### The `for-in` loop

JavaScript's for-in loop traverses the _indexes_ of a collection, placing each _index_ in the loop variable.

```javascript
// for-in loop
for (let i in intArray) {
  console.log("for-in loop: " + intArray[i]);
}
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
> 
> To keep these two loops straight, remember:
> 
> * for-**O**f puts each **O**bject in the variable.
> 
> * for-**IN** puts each **IN**dex in the variable.


<hr>

[Prev](conditionalStatements.md) | [Up](README.md) | [Next](tryCatchFinally.md)

