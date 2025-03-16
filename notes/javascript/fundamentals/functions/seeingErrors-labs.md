---
layout: default
title: Lab - Seeing Errors
---

Resources for this lab: [resources/labs/seeingErrors](resources/labs/seeingErrors)

### 1 : Invoke a function named `greet`, passing your name to the function as an argument ...  

***NOTE:*** At the moment, this will throw `ReferenceError: greet is not defined`  

### 2 : Write a function **declaration** named `greet` which takes one argument (name).  

`greet` should return the string 'Hello {name}' where {name} is the name provided as an argument.  

### 3 : Invoke a function named `farewell`, passing your name to the function as an argument ...  

***NOTE:*** This function will also throw `ReferenceError: greet is not defined`  

### 4 : Write a function **expression** named `farewell`; the assigned function should take one argument ('name').  

`farewell` should return the string 'Goodbye {name}' where {name} is the name
provided as an argument.  

***NOTE:*** The correct solution to this exercise will produce a TypeError. It is important that you understand why this error (instead of a `ReferenceError`) is produced. Think about how the JS interpreter is evaluating the function expression and try to determine exactly what is happening. If you cannot discern why a TypeError has occurred, ask an instructor for help.  

### 5 : Create a new function **expression** named `sayHello`; assign it the value of the `greet` function declaration.  

Invoke `sayHello` and pass it your name. What is the result?  

***NOTE***: At first this code will be unreachable because of the unrecoverable error encountered in your solution to #3. This is a fairly common problem in JavaScript development: if the interpreter encounters an error in a chain of function executions it will just stop executing the chain, making it seem as though things just aren't working. Usually this results from a value being `undefined` when it needed to be something else (e.g. a function). Surround that answer in a `try/catch` in order to allow the interpreter to continue.  

<hr>

[Prev](arrowFunctions.md) -- [Up](README.md) -- [Next](basicFunctions-labs.md)

