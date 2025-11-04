---
layout: default
title: `Character`
---


A `Character` object encapsulates a single Unicode `char` value.

### Constants

* `MIN_VALUE`: `\u0000`

* `MAX_VALUE`: `\uffff`

### Methods

* `Character` has a large number of `boolean` methods for testing `char` values.

  ```java
  char c = '\u03a6'; // uppercase Greek phi
  if ( Character.isUpperCase(c) ) {
    System.out.println("Uppercase letter: " + c);
  }
  ```

### Caching

`Character`, like the integer-type wrapper classes, maintains an internal cache of important `char` wrapper objects.

* The cached values are the original ASCII characters, from `0` to `127` (_nul_ to _del_, `\u0000` to `\u007f`).

<hr>

[Prev](integerTypes.md) -- [Up](README.md) -- [Next](Boolean.md)

