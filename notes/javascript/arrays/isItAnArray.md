---
layout: default
title: Determine If an Object Is an Array
---

JS Arrays are objects.

```javascript
let arr = [];
typeof arr; // 'object'
```

There are multiple ways to determine if an object is an Array, and this can be vital if your code requires an actual Array (not just something that can be iterated...like a string). The easiest way is to use the `Array.isArray(arr)` function.  

`Array.isArray(arr)` : the Array class static function `isArray(arr)` takes a single argument and returns a boolean:

```javascript
let arr = [];
let nonArr = 'hello';

Array.isArray(arr); // true
Array.isArray(nonArr); // false
```

With the ability to determine if an object is an array, you will reduce your risk of calling an Array class function on an object of a different type and causing your code to throw an exception.

<hr>

[Prev](arrayBasics.md) -- [Up](README.md) -- [Next](basicArrays-labs.md)

