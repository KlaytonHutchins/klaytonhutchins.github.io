## Strings
A string can be defined with either single or double quotes:

```javascript
var firstName = "Steven";
var lastName = 'Gregory';
```

String comparison in JavaScript is possible using the `==` comparator. There is no `.equals()` like we used in Java:

```javascript
var x = 'hello';
x == 'hello' // true
x == 'squirrel' // false
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> Do this drill in the Chrome Console.
>
> 1. Create a new string using double quotes, and include single quotes inside of it.
>    * Type the variable name into the console and press return, what happened when you included the single quotes within the double quotes?
>    * Now wrap single quotes around double quotes. What is the result?
>
> 1. Add two strings with the `+` operator. `console.log()` the result.
>
> 1. Subtract one string from another with the `-` operator. What happens?
>
> 1. JavaScript's strings are collections of characters (similar to Java). In JavaScript, this means that you can access individual characters of a string with *subscript notation* similar to Array access in Java:
>
>    ```javascript
>    var greet = "Hello World";
>    greet[0]; // "H"
>    ```
>
>    * Try it for yourself!

### Template Literals
Support for a more dynamic string manipulation technique, template literals was added to ES6.

It gives us string expression interpolation for single and multiline strings.

A template String starts with back ticks, \`\`, as oppoed to single ('') or double ("") quotes.

Variables can be added to a template sting using `${}` notation.

```js
var fname = "Douglas";
var lname = "Johnson";

var greetingConcat = "Hello my name is " + fname + " " + lname;
var greetingTemplate = `Hello my name is ${fname} ${lname}`;
```

<hr>

[Prev](numbers.md) | [Up](README.md) | [Next](nullAndUndefined.md)

