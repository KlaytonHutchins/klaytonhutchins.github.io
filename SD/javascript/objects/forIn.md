---
layout: default
title: for...in loops
---
The `for...in` loop is used to iterate over the properties of a JS object.

Syntactically, the `for...in` loop is constructed as `for (aliasForProperty in object) {}`. Below is an example of how it can be used.

```js
let dog = {
  breed : "labrador",
  name : "scout",
  age : 4
};

for (let p in dog) {
  console.log(p + " : " + dog[p]);
}

// breed : labrador
// name : scout
// age : 4
```

The `p` in the example above is a placeholder for the property being iterated over. `p` will be a string representation of the property name. To access the value for that property from the object, you must use subscript notation.

### Example
At first, this syntax may seem strange, but it is very similar to Java's `HashMap<>()`. Instead of using `put()` and `get()` to read and write from the JS object literal, we simply use the name of the property.

Here is an example in Java:

```java
Map<String,String> data = new HashMap<>();
data.put("name","Bob Dobbs");
data.put("email","bdobbs@gmail.com");

System.out.println(data.get("name")); // Bob Dobbs
System.out.println(data.get("email")); // bdobss@gmail.com
```

Here is the JavaScript equivalent:

```js
let data = {};
data.name = "Bob Dobbs";
data.email = "bdobbs@gmail.com";

console.log(data.name); // Bob Dobbs
console.log(data.email); // bdobbs@gmail.com
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create an array called `log`.  
>
> 1. Create an object called `day1` and assign it properties `date` (String representation of the date), `didWorkout` (boolean), `foodConsumed` (an array of strings),
>
> 1. Push the `day1` object into the `log` array.
>
> 1. Create a few other `day` objects and add them to the `log` array as well.
>
> 1. Iterate over the `log` array, and with each iteration perform a second loop (a for...in) and print out the property as well as its corresponding value.

<hr>

[Prev](manipulatingProperties.md) | [Up](README.md) | [Next](objectsAreKeyValuePairs-labs.md)

