---
layout: default
title: Initializing an Object Literal with Properties
---
Object literals can be assigned properties with values on creation.

Object properties are *key-value pairs*.

The property name is the 'key', and is colon-separated from it's 'value'. 
* Spaces before or after the colon don't matter.
* NOTE: property names *can* be numbers, however it is usually preferable to use strings.

Values assigned to properties can be of any type (String, Number, Array, Function, Object, Boolean).

* Additional properties are comma-separated.

```javascript
let dog = { name : "Spuds", breed : "Bull Terrier" };

let ralph = {
  name : "Ralph",
  breed : "Poodle",
  friendly : false
};

let oskar = {
  name : "Oskar",
  age : 3,
  favFoods : [
    "apple",
    "banana",
    "coconut"
  ]
};

let fruit = {
  name: "banana",
  shape: "sphere",
  color: "yellow"
}
```

<hr>

[Prev](creatingObjects.md) -- [Up](README.md) -- [Next](manipulatingProperties.md)

