---
layout: default
title: To use a semicolon...or not to use a semicolon?
---
*Disclaimer*: this is a subject of near-constant debate. With the belief that some guidelines are better than no guidelines...

### **DO** Use Semicolons
1. After a statement:

    ```js
    let x;
    x = 6;
    let y = 90;
    x = x + y;
    myFunction();
    ```

2. When you have two statements on the same line:

    ```js
    for (let i = 0 ; i < 10 ; i++) {}

    let x; x = 10; let y = x/2; // although for readability...don't do this
    ```

3. With *function expressions*:

    ```js
    // This is an assignment statement, it needs a semicolon
    let myFunction = function(){ };

    // This is a multi-line assignment statement, it also needs a semicolon

    let myOtherFunction = function(num1,num2) {
      //...implementation code
    };
    ```

4. With *do...while loops*:

    ```js
    do {
      // ... something
    } while (true);
    ```

### Do **NOT** Use Semicolons
*General Rule*: With the exception of *function expressions* and *do...while loops*, don't follow a `}` with a semicolon...

1. After a block:

    ```js
    if (true) { }

    for (;;) { }

    while (true) { }
    ```

2. Function statements (be they named or anonymous):
   * *Note*: these functions are not assignment expressions

    ```js
    function () { }

    function namedFunc () { }
    ```

<hr>

[Prev](scope.md) -- [Up](README.md) -- [Next](labs.md)

