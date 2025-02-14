## `isNaN()`
As we have seen, `NaN` is NEVER equal to any other value (including itself).

To evaluate a value and determine if it is not-a-number there is a global method on the Number type `isNaN()`:

```javascript
isNaN(NaN);       // true
isNaN(undefined); // true
isNaN({});        // true

isNaN(true);      // false
isNaN(null);      // false
isNaN(37);        // false

// strings
isNaN("37");      // false: "37" is converted to the number 37 which is not NaN

isNaN("37.37");   // false: "37.37" is converted to the number 37.37 which is not NaN

isNaN("123ABC");  // true:  parseInt("123ABC") is 123 but Number("123ABC") is NaN

isNaN("");        // false: the empty string is converted to 0 which is not NaN

isNaN(" ");       // false: a string with spaces is converted to 0 which is not NaN
```

### Checking to See If Something Is a Number
We can negate the `isNaN()` function if we want to see if a value is a number. When reading this code the language can be a little confusing: "is not not-a-number".

```javascript
!isNaN(NaN);  // false
!isNaN(5);    // true
!isNaN("5");    // true
```

<hr>

[Prev](identityVSequality.md) | [Up](README.md) | [Next](labs.md)

