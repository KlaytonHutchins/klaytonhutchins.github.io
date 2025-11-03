---
layout: default
title: The `StringBuilder` Cla
---

## The `StringBuilder` Class

Often we build text dynamically in our code resulting in a `String` made from other variables and string literals.

* Repeated `String` concatenation can result in the creation of large numbers of `String` objects, wasting memory and increasing the need for expensive garbage collecion.

  ```java
  String userName = "bdobbs";         // "bdobbs" in String Pool.
  String appName = "ThisApp";         // "ThisApp" in String Pool.
  String message = "Welcome, "        // "Welcome, " in String Pool.
                   + userName         // "Welcome, bdobbs" on heap.
                   + "!\n\n";         // "Welcome, bdobbs!\n\n" on heap, "Welcome, bdobbs" discarded.
  message += "You have logged into "; // New message on heap, previous version discarded.
  message += appName;                 // New message on heap, previous version discarded.
  message += ", please enjoy.\n";     // New message on heap, previous version discarded.
  System.out.println(message);
  ```

The `StringBuilder` class lets us build dynamic text much more efficiently.

`StringBuilder` encapsulates a `char` array, but unlike `String` allows us to modify its contents, automatically adding more capacity as our text grows.

* Unlike immutable `String`s, a `StringBuilder` is mutable.

```java
StringBuilder messageBuilder = new StringBuilder();
messageBuilder.append("Welcome, "); // "Welcome, " copied into messageBuilder's char array.
messageBuilder.append(userName);    // "bdobbs" copied into messageBuilder's char array
messageBuilder.append("!\n\n");     // messageBuilder automatically allocates a larger array,
                                    // copies "Welcome, bdobbs" and "!\n\n" into it.
messageBuilder.append("You have logged into "); // Copied into char array
messageBuilder.append(appName);                 // Copied into char array
messageBuilder.append(", please enjoy.");       // Copied into char array
message = messageBuilder.toString();            // Make a new String from char array on heap
System.out.println(message);
```

### `StringBuilder` constructors

`new StringBuilder()` constructs an object with an initial capacity of 16 characters, but no actual content.

* That is, the `StringBuilder` object contains a `char` array with length of 16, but no characters.

* As text is added to fill the array, the `StringBuilder` automatically copies its contents to a new, larger array.

`new StringBuilder("Some Text")` constructs an object with an internal `char` array containing "Some Text", plus 16 empty `char` slots.

`new StringBuilder(100)` constructs an object with an empty `char` array of length 100.

* If you have an idea how long your text will be, this preallocates enough capacity and saves your `StringBuilder` some work.



### Practice Exercise
In Java's earlier days, programmers used the `StringBuffer` class to build dynamic text.  `StringBuffer` is designed to be safe for use in multi-threaded programs, at a cost in performance.  `StringBuilder` was created to work exactly like `StringBuffer` but is not thread-safe and is therefore faster. Java recommends using `StringBuilder` over `StringBuffer` wherever possible.

<hr>

[Prev](StringMethods.md) -- [Up](README.md) -- [Next](StringBuilderMethods.md)

