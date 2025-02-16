---
layout: default
title: Numbers
---
In JavaScript there are no 'types' of numbers. However, decimal points do add precision to a degree. 'Integer' (non-decimal) values are accurate up to 15 digits, while decimals are accurate up to 17 digits.

Floating point arithmetic can be inaccurate:

```javascript
var x = 0.1 + 0.2; // 0.30000000000000004
```

### NaN
The worst name in all of programming goes to `NaN`.

`NaN` (not-a-number) is a number type. `NaN` results from operations in which the result is non-numerical, like trying to divide a number by a string.

```javascript
var x = 5/"Banana"; // NaN
```

> ### ![Logo](http://skilldistillery.com/downloads/sd_logo.jpg) Skill Drill
> 1. In the Chrome developers console, practice declaring and initializing variables.
>
> 1. Declare a variable `num`.
>    * Assign `num` the value of `4/0`. Type the variable name (`num`) into the console and press 'return'. What is the value of `num`?
>    * What is `num - 5`?
>    * What is `num - num`?
> 1. `NaN` is a valid number in JavaScript, but what happens when you subtract a number from it? (`NaN -4`)

<hr>

[Prev](declarations.md) | [Up](README.md) | [Next](strings.md)

