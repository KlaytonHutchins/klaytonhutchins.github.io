## Object Methods
**Any** value may be assigned to an object property, including a *function*.

A function that is assigned to a property of an object is referred to as a *method*.

Object methods can be created by assigning a function to a property when an object literal is created:

```javascript
let dog = {
  speak : function() {
    return "woof woof";
  }
}
```

Methods can be assigned with dot notation:

```javascript
let dog = {};

dog.speak = function() {
  return "woof woof";
}
```

Subscript notation can also be used:

```javascript
let dog = {};

dog['speak'] = function() {
  return "woof woof";
}
```

### Invocation
Invoking object methods has to be done through the name assigned to the object, in the form `obj.methodName()`.

If the method is called without the preceding object name, you will get a `Reference Error`.

```js
let dog = {};

dog.speak = function() {
  return "woof woof";
}

dog.speak();  // "woof woof"
```

### Example
JS Object methods are similar to Java instance methods.

Just as you would create a new instance of a class in Java and invoke one if its methods, you can do the same with JS objects. The core difference is that unlike Java, you are not required to create a class definition to create an instance of an object. What's more, you can assign functions to the object and store them in properties dynamically.

```js
let myObj = {};
myObj.makeArray = function(...args) {
  return args;
}

console.log(myObj.makeArray(1,5,2,34,1,67));
```


> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create a new object `let myMath`.
> 1. Assign `myMath` properties like `add(num1,num2)`, `subtract(num1,num2)`, `multiply(num1,num2)` and `divide(num1,num2)`, which return the computed value of each operation.
> 1. Invoke each potential operation and ensure a result is returned.

<hr>

[Prev](objectsAreKeyValuePairs-labs.md) | [Up](README.md) | [Next](this.md)

