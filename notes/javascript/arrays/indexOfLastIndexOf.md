---
layout: default
title: indexOf, lastIndexOf
---

### `indexOf(value)`
* Returns the first index of the object being sought, or `-1` if it does not exist in the array. Searches from beginning to end of the array.

  ```javascript
  let obj = {name : 'test'};
  let arr = [1,2,3,'kiwi', obj];
  
  arr.indexOf(3); // 2
  arr.indexOf('kiwi'); // 3
  arr.indexOf(obj); // 4
  
  arr.indexOf('not found'); // -1
  ```

### `lastIndexOf(value)`
* Returns the last index of the object being sought, or `-1` if it does not exist in the array. Searches from the end to the beginning of the array.

  ```javascript
  let arr = [1,2,3,4,3,2,1];
  
  arr.lastIndexOf(1); // 6
  arr.lastIndexOf(2); // 5
  arr.lastIndexOf(3); // 4
  arr.lastIndexOf('not found'); // -1
  ```

> ### Skill Drill
> 1. Create the following array:
    ```javascript  
    let arr = ["Apple", "Banana", "Coconut", "Apple"];
    ```
>
> 1. Write a function `contains` that uses `indexOf` to determine if the value is in the array or not.
>
> 1. Use the `lastIndexOf` function on `arr` to determine at what index the string `"Apple"` is stored.

<hr>

[Prev](reverseSort.md) | [Up](README.md) | [Next](filterReduce.md)

