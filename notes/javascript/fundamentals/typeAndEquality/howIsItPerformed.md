---
layout: default
title: How JS Performs Type Conversion
---

### Implicit Type Conversion in JavaScript
Similar to Java, JavaScript provides a set of global wrapper objects that the interpreter uses to attempt type conversion behind the scenes.

Most languages have type conversion, and most of the time is an extremely beneficial language feature.

This is similar to casting a Java object to a different type. However, it does not throw an error, but simply has the potential to produce an unexpected or unwanted result.

For example in JavaScript:

If a multiplication, division, or subtraction operation is being performed:

  * JS will try to convert the operands into numbers using the `Number` global object:

```js
// Our code:
"8" * "9"; // => 72

// Interpreter tries:
Number("8") * Number("9"); // => 72

// When it's not a number:
Number("hello") * Number("9"); // => NaN
```

### Explicit Type Conversion in Java
Alternatively, it is possible to explicitly perform type conversion in Java using static methods provided by the wrapper classes.

```java
public class Test {
  public static void main(String[] args) {

    String age = "29";

    int yearOfBirth = 2016 - Integer.parseInt(age);

    System.out.println(yearOfBirth);

  }
}
```

### Explicit Type Conversion in JavaScript
JavaScript provides similar static methods, but these also will not automatically throw an error:

```js
let stringAge = "29";
let numAge = Number.parseInt(stringAge); // => 29
typeof numAge; // => "number"

let greeting = "hello";
let numGreeting = Number.parseInt(greeting); // => NaN
typeof numGreeting; // => "number"
```

<hr>

[Prev](jsTypeConversion.md) -- [Up](README.md) -- [Next](conversionRefTable.md)

