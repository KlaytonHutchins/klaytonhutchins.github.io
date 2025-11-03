---
layout: default
title: The Pattern Cla
---

## The Pattern Class

Use `Pattern.compile(String regex)` to create a `Pattern` object.

```java
Pattern pat1 = Pattern.compile("cat|dog|frog");
```
* This will match any of the alternatives, `cat` or `dog` or `frog`.

You can split a string with `Pattern.split(CharSequence c)`.

* Your regex defines the delimiter on which to split.

  ```java
  Pattern p = Pattern.compile("[|]"); 
  String[] words = p.split("This|is|a|test.");￼
  ```
  * This will split on the `|` character in the data - in the pattern, `|` is in square brackets making it a literal.

For a single-use pattern match:

```java
boolean b = Pattern.matches("^Kha{3,}n!+", someString);
```

To set regex options, use `Pattern.compile(String regex, int flags)`

* The `Pattern` class defines a number of standard regex options including:

  |Flag|Usage|
  |---|---|
  |CASE_INSENSITIVE|Allows case-insensitive matching.|
  |COMMENTS|Allows white space and comments in a pattern.|
  |MULTILINE|Searches for patterns in a multiline string.|

  * The following will match text starting with "CAT", "Cat", "cat", etc. . .

    ```java
    Pattern p = Pattern.compile("^cat", Pattern.CASE_INSENSITIVE);
    ```

  * Combine multiple options with the bitwise-or operator:

    ```java
    Pattern p = Pattern.compile("^cat", Pattern.CASE_INSENSITIVE | Pattern.MULTILINE);
    ```

### Practice Exercise
> _bitwise-or_
> 
> When used in a numeric expression, the `|` operator yields a number with all of the bits that are set in either of its operands:
> 
> ```java
> int a = 4;          // 0b00000100
> int b = 16;         // 0b00010000
> int result = a | b; // 0b00010100, or 20
> ```
> 
> This can be a convenient way to pass a list of options to a method, without having to define a separate method parameter for each option.


<hr>

[Prev](regexJava.md) -- [Up](README.md) -- [Next](matcher.md)

