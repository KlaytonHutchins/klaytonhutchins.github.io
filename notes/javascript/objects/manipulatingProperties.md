---
layout: default
title: Assigning Properties to Objects
---
After creation, objects can be assigned additional properties.

This assignment is *Ex Nihilo* (latin for 'from nothing'). That is, you may assign properties to any object as needed.

Properties are assigned to objects in two ways: *Dot Notation* and *Subscript Notation*.

#### Dot Notation
*Dot Notation* uses the common OOP syntax of `Object.property` to assign properties.

The object reference is on the left of the period, and the property name is on the right.

```javascript
let obj = {};

obj.name = "value";
//  Assign a 'name' property to the object with a value of "value"

console.log(obj.name); // => "value"
```

If the object, `obj`, does not currently have an existing property of `name`, the property would be added to it. If it did already have a `name` property, the corresponding value would be overridden.

```javascript
let obj = {};

obj.name = "value";
obj.name = "new value"
console.log(obj.name); // => "new value"
```

#### Subscript Notation
*Subscript Notation* uses the string representation of a property's name to access/modify the value of that property.

The object is referenced on the left side of the statement, and the name of the property is placed within square brackets to the right of the name.

```javascript
let obj = {};

obj['name'] = "value"; //  Assign a 'name' property to the object with a value of "value"

console.log(obj['name']); // => "value"
// You can use dot and subscript notation interchangeably
console.log(obj.name); // => "value"
```

*Subscript Notation* is extremely powerful. It can be used to access properties of objects with the returned values from function calls, as well as make use of property names that would be invalid with *Dot Notation* (although for obvious reasons you should avoid this practice).


> ### Skill Drill
> 1. Assign `name`, `email`, `age`, `employed`, and `favoriteMovies` (an array of strings) properties to a `person` object.  
>
> 1. Push your `person` object into the `people` array.  
>
> 1. Create a second `person` object and assign it different values. Push that object into the person array as well.  
>
> 1. Iterate over the array and print out the objects that are stored inside.  

### Deleting Properties
You can remove properties from objects by using the `delete` operator.

```js
let obj = {};

obj.name = "value";

delete obj.name;

console.log(obj.name); // => undefined
```

### Determining If an Object Has a Property
If you want to test to see if an object currently has a property of a particular name assigned to it you can use the `in` keyword or the function `hasOwnProperty`.

```js
let obj = {};
obj.name = "value";

console.log("name" in obj); // => true
console.log(obj.hasOwnProperty("name")); // => true

console.log("test" in obj); // => false
console.log(obj.hasOwnProperty("test")); // => false
```

Alternatively, due to the fact that all uninitialized variables carry a value of `undefined`, we can access the property, and if the value is `undefined` assume it is not a property of the object.

```js
let obj = {};

obj.name; // => undefined
```

 ### Skill++
We said previously that keys can be Strings or Numbers. If a key is a number it can only be accessed via subscript notation.

```js
let obj = {};
obj[0] = "value";

obj.0; // VM114:1 Uncaught SyntaxError: Unexpected number
obj[0]; // "value"
obj["0"] // "value"
```

Arrays in JS are themselves objects.

```js
let arr = [];
typeof arr; // => "object"
```

Each index that is filled adds a property (0, 1, 2...) to the array object. We can then access those properties using subscript notation.

```js
let arr = [];

arr[0] = "Test";

arr[0]; // => "Test"
arr["0"]; // => "Test"
```

<hr>

[Prev](initializingWithProperties.md) -- [Up](README.md) -- [Next](forIn.md)

