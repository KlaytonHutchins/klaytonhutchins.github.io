---
layout: default
title: The Chrome Console  
---

The Chrome console is going to be our primary debugging tool when writing JavaScript. Because it is a non-compiled language, our errors will not be caught prior to trying to execute the code. All of the client side errors that occur, or printouts we include in our code (using `console.log()`), will show up in the Chrome console.

A link to the Chrome DevTools docs can be found [here][devTools].

### What Is It?  

Chrome's dev tools are a
> set of web authoring and debugging tools built into Google Chrome. The DevTools provide web developers deep access into the internals of the browser and their web application.  

To open Chrome's dev tools we have a few options:
* click the chrome menu in the top right corner and select _Tools > Developer Tools_.  
* Right click anywhere in the browser and select _Inspect Element_.  
* Use _Cmd + Opt + J_ to open the Console of the DevTools.  

Up to this point we have used the _Elements_ tab to track our HTML and CSS within the browser. The Console tab is where we will be living while writing our JS.

We will see all the feedback, error messages or logged information for our JavaScript runtime in the browser's console.

### Writing JS
The console can also be used to write live JS to interact with your page in real time. Anything saved to the global scope is accessible in the web console.

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. In a Chrome browser, open the DevTools console.  
> 1. Write the statement `var x = 5;`.
> 1. Enter just `x` and see what is returned.  
> 1. Write the statement `console.log('The value of x is ' + x)`. `console.log()` is equivalent to Java's `System.out.print()`.
> 1. Refresh the page, then try to access the value of `x`. What happens?  

**Note** The undefined message you keep seeing is the return value of the JS statement you executed. If there is no return value, it is undefined.

[devTools]:https://developers.google.com/web/tools/chrome-devtools/

<hr>

[Prev](README.md) | [Up](README.md)

