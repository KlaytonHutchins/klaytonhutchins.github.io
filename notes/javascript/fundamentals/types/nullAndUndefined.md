---
layout: default
title: Null & Undefined
---
`null` represents the absence of a value.

`null` is **not** a default value for a variable. It represents an intentional choice, potentially signifying the absence of data in correctly functioning code.

`undefined` also corresponds to a non-value. However, unlike `null`, it represents the value of _uninitialized_ variables, or parameters that have no value associated with them.

You can think of `null` values as non-error representations of nothing, whereas `undefined` usually corresponds to the lack of a value that was expected.  

```javascript
var nope; // undefined

nope = null; // null
```

<hr>

[Prev](strings.md) -- [Up](README.md) -- [Next](arrays.md)

