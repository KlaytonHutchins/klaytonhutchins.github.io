## Algorithms Lab

Resources for this lab: [resources/labs/algorithms](resources/labs/algorithms)

### Introduction
The following lab will test your ability to manipulate arrays in a non-trivial way. It will also introduce you to Computer Science and Algorithmic concepts that are presumed knowledge in industry.

This lab may take longer to complete than there is time allotted. In the likely situation that you do not complete all of these exercises prior to the end of lab time, begin with this lab during the next block of programming time.

### 0 : Use the following array literal to test all of your functions.

```js
let testArray = [
  8,99,76,90,1009,6520,32,102,109,392,324,203,230,
  12,23,546,234,1231,5346,4235234,1230,989,34230,
  123,242,124356,13,2,3,1,5,68,545,34,62,56
 ];
```

### 1 : Write a function named `linearSearch` ...  
The function will accept two arguments:  

* the first argument is the number you are searching for.

* the second argument is the array you are searching in.

Your goal is to iterate over the provided array, returning the index of the sought
number if it is present, or `-1` if it is not.  

##### Background :
In computer science, linear search or sequential search is a method for finding
a target value within a list. It sequentially checks each element of the list
for the target value until a match is found or until all the elements have been
searched. Linear search has a time complexity of `O(n)`, where 'O' is the
potential growth rate in terms of time for the operation to complete, and the
value between the parentheses represents the worst case scenario for the
operation's total time. In linear search operations, the worst case would be to
iterate over the entire list provided (of length 'n'), thus we represent the
time complexity for this operation as `O(n)`.

* https://en.wikipedia.org/wiki/Linear_search

* https://en.wikipedia.org/wiki/Big_O_notation


### 2 : Write a function named `slice` ...  
***NOTE:*** Do not use JavaScript's *Array.slice()* function.  

The function should accept two arguments:  

* the first argument is the index at which to begin.

* the second argument is the array to modify.

`slice` should return an array comprised of the values of the array provided as
an argument from the provided index to the end of the original array.  

##### Example :
```js
let arr = [0,1,2,3,4,5,6,7,8,9,10];

slice(5, arr); // => [5,6,7,8,9,10];
```
### 3 : Write a function named `includes` ...  
***NOTE:*** Do not use JavaScript's *Array.includes()* function.  

The function should accept two arguments:

* the first argument should be a value to look for.

* the second argument should be an array to look in.

If the value is inside of the array, return true, otherwise, return false.

### 4 : Write a function named `filter` ...  

***NOTE:*** Do not use JavaScript's *Array.filter()* function.  

The function should accept two arguments:  

* the first argument is a value to check exists.

* the second argument is an array.

Your `filter` should return a new array containing a subset of the values in the
array provided as an argument, such that they contain the value provided as the
first argument.  

##### Example :

```js
let arr = [1,11,44,23,65,123];

filter(1,arr); // => [1,11,123];
```

<hr>

[Prev](moreArrayMethods-labs.md) | [Up](README.md)

