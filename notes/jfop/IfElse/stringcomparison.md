---
layout: default
title: Comparing Strings in Java
---

## Comparing Strings in Java

Be careful comparing Strings in a control flow statement.

You should not use the `==` operator.
* Instead, you should use the special method called `equals()` that is built into every `String`.

```java
String fName = "John";
String lName = "Doe";
// if (fName == lName) // Wrong!
if ( fName.equals(lName) ) { // Right!
  System.out.println("Same first and last names");
}
```

### Practice Exercise
We are using this `equals` method differently than other methods we have written or used. Methods will be explained in much more detail later.


For now, just know that this `equals` method evaluates to a `boolean`; it has to since it is an `if ( )` statement's condition.

### Drill
`IfElse/src/drills/StringComparison.java`
* Run the program with a proper name.
* Fix the code to no longer use `==`.

<hr>

[Prev](nesting.md) -- [Up](README.md) -- [Next](labs.md)

