---
layout: default
title: shift, unshift
---

All of these functions are responsible for either adding a item to an existing array, or removing an item from an existing array.

### `shift()`
Remove and return the first item in an Array.

```javascript
let arr = [1,2,3,4];
arr.shift(); // 1

arr; // [2,3,4]
```  

### `unshift(value)`
Add an item to the beginning of an Array and return the resulting length of the Array.

```javascript
let arr = [1,2,3,4];
arr.unshift('kiwi'); // 5

arr; // ['kiwi',1,2,3,4]
```  

> ### Skill Drill
> 1. Create a `classmates` array, that has the string representation of a few of your class' first names inside of it.
>
> 1. Use `shift()` to store the first name from your `classmates` array into a variable named `first`.  
>
> 1. Use `console.log` to print out `first`, use another `console.log` to print out the `classmates` array.
>
> 1. Use `unshift()` to add the first name of three new people to your `classmates` array.  
>
> 1. Use `console.log` to print out the `classmates` array.

<hr>

[Prev](arrayMethods-labs.md) -- [Up](README.md) -- [Next](reverseSort.md)

