---
layout: default
title: filter, reduce
---

### `filter(func(x,i))`
* `filter()` returns a subset of an array based on a function you provide. This function should be a predicate (returning `true` or `false`) which the `filter()` will use to build the collection it returns. The function will be passed two values: the first is the value of the current element; the other is the current index.

  ```javascript
  let nums = [1,2,3,4,5];
  
  // filter only the even values
  nums.filter(function(x) {
	  return x % 2 === 0;
  }); // [ 2, 4 ]
  
  // filter only even indices
  nums.filter(function(x,i) {
	  return i % 2 === 0;
  }); // [ 1, 3, 5 ]
  
  let names = [
    { fname : 'Dario', lname : 'Argento' },
    { fname : 'George', lname : 'Romero' },
    { fname : 'Sam', lname : 'Raimi' },
    { fname : 'Eli', lname : 'Roth' },
    { fname : 'George', lname : 'Lucas' }
  ];
  
  names.filter(function(x,i) {
	  return x.fname === 'George';
  });
  /*
  [ { fname: 'George', lname: 'Romero' },
    { fname: 'George', lname: 'Lucas' } ]
  */
  ```  

### `reduce(func(acc,currentValue)[, startingAccumulatorValue])`
* `reduce()` is used to combine all of the values within an array into a single value. The reduction function can take as many as two arguments. The function is provided two values, which you will perform the combination operation on.
  * `acc` is the accumulated total of the running operation.
  * `currentValue` is the value at each index.

* `reduce()` will use the first index of the array as its starting accumulator value by default. If you would like to use an alternative starting value, you may optionally provide a second argument after the function, which will be the starting accumulator value.

  ```javascript
  let nums = [1,2,3,4,5];
  
  nums.reduce(function(acc,currentValue) {
	  return acc + currentValue;
  }); // 15
  
  nums.reduce(function(acc,currentValue) {
	  return acc * currentValue;
  }); // 120
  
  let mixNums = [1,5,2,9,54,23];
  
  // Return the largest number in the array
  mixNums.reduce(function(acc,currentValue) {
	  return (acc > currentValue) ? acc : currentValue;
  })
  
  let values = [1,5,'kiwi', 'geoff',true];
  
  // Sum all of the strictly number values in an array
  values.reduce(function(acc,currentValue){
	  acc = (typeof acc === 'number') ? acc : 0;
	  currentValue = (typeof currentValue === 'number') ? currentValue : 0;
	  return acc + currentValue;
  }); // 6
  
  ```  


> ### Skill Drill
> 1. Create an array of numbers named `nums` that stores the values 1-10.  
>
> 1. Use `filter()` to return only the numbers from your `nums` array that are even.
>
> 1. Use `reduce()` to sum all of the numbers in your `nums` array.
>

<hr>

[Prev](indexOfLastIndexOf.md) -- [Up](README.md) -- [Next](moreArrayMethods-labs.md)

