---
layout: default
title: Regular Expressions in Java
---

## Regular Expressions in Java

Regular Expressions were added to Java in version 1.4.

In code, a Java regex is a `String`.

```java
String myRegex = "^[gG]irr?affe";
```

Strings have a number of backslash escape sequences such as `\t` (tab) and `\b` (backspace).

* The backslash of a regex escape sequence must be escaped; for example `"\b"` is a backspace, but `"\\b"` is a regex word boundary.

* The upshot is, if you're testing your regex syntax outside Java (say, using an online regex tester/debugger), you'll need to double the backslashes when you copy it into your Java code.

  ```java
  String wordPattern = "\\b\\w+(?:'(?:[ts]|ll|[rv]e))?\\b";
  ```


<hr>

[Prev](README.md) -- [Up](README.md) -- [Next](pattern.md)

