---
layout: default
title: this in JavaScript Objects
---

JavaScript does not have analogous classes to Object Oriented languages.

JavaScript has *objects* and *functions*.

> ### Skill++
> Technically, a function is just a special type of object.


When a function is invoked, `this` is assigned a value. The value it is assigned can vary based on how the function was invoked.

When dealing with object methods, `this` will be bound to the object which the method is a property of (i.e. *the invoking object*):

```javascript
let dog = {};
dog.name = "Sparky";

// 'dog' is the invoking object, 'this' references 'dog'
dog.sayName = function() {
  return this.name;
}

dog.sayName(); // 'Sparky'
```

It is important to note that `this` will only be bound to the invoking object if a function is called.
* Thus, attempting to assign a value to another property in an object literal with `this` will produce `undefined` (or a radically unexpected result). For example:

```javascript
let dog = {
  fname : 'Sparky',
  lname : 'Le Grange',
  fullName : this.fname + " " + this.lname
};

dog.fullName; // undefined undefined
```

In the above example, `this` is actually referencing the global object (in this case `window`). The reason it is `undefined` is because `window` does not have `fname` or `lname` properties.

Given that the identity of `this` can be confusing, some style guides choose to reassign the value of `this` to a variable name inside of functions for clarity:

```js
let dog = {
  fname : 'Sparky',
  lname : 'Le Grange',
  // Method, when invoked will assign `this` as invoking object
  getFullName : function() {
    let thisDog = this;
    return thisDog.fname + " " + thisDog.lname;
  }
}

dog.getFullName(); // Sparky Le Grange
```

> ### Skill Drill
> 1. Create a variable named `tree`.  
>
> 1. Give `tree` an `age` property, and set it equal to some number.  
>
> 1. Create a method on `tree` named `ageOneYear`, which uses `this` to update the `age` property on `tree`. Call `ageOneYear` and check the `age` property.  
>
> 1. Create another method on `tree` named `isDead`. `isDead` should set the `age` property to `NaN` if the tree is older than 100. Call `isDead` within `ageOneYear`. Use `this`.  
>
> 1. In a `while` loop, until the tree's age is `NaN`, call `ageOneYear` and print the age to console.

<hr>

[Prev](objectMethods.md) | [Up](README.md) | [Next](modules.md)

