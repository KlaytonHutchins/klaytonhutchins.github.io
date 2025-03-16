---
layout: default
title: JavaScript Overview  
---

We are on to our next major programming language!

Over the course of this week we are going to learn about JavaScript as a browser scripting language.

Because we now have experience in other languages, we are going to move through the basics much faster than we did with Java.

You will see familiar syntax and structure in many aspects of the two languages, but:

![Java vs. JS](images/java-vs-javascript.jpg)

### How JavaScript Works

JavaScript (JS) is a client-side scripting language.

This means that JavaScript is a non-compiled language that can run inside of browsers.

* The Java programming language needed to be compiled from `.java` to `.class` files, and run in a Java virtual machine.

JavaScript code is loaded into the browser along with the HTML document.

As the browser comes across JS code, it has a built-in interpreter that changes the JS into executable byte code.
* The interpreter reads files within scope (src), and executes expressions / stores values into memory.
* This process only happens once, when the browser originally loads the files.

### Where Do I Write JavaScript?

When writing client-side JS we can write code in two locations.

#### Script tags  
HTML has an element called script tags, `<script></script>`.

* Inside of this element we can write JavaScript, which will execute as the browser encounters it during page load.

These tags can be placed anywhere within the HTML `<body>` or `<head>`.

#### External script files  

Alternatively, we can write JS in separate files that are by convention saved with the `.js` extension.

We can write as many `.js` files as we see fit and import them into an HTML document for use.

Information is available based on the order in which the files are imported into the document.

##### How to Import a JS File  

If we want to include a JS file in a specific HTML document we can import them using `<script src="myScript.js"></script>` syntax.

The `src` attribute takes the relative path to the JS file from the HTML file's location.  

```html
<!DOCTYPE html>
<html>
<head>
  <title>JS import</title>
</head>
<body>
  <script src="myScript.js"></script>
</body>
</html>
```

An HTML document can import as many scripts as you need.

These files can be imported in the head or body of the document.

You will see many programmers load their scripts at the bottom of the `<body>`.

This is to ensure that the entire HTML document has been loaded by the browser before it tries to execute any of our scripts.

> ### Skill Drill
> 1. We are going to be making a number of files while learning JavaScript. For organization sake lets create a directory to store all of our JS code. We currently have an `SD` directory with a `Java` folder. Create a second folder,  `SD/JS`.
>
> 1. Create an HTML document called `helloJS.html`.  
>
> 1. Set up the document's HTML skeleton.  
>
> 1. Inside of your documents body add `<script></script>` tags.  
>
> 1. Inside of these tags use the `console.log()` function to print out a message to the web console. It is similar to the Java `System.out.println()` function.  
>
>     ```html
>     <script>
>       console.log('Hello World');
>     </script>
>     ```
>
> 1. In a browser open your `helloJS.html` file. **Cmd + o**
>
> 1. Open the Chrome dev tools by pressing `Cmd + Opt + J`.  
>
> 1. You should see the message `Hello World` printed in the console.  
>
> 1. Create a second file called `myscript.js`.  
>
> 1. In your HTML file, remove the `<script>` tags and move the `console.log()` code into your JS file.  
>
> 1. Include the JS file into your HTML file using the `<script src="">` syntax shown earlier.
>
> 1. Open the document again in the browser. You should see the same result.  

 [The Chrome Console](chromeConsole.md) 


<hr>

[Up](../README.md) -- [Next](chromeConsole.md)
