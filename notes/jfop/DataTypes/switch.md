## `switch` and Data Types

Below is the list of primitives we can use in a `switch` statement.

* `byte`
* `char`
* `short`
* `int`

This means we cannot use these types:

* `long`
* `float`
* `double`
* `boolean`

### Practice Exercise
How can you remember what can't be used?
* Floating-point numbers can be imprecise, so they don't make good cases.
* If `boolean` could be used, what would the `default:` case be?
* `long` - just commit that one to (your) memory. It was a design decision by the creators of Java. Also imagine a switch with 18 quintillion possible cases.

<hr>

[Prev](long.md) -- [Up](README.md) -- [Next](labs.md)

