---
layout: default
title: Iterating with forEach and map
---

### `forEach(func(value, index, array))`
* `forEach()` will iterate over each element of an array and apply a provided function to each element as it iterates. The function will be passed three arguments:
    1. `value`: this will be the value at the current index of the array.
    2. `index`: will be the numerical index of the current element.
    3. `array`: the array currently being iterated over (the entire array)
* The `forEach()` function is non-destructive, but you can alter values during iteration by using the arguments passed to your function.

  ```javascript
  let nums = [1,2,3,4,5];
  
  // iterate over an array, log the square of each value
  nums.forEach(function(value, index, array){
    console.log(value * value);
  });
  
  // results:
  1
  4
  9
  16
  25
  
  nums; // [ 1, 2, 3, 4, 5 ] => non-destructive

  // iterate over an array, square the value in each position
  nums.forEach(function(value, index, array){
	  array[index] = value * value;
  });
  
  nums; // [ 1, 4, 9, 16, 25 ] => updated values
  ```  

### `map(func(currentValue, idx, arr))`
* Similar to `forEach()`, `map()` iterates over an array, taking an anonymous function as an argument, which will perform an operation on each element of the array. The returned value of the function will become the value of the element.

  `map` returns an array containing the results of performing the function on each element.

  `map` is also passed three values:

  1. `currentValue`: this will be the value at the current index of the array.
  2. `idx`: will be the numerical index of the current element.
  3. `arr`: the array currently being iterated over (the entire array).

  ```javascript
  let nums = [1,2,3,4,5];
  
  nums.map(function(currentValue, idx, arr) {
	  return currentValue * currentValue;
  }); // [ 1, 4, 9, 16, 25 ]
  ```

> ### Skill Drill
> 1. Create an array of numbers named `nums` that stores the values 1-10.  
>
> 1. Use `forEach` to print out the current index, followed by the number stored there.
>
> 1. Use `map` to add a `!` to the end of each of the numbers in the `nums` array.


<hr>

[Prev](splitJoinSliceSplice.md) | [Up](README.md) | [Next](arrayMethods-labs.md)

