---
layout: default
title: Identity (===) vs Equality (==) Operators
---
The `===` operator and `==` operator both evaluate two values and determine if they are the same. However, they use two different definitions of sameness.

The `===` operator (known as the _Strict Equality_ or _Identity_ operator), checks if the two values are identical in the traditional sense.

The `==` operator (known as the _Equality_ operator), uses the truthy, falsy principles.

```javascript
3 === '3' // false
true === 1 // false
false === 0 // false
null === undefined // false
NaN === NaN // false (NaN is never equal to any other value (including itself))
```

> #### Skill ++
> The `==` operator will attempt to perform type conversion before testing the equality of two values.

```javascript
3 == '3' // true
true == 1 // true
false == 0 // true
null == undefined // true
NaN == NaN // false ... NaN is NEVER equal to any other value
```

Both the identity and equality operator will compare like-typed values as expected. When choosing between them it is best to consider if type is paramount (in which case the identity operator should be used), or if type conversion is preferable (for example, in the case of numeric input from a form which will be evaluated as a string...in which case the equality operator is suitable).

In most situations, it is preferable to use the strict equality operator, as its results are more predictable, unless you have a specific reason to coerce type conversion.

<hr>

[Prev](conversionRefTable.md) -- [Up](README.md) -- [Next](isNaN.md)

