## JavaScript Type Conversions

JavaScript tries its best to execute any expression by dynamically converting data types.

When a value of one type is expected, you may provide a value of any type and JavaScript will attempt to convert the provided value into the desired type.

In each of these expressions, a boolean is expected but a number or string is used instead.

```javascript
true == 1 // true

if (-999) {
	console.log('of course');
} // 'of course' --> -999 is truthy

if ('hello') {
	console.log('really?');
} // 'really?' --> "hello" is truthy

true == 0 // false
true == '' // false
```

Above, `true` is equivalent to an un-empty string (`'hello'`), but it is not equivalent to an empty string (`''`). 

In JavaScript these variables are said to have _truthy_ and _falsy_ values, which correspond to `true` or `false`.


  * **truthy**
    * Non-empty strings
    * Non-zero numbers
    * Objects
    * Arrays
    * `true`

  * **falsy**
    * Empty strings
    * Zero (`0`)
    * `false`
    * `NaN`
    * `null`
    * `undefined`

Here is an example of how _truthy_ and _falsy_ values can be used with JavaScript:

```javascript
let name; // undefined
let greeting; // undefined

if (name) {
  /*
    name is undefined.

    undefined is a 'falsy' value that will evaluate
    to false in this conditional.

    This 'if' block will be skipped and the code will
    assign a value to greeting in the 'else' block
  */
  greeting = 'Hello ' + name;
} else {
  greeting = 'Hello World!';
}

console.log(greeting); // 'Hello World!'
```

_truthy_ and _falsy_ can be very useful when validating input values before they reach your database:

```javascript
let fname;
let lname = 'Johnson';

if (fname && lname) {
  // Do some server logic to store data
} else {
  throw new Error('Name fields must not be blank');
}

/*
Error: Name fields must not be blank
    at repl:4:7
    at REPLServer.defaultEval (repl.js:164:27)
    at bound (domain.js:280:14)
    at REPLServer.runBound [as eval] (domain.js:293:12)
    at REPLServer.<anonymous> (repl.js:393:12)
    at emitOne (events.js:82:20)
    at REPLServer.emit (events.js:169:7)
    at REPLServer.Interface._onLine (readline.js:210:10)
    at REPLServer.Interface._line (readline.js:549:8)
    at REPLServer.Interface._ttyWrite (readline.js:826:14)
*/

```

<hr>

[Prev](README.md) | [Up](README.md) | [Next](howIsItPerformed.md)

