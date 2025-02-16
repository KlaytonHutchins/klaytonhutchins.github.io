---
layout: default
title: split, join, slice, splice
---

### `String.split(separator)`
* `split(separator)` is a string function which divides a string into an array based on some delimiter.

  ```js
  let sentence = "sally sells sea shells by the sea shore";
  let wordArray = sentence.split(" ");
  
  wordArray; // ["sally", "sells", "sea", "shells", "by", "the", "sea", "shore"]
  ```  

### `join(separator)`
* Returns a concatenated string of all of the values in an Array (defaults to commas);

  ```javascript
  let arr = [1,true,'hello','mango'];
  
  let joined = arr.join();
  joined; // '1,true,hello,mango'
  
  let spaced = arr.join(' ');
  spaced; // '1 true hello mango'
  
  let and = arr.join(' and ');
  and; // '1 and true and hello and mango'
  ```  

### `slice(startIndex, endIndex)`
* Returns a slice (subarray) of the array from the index specified at the first argument up to (but not including) the number provided at the index specified by the second argument. If no second argument is provided, it will create a subarray from the start index to the end of the array. **NOTE** `slice` is non-destructive. It returns a subarray, but does not alter the original.

  ```javascript
  let arr = ['zero','one','two','three'];
  
  let sub = arr.slice(2);
  sub; // [ 'two', 'three' ]
  
  let sub2 = arr.slice(0,2);
  sub2; // [ 'zero', 'one' ] => Note the non-inclusivity
  
  arr; // [ 'zero', 'one', 'two', 'three' ] => Non-destructive
  ```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill++
  > Remember that assigning an array to a variable assigns a _reference_ to the original array:
  > 
  > ```javascript
  > let arrRef = arr;
  > console.log(arrRef === arr); // true
  > ```
  > With no arguments, `slice` returns a complete copy of the original array:
  > 
  > ```javascript
  > let arrCopy = arr.slice();
  > console.log(arrCopy === arr); // false
  > ```
  > This is an easy way to create a copy of an array.  Another way is to use the spread opertator:
  > 
  > ```javascript
  > let arrCopy2 = [...arr];
  > console.log(arrCopy2 === arr); // false
  > ```

### `splice(delStartIndex, delEndIndex, itemToInsert, ...)`
* Destructively deletes, inserts, or both inserts and deletes from an Array, modifying the original array in the process.
  * The first argument specifies the index to begin the deletion/insertion.
  * The second argument indicates how many indices to remove after the starting point. (**NOTE** providing a `0` will lead to no deletions).
  * All subsequent arguments provided will be inserted into the array at the index specified by the first argument.
  * `splice` returns an array of deleted items.

  ```javascript
  let ogArray = ['apple', 'banana', 'coconut'];
  
  ogArray.splice(1); // [ 'banana', 'coconut' ] => returns deleted elements
  
  ogArray; // [ 'apple' ] => destructive update of original
  
  //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
  
  let removeTheMiddleArray = ['Reese', 'Malcom', 'Dewey'];
  
  removeTheMiddleArray.splice(1,1); // [ 'Malcom' ]
  
  removeTheMiddleArray; // [ 'Reese', 'Dewey' ]
  
  //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
  
  // There should be a 4 where it says 'kiwi'
  let incorrectArray = [1,2,3,'kiwi',5,6,7];
  
  incorrectArray.splice(3,1,4); // [ 'kiwi' ] => remove 'kiwi'
  
  incorrectArray; // [ 1, 2, 3, 4, 5, 6, 7 ] => 4 has been inserted
  
  //\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
  
  // Add several items
  let missingData = ['death', 'taxes'];
  
  missingData.splice(1,0,'bananas','jobs','school','friends'); // [] => nothing deleted
  
  missingData; // [ 'death', 'bananas', 'jobs', 'school', 'friends', 'taxes' ]
  
  ```

> ### Hands On:
> 1. Create a variable `data` which stores a String of comma-separated words as values.  
>
> 1. Use `split()` on `data` and assign the resulting array to a variable `dataArray`.
>
> 1. Use `join` on the `dataArray` to concatenate all of the values with `//` and store the string back into the `data` variable.
>
> 1. Create a new variable named `initialData`, and use `splice` on `dataArray` to store only the first two data points into `initialData`.
>
> 1. Use `splice` on `initialData` to insert `"First Data Point"` at the 0th index.  
>
> 1. Use `splice` on `initialData` again to insert `"Third Data Point"` at the 2nd index.
>
> 1. Use `splice` on `initialData` again to delete everything after the first data point (1st index).

<hr>

[Prev](basicArrays-labs.md) | [Up](README.md) | [Next](forEachMap.md)

