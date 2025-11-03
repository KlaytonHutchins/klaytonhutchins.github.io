## JSP EL Operators
JSP EL is an entire language, complete with literals and operators.

### JSP EL Literals
* Boolean — Use the `true` and `false` literals to represent boolean content.
* Integer — The rules for integer literals in EL are the same as for Java.
* Floating Point — The rules for floating point literals in EL are also the same as for Java.
* String — To embed literal strings in an EL expression, surround them with single or double quotes.
* Null — Use the `null` literal to represent null content.

### JSP EL Operators
* Binary arithmetic operators: `+`, `-`, `*`, `/`, `div`, `%`, `mod`
* Logical binary operators: `and`, `or`, `&&`, `||`
* Unary negation operators: `not`, `!`
* Binary relational operators: `<`, `<=`, `==`, `>=`, `>`, `lt`, `le`, `eq`, `ge`, `gt`
* Conditional/Ternary operator: `?:`
* Empty operator: `empty`.
  * The `empty` operator checks to see if a value is null or empty, and, if so, evaluates to true.

The EL is very forgiving. It will convert the variable to the correct type based on what you are trying to do with it.
* NullPointerExceptions and ArrayIndexOutOfBoundsExceptions are not thrown; instead, the expression will yield an empty string.
* However, if you use the `.` operator to access a JavaBean property that does not exist, you will see `HTTP Status 500 – Internal Server Error`.

> ### Practice Exercise
> While we _can_ use operators on the JSP page, it is better to keep complex logic in the servlet. Testing a view (JSP) often means visiting a page and entering data.
>
> It is better to write JUnit tests, or use some other automated testing framework, than manually input data and verify a change visually.

<hr>

[Prev](java-beans.md) | [Up](README.md) | [Next](labs.md)

