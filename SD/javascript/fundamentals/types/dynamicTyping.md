---
layout: default
title: _Untyped_ vs _Typed_
---

### *Typed* Languages
A language is *Typed* (where variables are *Statically Typed* - assigned before runtime) if the type of a reference value is restricted to the type of value it can represent. As an example:
  * `int num;` is a Java variable typed as an `int`. When declared, 4 bytes (32-bits) are reserved in memory to store this value.

  * At compile and runtime, if a `String` value is assigned to a variable typed `int` (`num = "banana";`), an 'Incompatible types:' exception will be thrown.
    ```java
      int num = 5;
      num = "banana"
    ```

  * The compiler enforces the type constraint as much as possible.

A benefit of *Typed* languages is that typing violations will cause errors during compilation (fail loudly), making bugs and errors easy to spot.

However, due to the necessity of compilation and explicit type conversion, *Typed* languages are perceived to be harder and more time-consuming to develop with.

### *Untyped* Languages
A language is *Untyped* (where variables are *Dynamically Typed* at runtime) if the type of a reference variable is not assigned and thus does not restrict the type of the value it can represent. This means that a program will always run (or attempt to run). For example:

  * `var num;` is a JavaScript variable declaration. Its value and type are `undefined` as no value has been assigned to the variable.

  * Later in the program we assign a number value to the variable: `num = 1;`.

  * Even later in the program we assign a string value to the variable: `num = "banana";`

  * Both of these assignments are valid. As the JavaScript Interpreter evaluates expressions at runtime it will dynamically resize the memory available for a variable's value and garbage collect as needed.

*Untyped* languages benefit from the lack of types by being fast and lightweight to develop with.

Unfortunately, it is more difficult to catch bugs in a runtime environment, and untyped languages frequently suffer from 'silent' failures which can be difficult to debug.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. Create an `index.html` and `script.js` file. Source the `script.js` file in your html file.
>
> 1. Open a browser, and use dev tools to open the Chrome Console. This console is the standard out for browser JavaScript.
>
> 1. In your `script.js` declare a JavaScript variable with the `var` keyword, followed by some name for that variable (i.e. `var x;`). This is a JavaScript statement, and it is convention in JS to close statements with a semicolon `;`. Unlike Java, the exclusion of the semicolon will not necessarily throw an error, but it is best practice.
>
> 1. Now check the value of the variable by using `console.log()` to print the value of the variable to standard out (this is analogous to Java's `System.out.println()`).
>
> 1. You may assign a value to an existing variable just as you would in Java by placing a variable name on the left side of the expression, followed by the assignment operator, followed by some value (e.g. `x = 4;`). Assign your variable a value. Afterwards, print the value to standard out with `console.log()`.
>
> 1. You may also initialize a variable with a value. Create a new variable and assign it a value in a single expression, then print the value to standard out.
>
> 1. JavaScript is dynamically typed, so all of the variables we have created have their type evaluated at runtime. This means that a single variable can hold any type. Assign one of the variables a string instead of a number (or a number a string). Are there any errors? What is the value when you print it to standard out?

<hr>

[Prev](README.md) | [Up](README.md) | [Next](primitives.md)

