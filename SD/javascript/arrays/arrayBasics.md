## Array Basics
Array data structures are going to share similar functionality between all languages.

The syntax for a js array is going to look familiar to that of a traditional Java array, the major exception being that they are not typed.

It functions, however, in a manner more similarly to that of an _ArrayList_.

JS arrays actually have a number of functions tied to their class that allow them to be an extremely versatile data structure.


### Creating Arrays

To create a new array literal with no starting values, we simply use `[]`
```javascript
let nums = [];
```

If we instead wanted to create an array with values, we could list the values separated by a comma.
```javascript
let nums = [1,2,3,4];
let names = ["Andrew", "Kris"];
```

### Accessing Properties and Values
Once an array has been created we can check how many elements are stored inside of it with the `.length` property.
```javascript
let nums = [1,2,3,4];
nums.length;     // 4
```

To access a specific element in an array we can use subscript notation, just like in Java.
```javascript
let nums = [1,2,3,4];
nums[2];         // 3
```

### Adding to an Array `push(value)`
Add an item to the end of an Array and return the resulting length of the Array.

```javascript
let arr = [1,2,3];
arr.push('kiwi'); // 4

arr; // [1,2,3,'kiwi']
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> * Create a folder ArrayHandsOn in `SD/JS`. Inside of this location create an `array.js` file and an `array.html` file. We will use this file for all of the hands ons in this chapter.
> * Assign an empty array to a variable named `classmates`.  
>
> * Use `push()` to add the names of your classmates to the array.


### Removing from an Array `pop()`
Remove and return the last item in an Array.

```javascript
let arr = [1,2,3,4];
arr.pop(); // 4

arr; // [1,2,3]
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> * Use `pop()` to store the last name from your `classmates` array into a variable named `last`.  
>
> * Use `console.log` to print out `last`, and use another `console.log` to print out the `classmates` array.

<hr>

[Prev](README.md) | [Up](README.md) | [Next](isItAnArray.md)

