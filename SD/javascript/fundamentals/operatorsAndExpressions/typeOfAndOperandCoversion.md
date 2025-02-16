---
layout: default
title: `typeof` and Operand Conversion
---
The `typeof` operator returns a string representation of the type of the provided value.

```javascript
typeof 9; // 'number'
typeof 'hello'; // 'string'
typeof []; // 'object'
typeof {}; // 'object'
typeof function(){}; // 'function'

let x = '9';
typeof x; // 'string'
```

To convert from one primitive type to another (i.e. string/number), there are global methods at your disposal:

1. `parseInt(num);`

    ```javascript
    parseInt('9'); // 9
    parseInt('9.999'); // 9 => note the loss of precision

    parseInt('hello'); // NaN

    parseInt(true); // NaN
    parseInt(false); // NaN

    parseInt([]); // NaN
    parseInt([9]); // 9
    parseInt(['9']); // 9
    parseInt(['9', '6']); // 9 => only parses the first index, ignoring the rest
    ```

1. `parseFloat(num);` functions the same as `parseInt()` except that it preserves the precision of decimal numbers.

    ```javascript
    parseFloat('9'); // 9
    parseFloat('9.999'); // 9.999
    ```

1. `Object.toString()`

    ```javascript
    '89'.toString(); // '89'
    'hello'.toString(); // 'hello'

    56.toString(); // SyntaxError...
    let num = 56;
    num.toString(); // '56'

    [].toString(); // ''
    [1,2,3,4].toString(); // '1,2,3,4'

    {}.toString(); // SyntaxError...
    let obj = {};
    obj.toString(); // '[object Object]'
    ```

<hr>

[Prev](typeConversionAndOperators.md) | [Up](README.md) | [Next](operatorReferenceTable.md)

