---
layout: default
title: Scoping - let and const
---

The `var` keyword is function-scoped in JavaScript and can cause some unexpected behaviors.

```js
for (var x = 0; x< 10; x++){
  //...
}

console.log(x);   // 10
```

A variable declared with `var` outside a function (much more on JavaScript functions later) becomes a global variable.

* Global variables can lead to unwanted and hard-to-diagnose side effects in large applications.

ES6 introduced the `let` keyword which creates block-scoped variables, which is what we are more familiar with from Java.

```js
for (let j=0; j< 10; j++){
  //...
}

console.log(j);     // Uncaught ReferenceError: j is not defined
```

* These are also called _lexically-scoped_ variables.

Lexically-scoped variables are generally preferable to function/global scope variables.

### Constants

At the same time as `let`, JavaScript added support for constant variables (immutable).

* These variables can not be re-assigned after their initial assignment.

```javascript
const pi = 3.14159;
```

Attempting to reassign the `const` variable will cause a `TypeError`.

```javascript
const pi = 3.14159;
pi = 4;   // Uncaught TypeError: Assignment to constant variable.
```

A `const` variable _must_ be initialized in its declaration.

```javascript
const pi;    // Uncaught SyntaxError: Missing initializer in const declaration
pi = 3.14159;
``` 

Unlike `var` declarations, declarations using `let` or `const` are _NOT_ hoisted.

```javascript
name = 'Fred';
console.log(name);
var name;  // JS hoists declaration to top of scope
```

```javascript
name = 'Fred';  // Uncaught ReferenceError: Cannot access 'name' before initialization
console.log(name);
let name;
```

> ### Skill++
> 
> You will find many examples, tutorials, etc. that use `var`, especially older ones.  For our purposes as we learn JavaScript, using `var` probably won't cause problems in our code or make any difference in our code's logic.
> 
> However, using lexically-scoped variables avoids a variety of subtle and hard-to-find types of bug (which is why they were added to JavaScript), so get in the habit now of declaring variables with `let` or `const`.


<hr>

[Prev](hoisting.md) | [Up](README.md) | [Next](statementTermination.md)

